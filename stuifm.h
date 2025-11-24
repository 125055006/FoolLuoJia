#ifndef STUIFM_H
#define STUIFM_H

#include<QString>
#include<QDataStream>
struct Student{
    QString id;
    QString name;
    QString sex;
    int age;
    QString major;
    QString Class;
    QString phone;
    QString Address;
};
QDataStream& operator<<(QDataStream& out,const Student& stu);  //写入数据流
QDataStream& operator>>(QDataStream& in,Student& stu);         //读取数据流
class StuIFM
{
public:
    StuIFM();
};

#endif // STUIFM_H
