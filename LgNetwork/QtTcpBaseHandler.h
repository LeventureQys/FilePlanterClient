/*!
 * \file QtTcpBaseHandler.h
 *
 * \author daiweiheng
 * \date 四月 2021
 *
 * 用于支持QT下的TCP公共处理，使用此类前需要在项目属性中添加network模块支持
 */
#pragma once
#include <functional>

#include <QtNetwork/QTcpSocket>

void SendTcp(QTcpSocket * pTcpSocket, const QByteArray &bytes);

using fun_Notice = std::function<void(const QByteArray&)>;
void ReadTCPMsg(QTcpSocket * pTcpSocket, qint64 &nCountRecvedMsg, fun_Notice funNotice);