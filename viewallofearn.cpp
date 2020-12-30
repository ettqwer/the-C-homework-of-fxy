#include "viewallofearn.h"
#include "ui_viewallofearn.h"

ViewAllOfEarn::ViewAllOfEarn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewAllOfEarn)
{
    ui->setupUi(this);
}

ViewAllOfEarn::~ViewAllOfEarn()
{
    delete ui;
}
