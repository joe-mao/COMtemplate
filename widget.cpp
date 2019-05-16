#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mytcp = new MyTcpCom(this);
    labelSocketState = new QLabel(tr("Socket状态:"));



    connect(mytcp, &MyTcpCom::connectOKSignal, this, &Widget::onConnectTcpOK);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::onConnectTcpOK()
{
    connectState = true;
}
