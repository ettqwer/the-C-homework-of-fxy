#include "usersudo.h"
#include "ui_usersudo.h"
UserSudo::UserSudo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserSudo)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);//锁定主窗口，无法在下层窗口做任何操作
    setWindowFlags(windowFlags()& ~Qt::WindowMinMaxButtonsHint);//禁用最大化最小化按钮
    //setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//禁用最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowCloseButtonHint);//禁用关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小防止拖动
    this->setAttribute(Qt::WA_DeleteOnClose,1);
    this->SetSudoControlCbs();
}

UserSudo::~UserSudo()
{
    delete ui;
}

void UserSudo::on_pb_back_clicked()
{
    this->close();
}
void UserSudo::SetSudoControlCbs()
{
    QList<QCheckBox *> cbs = this->findChildren<QCheckBox *>();
    for(int i = 0;i<=15;i++)
    {
    QString a = cbs.at(i)->objectName();
    a = a.mid(3,-1);
    int b = a.toInt();
    if(Sudo[b - 1] == "1")
    {
        cbs.at(i)->setChecked(true);
    }
        else
    {
        cbs.at(i)->setChecked(false);
    }

    }
}
void UserSudo::on_pb_Save_clicked()
{
    QList<QCheckBox *> cbs = this->findChildren<QCheckBox *>();
    for(int i = 0;i<=15;i++)
    {
    QString a = cbs.at(i)->objectName();
    a = a.mid(3,-1);
    int b = a.toInt();
    //qDebug()<<b<<" ";
    //测试通过 12.26
    Sudo[b - 1] = cbs.at(i)->isChecked()?"1":"0";
    }
    QFile file("Sudo.ilfxy");
    if(! file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,"严重错误","文件打开失败，信息未写入，请与开发者联系","确认");
        return;
    }
    QTextStream out(&file);
    for(int i = 0;i<=15;i++)
    {
        if(i)
            out<<"\n";
        out<<Sudo[i];
    }
    file.close();
    int ret = QMessageBox::information(this,"提示","\n您已成功修改普通用户的相关权限\n请问您接下来想做什么\n","退出","继续更改");
    if(!ret)
    {
        this->close();
        return;
    }
    else
    {
        return;
    }
}
