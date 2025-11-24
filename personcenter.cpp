#include "personcenter.h"
#include "ui_personcenter.h"

PersonCenter::PersonCenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonCenter)
    ,client(new MyClient(this))
{
    ui->setupUi(this);
    ui->stuTable->setColumnCount(8);
    ui->stuTable->setHorizontalHeaderLabels({"学号：","姓名：","性别：","年龄：","专业：","班级：","联系方式：","家庭住址："});
    client->connectToServer("127.0.0.1",9988);
    connect(client->getSocket(),&QTcpSocket::readyRead,this,&PersonCenter::onReadyRead);
}

PersonCenter::~PersonCenter()
{
    delete ui;
}

void PersonCenter::on_Return_clicked()
{
    this->close();
}
void PersonCenter::onReadyRead()
{
    QTcpSocket *socket=client->getSocket();
    QByteArray data=socket->readAll();        //读取数据
    QDataStream in(&data,QIODevice::ReadOnly);
    int size;
    in>>size;
    QVector<Student> students;
    for(int i=0;i<size;i++)
    {
        Student stu;
        in>>stu;
        students.append(stu);
    }
    ui->stuTable->setRowCount(students.size());
    for(int i=0;i<students.size();i++)
    {
        const auto& stu=students[i];
        ui->stuTable->setItem(i,0,new QTableWidgetItem(stu.id));//设置指定的单元个内容，参数分别为行索引，列索引，内容
        ui->stuTable->setItem(i,1,new QTableWidgetItem(stu.name));
        ui->stuTable->setItem(i,2,new QTableWidgetItem(stu.sex));
        ui->stuTable->setItem(i,3,new QTableWidgetItem(QString::number(stu.age)));
        ui->stuTable->setItem(i,4,new QTableWidgetItem(stu.major));
        ui->stuTable->setItem(i,5,new QTableWidgetItem(stu.Class));
        ui->stuTable->setItem(i,6,new QTableWidgetItem(stu.phone));
        ui->stuTable->setItem(i,7,new QTableWidgetItem(stu.Address));
    }
}
