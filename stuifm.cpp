#include "stuifm.h"

StuIFM::StuIFM() {}
QDataStream& operator<<(QDataStream& out,const Student& stu){
    out<<stu.id<<stu.name<<stu.sex<<stu.age<<stu.major<<stu.Class<<stu.phone<<stu.Address;
    return out;
}

QDataStream& operator>>(QDataStream& in,Student& stu){
    in>>stu.id>>stu.name>>stu.sex>>stu.age>>stu.major>>stu.Class>>stu.phone>>stu.Address;
    return in;
}
