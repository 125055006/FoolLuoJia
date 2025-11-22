#include "TeaLoad.h"
#include "ui_TeaLoad.h"

TeaLoad::TeaLoad(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeaLoad)
{
    ui->setupUi(this);
}

TeaLoad::~TeaLoad()
{
    delete ui;
}

void TeaLoad::on_Cancel_clicked()
{
    this->close();
}


void TeaLoad::on_Load_clicked()
{
    tea_menu->show();
}

