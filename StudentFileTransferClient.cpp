#include "StudentFileTransferClient.h"

FramelessWidget::FramelessWidget(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    boundaryWidth = 4;                                    //设置触发resize的宽度
    this->setWindowFlags(Qt::FramelessWindowHint);      //设置为无边框窗口
    this->setMinimumSize(45, 45);                        //设置最小尺寸

    c_tcp = new QtTcpClientHandler(this);

    connect(c_tcp, SIGNAL(Connected(const QString, const quint16)), this, SLOT(Connected(const QString, const quint16)));
    connect(c_tcp, SIGNAL(RecvTCP(const QByteArray&)), this, SLOT(RecvTCP(const QByteArray&)));
    //connect(c_tcp, SIGNAL(), this, SLOT());
    QSettings settings("File_Receive_Path.ini", QSettings::IniFormat);
    this->ui.line_path->setText(settings.value("File_Path").toString());
    this->file_path = settings.value("File_Path").toString();
    //设置程序自动启动
	this->SetProcessAutoRun(QApplication::applicationFilePath(), 1);

	this->ui.btn_connect->click();
}
FramelessWidget::~FramelessWidget()
{

}
void FramelessWidget::FileReceiver(QByteArray strValue)
{

    QString file_title;
    QString SeatID;
    QString file_path;
    QDir folder;
    qint32 parse_index;
    QByteArray title_bytes; //名称信息
    QByteArray file_bytes; //文件二进制流

    parse_index = strValue.indexOf("|",1);
	
    title_bytes = strValue.left(parse_index);
    file_title = QString::fromLocal8Bit(title_bytes);
    
    file_path = this->file_path +"/"+ file_title;

	//不管怎么样，只要没占用就得重新写入
    QFile received_file(file_path);   
        file_bytes = strValue.mid(parse_index + 1, -1);
        file_bytes = file_bytes + "\0";

        received_file.open(QIODevice::Truncate | QIODevice::WriteOnly);

        if (received_file.isOpen()) {
            received_file.write(file_bytes, file_bytes.length());
        }
        else {
            folder.mkpath(this->file_path);
            received_file.open(QIODevice::Truncate | QIODevice::WriteOnly);
            received_file.write(file_bytes, file_bytes.length());
        } 
	//接收文件结束之后需要通知服务端当前文件已接收，同时需要改变置顶的文字提示
	ui.lab_title->setText(QString("文件%1已接受！").arg(file_path));
	c_tcp->SendMsg("FILERECIVED");
}
void FramelessWidget::SetProcessAutoRun(const QString & appPath, bool flag)
{
	QSettings settings(AUTO_RUN, QSettings::NativeFormat);

	//以程序名称作为注册表中的键,根据键获取对应的值（程序路径）
	QFileInfo fInfo(appPath);
	QString name = fInfo.baseName();    //键-名称

										//如果注册表中的路径和当前程序路径不一样，则表示没有设置自启动或本自启动程序已经更换了路径
	QString oldPath = settings.value(name).toString(); //获取目前的值-绝对路劲
	QString newPath = QDir::toNativeSeparators(appPath);    //toNativeSeparators函数将"/"替换为"\"
	if (flag)
	{
		if (oldPath != newPath)
			settings.setValue(name, newPath);
	}
	else
		settings.remove(name);
}
bool FramelessWidget::isAutoRun(const QString & appPath)
{
	QSettings settings(AUTO_RUN, QSettings::NativeFormat);
	QFileInfo fInfo(appPath);
	QString name = fInfo.baseName();
	QString oldPath = settings.value(name).toString();
	QString newPath = QDir::toNativeSeparators(appPath);
	return (settings.contains(name) && newPath == oldPath);

}
void FramelessWidget::RecvTCP(const QByteArray& bytes)
{
    //接到发送消息，进行解析
    if (bytes.contains(file_title)) {
		this->ui.lab_title->setText("正在接收文件...");
        //如果当前发送的字符串是发送的文件，则此时开始保存文件
		//接到这段消息之后将字符串向右移动，将抬头移除
		QByteArray temp_qba = bytes;
		//将左侧的NewFile|移除，再输入
		temp_qba = temp_qba.remove(0, 8);
        this->FileReceiver(temp_qba);
    }

    if (bytes.contains("You_Get_Regedited")) {
        this->ui.btn_connect->setEnabled(false);
        this->ui.lab_title->setText("连接到服务器成功！");
    }

	if (bytes.contains("QUITCONNECT")) {
		QApplication::exit();
	}
}
void FramelessWidget::Connected(const QString& qsServerAddr, const quint16 nServerPort)
{
    //链接到服务器
    this->ui.lab_title->setText("链接服务器成功:" + qsServerAddr);
    this->ui.btn_connect->setEnabled(false);
}
void FramelessWidget::on_btn_path_clicked()
{
    QString srcDirPath;
    srcDirPath = QFileDialog::getExistingDirectory(this, "choose src Directory","/");
    QSettings settings("File_Receive_Path.ini", QSettings::IniFormat);
    settings.setValue("File_Path", srcDirPath);
	if (!this->ui.line_ip->text().isEmpty()) settings.setValue("Ip", this->ui.line_ip->text());
	if (!this->ui.line_seat->text().isEmpty()) settings.setValue("Seat", this->ui.line_seat->text());
	
    this->ui.line_path->setText(srcDirPath);
    this->file_path = srcDirPath;

}

