#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->StuLoad,&QPushButton::clicked,this,&Widget::on_StuLoad_clicked);
    connect(ui->TeaLoad,&QPushButton::clicked,this,&Widget::on_TeaLoad_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_StuLoad_clicked()
{
    stu_load->show();
}


void Widget::on_TeaLoad_clicked()
{
    tea_load->show();
}

