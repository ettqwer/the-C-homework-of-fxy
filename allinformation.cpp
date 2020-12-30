#include "allinformation.h"
#include "ui_allinformation.h"

AllInformation::AllInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllInformation)
{
    ui->setupUi(this);
}

AllInformation::~AllInformation()
{
    delete ui;
}
