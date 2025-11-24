#include "TeaMenu.h"
#include "ui_TeaMenu.h"

TeaMenu::TeaMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeaMenu)
{
    ui->setupUi(this);
    re_ifm=new RecordIFM;
}

TeaMenu::~TeaMenu()
{
    delete ui;
}

void TeaMenu::on_Return_clicked()
{
    this->close();
}


void TeaMenu::on_RecordIFM_clicked()
{
    re_ifm->show();
}

