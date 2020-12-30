#include "viewnumberofgoods.h"
#include "ui_viewnumberofgoods.h"

ViewNumberOfGoods::ViewNumberOfGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewNumberOfGoods)
{
    ui->setupUi(this);
}

ViewNumberOfGoods::~ViewNumberOfGoods()
{
    delete ui;
}
