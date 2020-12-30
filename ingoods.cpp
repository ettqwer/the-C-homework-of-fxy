#include "ingoods.h"
#include "ui_ingoods.h"

InGoods::InGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InGoods)
{
    ui->setupUi(this);
}

InGoods::~InGoods()
{
    delete ui;
}
