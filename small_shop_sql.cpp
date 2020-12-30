// 2020.12.29 16:26 测试通过 版本上传成功
#include "small_shop_sql.h"
#include "ui_small_shop_sql.h"
#include <rootview.h>
#include<pooruserview.h>
#include<add_user.h>
Small_Shop_SQL::Small_Shop_SQL(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Small_Shop_SQL)
{
    ui->setupUi(this);
    this->ReadUserFileToVector();
    this->setWindowModality(Qt::ApplicationModal);//锁定主窗口，无法在下层窗口做任何操作
    //setWindowFlags(windowFlags()& ~Qt::WindowMinMaxButtonsHint);//禁用最大化最小化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//禁用最大化按钮
    //setWindowFlags(windowFlags()& ~Qt::WindowCloseButtonHint);//禁用关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小防止拖动
}

Small_Shop_SQL::~Small_Shop_SQL()
{
    delete ui;
}

void Small_Shop_SQL::ReadUserFileToVector()
{
    //打开文件
    QFile file("User.ilfxy");
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
            User.push_back(line);
        }
        i++;
        }
    for(i = 0;i <= ((int)User.size())-1;i++)
    {
    //将不定数组内的字符串按“|”切割
    QStringList section= User[i].split(QRegExp("[|]"));
    //存储进对应的不定数组
    User_Number.push_back(section.at(0));
    User_Name.push_back(section.at(1));
    User_password.push_back(section.at(2));
    User_Phone.push_back(section.at(3));
    User_Sudo.push_back(section.at(4));
    }
    //调试，用于查看切割的结果是否正确
    //qDebug()<<User_Name[0]<<" "<<User_Number[0]<<" "<<User_password[0]<<" "<<User_Phone[0]<<" "<<User_Sudo[0]<<endl;
    //测试通过 12.26
    file.close();
}

void Small_Shop_SQL::on_pushButton_clicked()
{
    //从页面上的两个输入框来获取用户输入的账号密码
    QString Name = ui->le_UserName->text();
    QString Pass = ui->le_Password->text();
    //调试，用于查看获取的字符串是否正确
    //qDebug()<<Name<<' '<<Pass<<endl;
    //测试通过 12.26
    if(Name != "" && Pass != "")
    {
    //存储密码正不正确
    bool PasswordCu = false;
    for(int i = 0;i <= ((int)User_Name.size())-1;i++)
    {
        //用户名密码都正确
        if(User_Name[i] == Name && User_password[i] == Pass)
        {
            //存储当前用户的工号
            User_Number_Now = User_Number[i];
            //存储当前用户在不定数组的位置
            User_Sort_Now = i;
            //密码正确
            PasswordCu = true;
            //退出循环
            break;
        }
    }
        //如果密码正确
        if(PasswordCu)
        {
            //权限是“管理员”(root)
            if(User_Sudo[User_Sort_Now] == "1")
            {
                    this->hide();//主界面关闭
                    RootView *root = new RootView(this);//新建子界面
                    root->show();//子界面出现
                    connect(root,SIGNAL(sendsignal()),this,SLOT(show()));//当收到子页面的信号时，调用主界面的show()函数
                    ui->le_NoPass->setText("");//清空密码错误的提示
                    ui->le_Password->setText("");//清空密码输入框内的输入内容
                    ui->le_UserName->setText("");//清空用户名输入框内的输入内容
            }
            //权限是“穷逼用户”(Poor User)
            if(User_Sudo[User_Sort_Now] == "0")
            {
                    this->hide();//主界面关闭
                    PoorUserView *poorUser = new PoorUserView(this);//新建子界面
                    poorUser->show();//子界面出现
                    connect(poorUser,SIGNAL(PoorSendsignal()),this,SLOT(show()));//当收到子页面的信号时，调用主界面的show()函数
                    ui->le_NoPass->setText("");//清空密码错误的提示
                    ui->le_Password->setText("");//清空密码输入框内的输入内容
                    ui->le_UserName->setText("");//清空用户名输入框内的输入内容
            }
        }
        else
        {
            //密码错误提示
            ui->le_Password->setText("");//清空密码输入框内的输入内容
            ui->le_NoPass->setText("密码或账号错误，请检查后再试");
        }
    }
    else
    {
    //密码为空提示
    ui->le_NoPass->setText("密码或账号不能为空");
    }
}

void Small_Shop_SQL::on_pb_adduser_clicked()
{
    Add_User *NewUser = new Add_User(this);
    NewUser->show();
}
