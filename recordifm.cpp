#include "recordifm.h"
#include "ui_recordifm.h"

RecordIFM::RecordIFM(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordIFM)
    ,client(new MyClient(this))
{
    ui->setupUi(this);
    client->connectToServer("127.0.0.1",9988);
    connect(ui->Save,&QPushButton::clicked,this,[=](){
        Student stu;
        stu.id=ui->idEdit->text();
        stu.name=ui->nameEdit->text();
        stu.sex=ui->sexEdit->text();
        stu.age=ui->ageSpin->value();
        stu.major=ui->majorEdit->text();
        stu.Class=ui->classEdit->text();
        stu.phone=ui->phoneEdit->text();
        stu.Address=ui->addressEdit->text();
        students.append(stu);
    });
    connect(ui->Send,&QPushButton::clicked,this,&RecordIFM::SendIFM);
}

RecordIFM::~RecordIFM()
{
    delete ui;
}

void RecordIFM::on_Return_clicked()
{
    this->close();
}

void RecordIFM::SendIFM()
{
    if(students.isEmpty())
    {
        qDebug()<<"发送错误";
        return;
    }
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    out << students.size();
    for(const auto& stu : students){
        out << stu;
    }
    qDebug() << "教师端发送数据大小：" << data.size();
    client->sendData(data);
}

