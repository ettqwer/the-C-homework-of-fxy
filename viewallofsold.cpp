#include "viewallofsold.h"
#include "ui_viewallofsold.h"

ViewAllOfSold::ViewAllOfSold(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewAllOfSold)
{
    ui->setupUi(this);
}

ViewAllOfSold::~ViewAllOfSold()
{
    delete ui;
}
