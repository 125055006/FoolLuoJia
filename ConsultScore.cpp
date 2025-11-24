#include "ConsultScore.h"
#include "ui_ConsultScore.h"

ConsultScore::ConsultScore(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ConsultScore)
{
    ui->setupUi(this);
}

ConsultScore::~ConsultScore()
{
    delete ui;
}

void ConsultScore::on_Return_clicked()
{
    this->close();
}

