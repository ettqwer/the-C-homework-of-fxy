#include "pooruserview.h"
#include "ui_pooruserview.h"

PoorUserView::PoorUserView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PoorUserView)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);//锁定主窗口，无法在下层窗口做任何操作
    setWindowFlags(windowFlags()& ~Qt::WindowMinMaxButtonsHint);//禁用最大化最小化按钮
    //setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//禁用最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowCloseButtonHint);//禁用关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小防止拖动
}

PoorUserView::~PoorUserView()
{
    delete ui;
}

void PoorUserView::on_pb_close_clicked()
{
    //弹出关闭程序确认信息框
    int ret = QMessageBox::information(this,"二次确认","\n您是否确认退出本系统\n","确认","取消");
    if(ret == 1)//用户选择了取消
    {
        return;//不做任何操作，返回
    }
    else //用户选择了确定
    {
        exit(0);//退出程序，返回值为0
    }
}

void PoorUserView::on_pb_logout_clicked()
{
    //弹出退出账号确认信息框
    int ret = QMessageBox::information(this,"二次确认","\n您是否确认退出此账号\n","确认","取消");
    if(ret == 1) //用户选择了取消
    {
        return; //啥也不做，返回
    }
    else//用户选择了确定
    {
        emit PoorSendsignal(); //向主页面发送一个“我要关闭啦，你要显示自己啦”的信号
        this->close(); //关闭此页面
    }
}
