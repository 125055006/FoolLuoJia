#include "StuLoad.h"
#include "ui_StuLoad.h"

    StuLoad::StuLoad(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StuLoad)
{
    ui->setupUi(this);
}

StuLoad::~StuLoad()
{
    delete ui;
}
void StuLoad::on_Cancel_clicked()
{
    this->close();
}


void StuLoad::on_Load_clicked()
{
    stu_menu->show();
}

