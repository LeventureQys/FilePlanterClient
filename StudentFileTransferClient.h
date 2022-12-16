#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>      
#include <windows.h>        //注意头文件
#include <windowsx.h>
#include <QMouseEvent>
#include "ui_StudentFileTransferClient.h"
#include "LgNetwork/QtTcpClientHandler.h"
#include "qdir.h"
#include "qmessagebox.h"
#include "qfiledialog.h"
#include "qsettings.h"
class FramelessWidget : public QMainWindow
{
    Q_OBJECT

public:
    FramelessWidget(QWidget* parent = 0);
    ~FramelessWidget();

private:
    Ui::StudentFileTransferClientClass ui;
    QtTcpClientHandler* c_tcp;
    const QByteArray file_title = QByteArray("NewFile");
    QString file_path;
    void FileReceiver(QByteArray strValue);
	/*******************************
	* 时间：2021年12月1日
	* 功能：设置/取消 进程开机自动启动函数
	* 参数：
	1、appPath：需要设置/取消的自启动软件的“绝对路径”
	2、flag：   设置/取消自启动标志位，1为设置，0为取消,默认为设置
	*******************************/
	//注册表路径需要使用双反斜杠
#define AUTO_RUN "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"

	void SetProcessAutoRun(const QString &appPath, bool flag);
	bool isAutoRun(const QString &appPath);
private slots:
    //点击尝试链接
    void on_btn_connect_clicked();
    void RecvTCP(const QByteArray& bytes);
    //连接到服务器
    void Connected(const QString& qsServerAddr, const quint16 nServerPort);

    void on_btn_path_clicked();

    void on_btn_test_clicked();
	void Disconnect(const QString &qsServerAddr, const quint16 nServerPort);
    void on_btn_close_clicked();
protected:
    bool nativeEvent(const QByteArray& eventType, void* message, long* result);
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
private:
    int boundaryWidth;
    QPoint clickPos;
};

#endif // FRAMELESSWIDGET_H