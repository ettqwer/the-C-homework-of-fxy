#include "searchgoods.h"
#include "ui_searchgoods.h"

SearchGoods::SearchGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchGoods)
{
    ui->setupUi(this);
}

SearchGoods::~SearchGoods()
{
    delete ui;
}
