#include "changeuser.h"
#include "ui_changeuser.h"

ChangeUser::ChangeUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeUser)
{
    ui->setupUi(this);
}

ChangeUser::~ChangeUser()
{
    delete ui;
}
