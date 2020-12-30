#include "deletegoods.h"
#include "ui_deletegoods.h"

DeleteGoods::DeleteGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteGoods)
{
    ui->setupUi(this);
}

DeleteGoods::~DeleteGoods()
{
    delete ui;
}
