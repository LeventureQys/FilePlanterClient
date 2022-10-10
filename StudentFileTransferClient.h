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
#include "qprocess.h"
#include "qthread.h"
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

	void KillProcess(QString ProcessName);
	bool IsProcessExist(QString ProcessName);

	const QString local_file = QCoreApplication::applicationDirPath() + "/FileTransfer_Temp/";

	void closeEvent(QCloseEvent* event);
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