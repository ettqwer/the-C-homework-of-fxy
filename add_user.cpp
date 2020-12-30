#include "add_user.h"
#include "ui_add_user.h"

Add_User::Add_User(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add_User)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);//锁定主窗口，无法在下层窗口做任何操作
    setWindowFlags(windowFlags()& ~Qt::WindowMinMaxButtonsHint);//禁用最大化最小化按钮
    //setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//禁用最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowCloseButtonHint);//禁用关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小防止拖动
}

Add_User::~Add_User()
{
    delete ui;
}

void Add_User::on_pb_back_clicked()
{
    this->close();
}

void Add_User::on_pb_GoAdd_clicked()
{
    QString Name,Pass,Num,Phone;
    Name = ui->le_UserName->text();
    Pass = ui->le_Password->text();
    Num = ui->le_Number->text();
    Phone = ui->Le_Phone->text();
    if(Name == ""||Pass == ""||Num =="")
    {
        ui->le_wa->setText("必填项未填写");
        return;
    }
    else
    {
        if(Name.size() < 3)
        {
            ui->le_wa->setText("用户名格式错误，字符小于三位");
            return;
        }
        if(!isDigitString(Name))
        {
            ui->le_wa->setText("用户名格式错误，不能为纯数字");
            return;
        }
        if(Pass.size() < 6)
        {
            ui->le_wa->setText("密码格式错误，字符小于六位");
            return;
        }
        if(!isDigitString(Num))
        {
            ui->le_wa->setText("工号格式错误，非纯数字");
            return;
        }
        if(Phone != "")
        {
        if(!isDigitString(Phone)&&Phone.size() != 11)
        {
            ui->le_wa->setText("手机号格式错误，非纯数字或非11位数字");
            return;
        }
        }
        if(std::find(User_Name.begin(), User_Name.end(), Name) != User_Name.end())
        {
            ui->le_wa->setText("用户名与已有用户重复");
            return;
        }
        if(std::find(User_Number.begin(), User_Number.end(), Num) != User_Number.end())
        {
            ui->le_wa->setText("工号与已有用户重复");
            return;
        }
        if(Phone == "")
            Phone = "None";
        QString tips = "用户名:  "+Name+"\n"+"密码:   "+Pass+"\n"+"工号:   "+Num+"\n"+"联系方式: "+(Phone=="None"?"无":Phone)+"\n";
        int ret = QMessageBox::information(this,"请仔细确认","您是否确认注册为此账号，此操作不可更改\n\n"+tips,"确认","取消");
        if(!ret)
        {
            User_Name.push_back(Name);
            User_Sudo.push_back("0");
            User_Phone.push_back(Phone);
            User_password.push_back(Pass);
            User_Number.push_back(Num);
            User.push_back(Num+"|"+Name+"|"+Pass+"|"+Phone+"|"+"0"+"|");
            QFile file("User.ilfxy");
            if(! file.open(QIODevice::WriteOnly|QIODevice::Text))
            {
                QMessageBox::critical(this,"严重错误","文件打开失败，信息未写入，请与开发者联系","确认");
                return;
            }
            QTextStream out(&file);
            for(int i = 0;i < (int)User.size();i++)
            {
                if(i)
                    out<<"\n";
                out<<User[i];
            }
            file.close();
            ui->le_wa->setText("");
            ui->le_Number->setText("");
            ui->le_Password->setText("");
            ui->le_UserName->setText("");
            ui->Le_Phone->setText("");
            if(0 == QMessageBox::information(this,"成功","您已注册 "+Name+" 账号，此操作不可撤销\n","确认"))
                this->close();
        }
    }
}

bool Add_User::isDigitString(const QString& src)
{
    const char *s = src.toUtf8().data();
    while(*s && *s>='0' && *s<='9')s++;
    return !bool(*s);
}
