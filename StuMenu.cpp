#include "StuMenu.h"
#include "ui_StuMenu.h"

    StuMenu::StuMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StuMenu)
{
    ui->setupUi(this);
}

StuMenu::~StuMenu()
{
    delete ui;
}

void StuMenu::on_Return_clicked()
{
    this->hide();
}

