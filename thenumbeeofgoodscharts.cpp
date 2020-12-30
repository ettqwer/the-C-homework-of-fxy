#include "thenumbeeofgoodscharts.h"
#include "ui_thenumbeeofgoodscharts.h"

TheNumbeeOfGoodsCharts::TheNumbeeOfGoodsCharts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TheNumbeeOfGoodsCharts)
{
    ui->setupUi(this);
}

TheNumbeeOfGoodsCharts::~TheNumbeeOfGoodsCharts()
{
    delete ui;
}
