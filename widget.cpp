#include "widget.h"
#include "ui_widget.h"
#include"MyServer.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyServer *server=new MyServer(this);
    if(server->startServer(9988))
    {
        qDebug()<<"成功启动";
    }
    else{
        qDebug()<<"启动失败";
    }

}

Widget::~Widget()
{
    delete ui;
}
