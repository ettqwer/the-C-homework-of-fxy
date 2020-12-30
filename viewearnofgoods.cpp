#include "viewearnofgoods.h"
#include "ui_viewearnofgoods.h"

ViewEarnOfGoods::ViewEarnOfGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewEarnOfGoods)
{
    ui->setupUi(this);
}

ViewEarnOfGoods::~ViewEarnOfGoods()
{
    delete ui;
}
