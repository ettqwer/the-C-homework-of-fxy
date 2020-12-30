#include "outgoods.h"
#include "ui_outgoods.h"

OutGoods::OutGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OutGoods)
{
    ui->setupUi(this);
}

OutGoods::~OutGoods()
{
    delete ui;
}
