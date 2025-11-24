#include "StuMenu.h"
#include "ui_StuMenu.h"

    StuMenu::StuMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StuMenu)
{
    ui->setupUi(this);
    con_score=new ConsultScore;
    go_center=new PersonCenter;
}

StuMenu::~StuMenu()
{
    delete ui;
}

void StuMenu::on_Return_clicked()
{
    this->hide();
}


void StuMenu::on_con_score_clicked()
{
    con_score->show();
}

void StuMenu::on_Pcenter_clicked()
{
    go_center->show();
}

