#include "addgoods.h"
#include "ui_addgoods.h"

AddGoods::AddGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddGoods)
{
    ui->setupUi(this);
}

AddGoods::~AddGoods()
{
    delete ui;
}
