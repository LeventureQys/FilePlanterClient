#include "QtTcpBaseHandler.h"
#include <memory>
#include <QtCore/QHash>
#include <QtCore/QMutex>

#pragma pack(1)

struct MsgHeader
{
	/*
	头部12字节
	[0] = 4;
	[1] = 'H';
	[2] = 'E';
	[3] = 'A';
	[4] = 'D';
	[5] = 0;
	[6] = 0;
	[7] = 0;
	[8] = 0;
	[9] = 0;
	[10] = 0;
	[11] = 0;
	*/
	char gcBaseHeader[12] = { 0 };

	/*
	4字节，长度信息：内容长度+1
	*/
	int nMsgBodyLen = 0;

	/*
	预留字节
	*/
	char gcReserved[12] = { 0 };
};

void SendTcp(QTcpSocket * pTcpSocket, const QByteArray &bytes)
{
	/* 消息结构：头 + 内容 + 结尾符0 */
	MsgHeader header;
	header.nMsgBodyLen = bytes.length() + 1;

	QByteArray bytesHeaderInfo((char*)&header, sizeof(MsgHeader));
	pTcpSocket->write(bytesHeaderInfo);

	char *pData = new char[header.nMsgBodyLen];
	memset(pData, 0, header.nMsgBodyLen);
	memcpy_s(pData, header.nMsgBodyLen, bytes.data(), bytes.length());
	for (int i = 0; i < header.nMsgBodyLen; i += 1024)
	{
		pTcpSocket->write(pData + i, qMin(1024, header.nMsgBodyLen - i));
	}

	delete[] pData;
}

// 存储结构
typedef struct tagTCPRecvData
{
	int nExpectSize = 0;	// 期望大小
	int nRecvedLen = 0;		// 已收大小
	QByteArray bytes;

	void Clear()
	{
		nExpectSize = 0;
		nRecvedLen = 0;
		bytes.clear();
	}
}TCPRecvData;
using SPTCPRecvData = std::shared_ptr<TCPRecvData>;
QHash<QTcpSocket*, SPTCPRecvData> g_qhsSock2RecvData;
// 互斥锁
QMutex g_mtForQhsSock2RecvData;
void ReadTCPMsg(QTcpSocket * pTcpSocket, qint64 &nCountRecvedMsg, fun_Notice funNotice)
{
	QMutexLocker am(&g_mtForQhsSock2RecvData);

	if (!g_qhsSock2RecvData.contains(pTcpSocket))
	{
		SPTCPRecvData spTcpRecvData = std::make_shared<TCPRecvData>();
		g_qhsSock2RecvData.insert(pTcpSocket, spTcpRecvData);
	}
	SPTCPRecvData spTcpRecvData = g_qhsSock2RecvData[pTcpSocket];

	while (pTcpSocket->bytesAvailable() > 0)
	{
		if (0 == spTcpRecvData->nRecvedLen)
		{
			if (pTcpSocket->bytesAvailable() < sizeof(MsgHeader)) return;

			QByteArray bytesHeader = pTcpSocket->read(sizeof(MsgHeader));

			MsgHeader *pHeader = (MsgHeader*)(bytesHeader.data());
			spTcpRecvData->nExpectSize = pHeader->nMsgBodyLen;
		}

		int nBytesAvailable = pTcpSocket->bytesAvailable();
		if (nBytesAvailable > 0)
		{
			int nThisRecv = qMin(nBytesAvailable, spTcpRecvData->nExpectSize - spTcpRecvData->nRecvedLen);
			spTcpRecvData->bytes += pTcpSocket->read(nThisRecv);
			spTcpRecvData->nRecvedLen += nThisRecv;

			// 其实就是等于，加大于号为了保险...
			if (spTcpRecvData->nRecvedLen >= spTcpRecvData->nExpectSize)
			{
				// 通知
				if (nullptr != funNotice) funNotice(spTcpRecvData->bytes);

				// 重置
				spTcpRecvData->Clear();
			}
		}
	}

	nCountRecvedMsg = spTcpRecvData->nRecvedLen;
}

#pragma pack()