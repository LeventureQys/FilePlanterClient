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
	this->ui.line_ip->setText(settings.value("Ip").toString());
	this->ui.line_seat->setText(settings.value("Seat").toString());
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
	QDir temp_dir;
    parse_index = strValue.indexOf("|",1);
	
    title_bytes = strValue.left(parse_index);
    file_title = QString::fromLocal8Bit(title_bytes);
    
    //file_path = this->file_path +"/"+ file_title;
	//先缓存，后转移
	temp_dir.mkdir(this->local_file);
	file_path = this->local_file + file_title;
	
	//要强制结束这个进程来换文件，不然可能就换不了
	
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
	//到此文件应该已经接收完毕了，现在要将本地指定的文件转移到对应位置
		QFile temp_file(file_path);
		this->KillProcess(file_title);

		file_path = this->file_path + "/" + file_title;
		//将指定位置的指定文件移除，再打开
		QFile::remove(file_path);

		temp_file.copy(file_path);

	//接收文件结束之后需要通知服务端当前文件已接收，同时需要改变置顶的文字提示
	ui.lab_title->setText(QString("文件%1已接受！").arg(file_path));
	c_tcp->SendMsg("FILERECIVED");
}
void FramelessWidget::KillProcess(QString ProcessName)
{
	QProcess p;
	p.start(QString("taskkill /im %1 /f").arg(ProcessName));
	p.waitForFinished();

	while (IsProcessExist(ProcessName)) {
		QThread::msleep(20);
	}
}
bool FramelessWidget::IsProcessExist(QString strExe)
{
	bool bResult = false;
	// 判断进程是否存在
	QProcess tasklist;
	tasklist.start("tasklist",
		QStringList() << "/NH"
		<< "/FO" << "CSV"
		<< "/FI" << QString("IMAGENAME eq %1").arg(strExe));
	tasklist.waitForFinished();
	QString strOutput = tasklist.readAllStandardOutput();
	//如果进程存在,则结束进程
	if (strOutput.startsWith(QString("\"%1").arg(strExe)))
	{
		qInfo() << "check process";
		bResult = true;
	}
	return bResult;
}
void FramelessWidget::closeEvent(QCloseEvent * event)
{
	QDir temp_dir(this->local_file);
	temp_dir.removeRecursively();
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

	//链接成功后向教师端发送座位号
	QString strMessage = QString("%1|%2").arg("NEWCONNECTION").arg(ui.line_seat->text());

	c_tcp->SendMsg(strMessage.toLocal8Bit());
	QSettings settings("File_Receive_Path.ini", QSettings::IniFormat);
	if (!this->ui.line_ip->text().isEmpty()) settings.setValue("Ip", this->ui.line_ip->text());
	if (!this->ui.line_seat->text().isEmpty()) settings.setValue("Seat", this->ui.line_seat->text());

}
void FramelessWidget::on_btn_path_clicked()
{
    QString srcDirPath;
    srcDirPath = QFileDialog::getExistingDirectory(this, "choose src Directory","/");
    QSettings settings("File_Receive_Path.ini", QSettings::IniFormat);
    settings.setValue("File_Path", srcDirPath);
	
	
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

