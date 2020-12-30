#include "rootview.h"
#include "ui_rootview.h"
#include"usersudo.h"
#include"add_user.h"
#include"finduser.h"
#include"deleteuser.h"
RootView::RootView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RootView)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);//锁定主窗口，无法在下层窗口做任何操作
    setWindowFlags(windowFlags()& ~Qt::WindowMinMaxButtonsHint);//禁用最大化最小化按钮
    //setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//禁用最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowCloseButtonHint);//禁用关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小防止拖动
    this->setAttribute(Qt::WA_DeleteOnClose,1);
    this->ReadSudoFileTOVector();
}

RootView::~RootView()
{
    delete ui;
}

void RootView::on_pb_close_clicked()
{
    //弹出关闭程序确认信息框
    int ret = QMessageBox::information(this,"二次确认","\n您是否确认退出本系统\n","确认","取消");
    //用户选择了取消
    if(ret == 1)
    {
        //不做任何操作，返回
        return;
    }
    //用户选择了确定
    else
    {
        //退出程序，返回值为0
        exit(0);
    }
}

void RootView::on_pb_logout_clicked()
{
    //弹出退出账号确认信息框
    int ret = QMessageBox::information(this,"二次确认","\n您是否确认退出此账号\n","确认","取消");
    //用户选择了取消
    if(ret == 1)
    {
        //啥也不做，返回
        return;
    }
    //用户选择了确定
    else
    {
        //向主页面发送一个“我要关闭啦，你要显示自己啦”的信号
        emit sendsignal();
        //关闭此页面
        this->close();
    }
}

void RootView::ReadSudoFileTOVector()
{
    QFile file("Sudo.ilfxy");
    if(! file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        //失败报错
        QMessageBox::critical(this,"严重错误","文件打开失败，信息未读入，请与开发者联系","确认");
        this->close();
        return;
    }
    //重定向流输入
    QTextStream in(&file);
    //定义字符串line，用于检测是否到达文件末
    QString line;
    int i = 0;
    //从文件一行行的读入数据，存储进不定数组User中
    while(1)
        {
        line=in.readLine();
        if(line==NULL)
        {
            break;
        }
        else
        {
            Sudo.push_back(line);
        }
        i++;
        }
    //测试通过 12.26
    file.close();
}
void RootView::on_pb_SudoControl_clicked()
{
    UserSudo *controlUsersSudo = new UserSudo(this);
    controlUsersSudo->show();
}

void RootView::on_pb_AddUser_clicked()
{
    Add_User *NewUser = new Add_User(this);
    NewUser->show();
}

void RootView::on_pb_SearchUser_clicked()
{
    FindUser * SerachUsers = new FindUser(this);
    SerachUsers->show();
}

void RootView::on_pb_DeleteUser_clicked()
{
    DeleteUser * UserJuck = new DeleteUser(this);
    UserJuck->show();
}
