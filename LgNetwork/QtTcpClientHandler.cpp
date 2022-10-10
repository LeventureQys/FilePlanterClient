#include "QtTcpClientHandler.h"
#include "QtTcpBaseHandler.h"

QtTcpClientHandler::QtTcpClientHandler(QObject *parent) : QObject(parent)
, m_pTcpSocket(new QTcpSocket(this))
{
	m_pTcpSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 1024 * 1024 * 100);
	connect(m_pTcpSocket, &QTcpSocket::connected, this, &QtTcpClientHandler::ConnectedServer);
	connect(m_pTcpSocket, &QTcpSocket::disconnected, this, &QtTcpClientHandler::DisConnectedServer);
	connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(RecvMsg()));
	connect(&heart_timer, &QTimer::timeout, this, [=]() {
		//五秒触发一次，未检测到则自动断开连接，由外部自行决定尝试重连
		if (this->bln_heartbeat_detectived == false) {
			if (this->bln_connected) {
				emit Disconnect(m_qsServerAddr, m_nServerPort);
				this->Close();
				this->bln_connected = false;
				qDebug() << "_qtnetdll收到心跳包失败:receive heartbeat failed!";
				this->heart_timer.stop();
				//this->Open(m_qsServerAddr, m_nServerPort);
			}
			else {
				//this->Open(m_qsServerAddr, m_nServerPort);
			}
		}
		else if (this->bln_heartbeat_detectived = true) {
			this->bln_heartbeat_detectived = false;
		}
	});
}

QtTcpClientHandler::~QtTcpClientHandler()
{
	Close();

	if (Q_NULLPTR != m_pTcpSocket)
	{
		delete m_pTcpSocket;
		m_pTcpSocket = Q_NULLPTR;
	}
}

void QtTcpClientHandler::Open(const QString &qsServerAddr, const quint16 serverPort)
{
	m_qsServerAddr = qsServerAddr;
	m_nServerPort = serverPort;
	m_pTcpSocket->connectToHost(QHostAddress(m_qsServerAddr), m_nServerPort);
}

void QtTcpClientHandler::Close()
{
	//m_pTcpSocket->disconnectFromHost();
	m_pTcpSocket->close();
	this->heart_timer.stop();
	this->bln_connected = false;
	this->bln_heartbeat_detectived = false;
}

void QtTcpClientHandler::SendMsg(const QByteArray &bytes)
{
	SendTcp(m_pTcpSocket, bytes);

	qInfo() << QString("qtnetdll发送TCP：") + QString::fromLocal8Bit(bytes);
}

void QtTcpClientHandler::ConnectedServer()
{
	qInfo() << QString("qtnetdll连接到服务器(%1, %2)").arg(m_qsServerAddr).arg(m_nServerPort);
	emit Connected(m_qsServerAddr, m_nServerPort);
	this->bln_connected = true;
	this->heart_timer.start(5000);
}

void QtTcpClientHandler::DisConnectedServer()
{
	emit Disconnect(m_qsServerAddr, m_nServerPort);
	this->bln_connected = false;
	this->heart_timer.stop();
}

void QtTcpClientHandler::RecvMsg()
{
	ReadTCPMsg(m_pTcpSocket, m_nRecvedSize, [&](const QByteArray& bytes) {
		qInfo() << QString("qtnetdll收到TCP：") + QString::fromLocal8Bit(bytes);
		emit RecvTCP(bytes);

		if (QString::fromLocal8Bit(bytes) == QString("heartbeat")) {
			this->bln_heartbeat_detectived = true;
			this->heart_timer.start(5000);
		}
	});
}
