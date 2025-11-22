#include "TeaMenu.h"
#include "ui_TeaMenu.h"

TeaMenu::TeaMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeaMenu)
{
    ui->setupUi(this);
}

TeaMenu::~TeaMenu()
{
    delete ui;
}