void FramelessWidget::on_btn_test_clicked()
{
    QString tempMessage = "file_name.exe|12345678981`212415";
    this->FileReceiver(tempMessage.toLocal8Bit());
}

void FramelessWidget::Disconnect(const QString & qsServerAddr, const quint16 nServerPort)
{
	//如果掉线了，则放开连接限制
	this->ui.btn_connect->setEnabled(true);
	this->ui.lab_title->setText("已掉线...等待用户重新连接至服务器");
}

void FramelessWidget::on_btn_close_clicked()
{
    QApplication::exit();
}

void FramelessWidget::on_btn_connect_clicked() {
    if (ui.label->text().isEmpty() || ui.line_seat->text().isEmpty()) {
        QMessageBox::information(NULL, "请输入文字", "请输入正确的服务端ip和本机座位", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else {
        //尝试链接
		QString temp = ui.line_ip->text();
        c_tcp->Open(ui.line_ip->text(),7777);

        //链接成功后向教师端发送座位号
        QString strMessage = QString("%1|%2").arg("NEWCONNECTION").arg(ui.line_seat->text());

        c_tcp->SendMsg(strMessage.toLocal8Bit());

    }
}
#pragma region 无边框


bool FramelessWidget::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
    MSG* msg = (MSG*)message;
    switch (msg->message)
    {
    case WM_NCHITTEST:
        int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
        int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
        if (xPos < boundaryWidth && yPos < boundaryWidth)                    //左上角
            *result = HTTOPLEFT;
        else if (xPos >= width() - boundaryWidth && yPos < boundaryWidth)          //右上角
            *result = HTTOPRIGHT;
        else if (xPos < boundaryWidth && yPos >= height() - boundaryWidth)         //左下角
            *result = HTBOTTOMLEFT;
        else if (xPos >= width() - boundaryWidth && yPos >= height() - boundaryWidth)//右下角
            *result = HTBOTTOMRIGHT;
        else if (xPos < boundaryWidth)                                     //左边
            *result = HTLEFT;
        else if (xPos >= width() - boundaryWidth)                              //右边
            *result = HTRIGHT;
        else if (yPos < boundaryWidth)                                       //上边
            *result = HTTOP;
        else if (yPos >= height() - boundaryWidth)                             //下边
            *result = HTBOTTOM;
        else              //其他部分不做处理，返回false，留给其他事件处理器处理
            return false;
        return true;
    }
    return false;         //此处返回false，留给其他事件处理器处理
}


void FramelessWidget::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton)
        clickPos = e->pos();
}
void FramelessWidget::mouseMoveEvent(QMouseEvent* e)
{
    if (e->buttons() & Qt::LeftButton)
        move(e->pos() + pos() - clickPos);
}
#
#pragma endregion

