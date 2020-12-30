#include "sudonumberchange.h"
#include "ui_sudonumberchange.h"

SudoNumberChange::SudoNumberChange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudoNumberChange)
{
    ui->setupUi(this);
}

SudoNumberChange::~SudoNumberChange()
{
    delete ui;
}
