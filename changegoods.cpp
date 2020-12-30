#include "changegoods.h"
#include "ui_changegoods.h"

ChangeGoods::ChangeGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeGoods)
{
    ui->setupUi(this);
}

ChangeGoods::~ChangeGoods()
{
    delete ui;
}
