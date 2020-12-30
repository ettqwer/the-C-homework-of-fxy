#include "finduser.h"
#include "ui_finduser.h"

FindUser::FindUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindUser)
{
    ui->setupUi(this);

    this->setWindowModality(Qt::ApplicationModal);//锁定主窗口，无法在下层窗口做任何操作
    setWindowFlags(windowFlags()& ~Qt::WindowMinMaxButtonsHint);//禁用最大化最小化按钮
    //setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);//禁用最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowCloseButtonHint);//禁用关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小防止拖动
    this->setAttribute(Qt::WA_DeleteOnClose,1);

    this->model_view =new QStandardItemModel(this); 
    model_view->setHorizontalHeaderItem (0,new QStandardItem("工号"));
    model_view->setHorizontalHeaderItem(1,new QStandardItem("用户名"));
    model_view->setHorizontalHeaderItem(2,new QStandardItem("密码"));
    model_view->setHorizontalHeaderItem(3,new QStandardItem("联系方式"));
    model_view->setHorizontalHeaderItem(4,new QStandardItem("权限"));
    this->ui->tb_result->setModel(model_view);
    this->ui->tb_result->setColumnWidth(0,130);
    this->ui->tb_result->setColumnWidth(1,130);
    this->ui->tb_result->setColumnWidth(2,130);
    this->ui->tb_result->setColumnWidth(3,130);
    this->ui->tb_result->setColumnWidth(4,128);
    //删除头序号
   this->ui->tb_result->verticalHeader()->hide();
}

FindUser::~FindUser()
{
    delete ui;
}

void FindUser::on_pb_back_clicked()
{
    this->close();
}

void FindUser::on_pb_GoSearch_clicked()
{
    this->model_view->clear();
    model_view->setHorizontalHeaderItem (0,new QStandardItem("工号"));
    model_view->setHorizontalHeaderItem(1,new QStandardItem("用户名"));
    model_view->setHorizontalHeaderItem(2,new QStandardItem("密码"));
    model_view->setHorizontalHeaderItem(3,new QStandardItem("联系方式"));
    model_view->setHorizontalHeaderItem(4,new QStandardItem("权限"));
    this->ui->tb_result->setColumnWidth(0,130);
    this->ui->tb_result->setColumnWidth(1,130);
    this->ui->tb_result->setColumnWidth(2,130);
    this->ui->tb_result->setColumnWidth(3,130);
    this->ui->tb_result->setColumnWidth(4,128);
    QString SearchView = ui->le_SearchData->text();
    QString Data;
    for(int i = 0;i < SearchView.size();i++)
    {
        if(i)
        {
            if(SearchView[i] == "?"||SearchView[i-1] == "?")
            {
                Data += SearchView[i];
            }
            else
            {
                Data += "*";
                Data +=SearchView[i];
            }

        }
        else
        {
            if(SearchView[0] == '?')
            {
                Data += '?';
            }
            else
            {
                Data += "*";
                Data +=SearchView[0];
            }
        }
    }
    Data+="*";
    //qDebug()<<Data<<endl;
    //12.29 第一次测试失败
    //12.29 第二次测试失败
    //12.29 第三次测试失败
    //12.29 第四次测试成功
    const char * str2 = Data.toUpper().toStdString().c_str();
    int i2 =0;
    std::vector<int> NowViewNum;
    qDebug()<<User.size();
    for(int i = 0;i < (int)User.size();i++)
    {
        //中文使用拼音模糊查询
        const char * str1 = ChineseLetterHelper::GetPinyins(User_Name[i]).toStdString().c_str();
        if(str1[0]!=0&&Model::strMatch(str1,str2)&&std::find(NowViewNum.begin(),NowViewNum.end(),i) == NowViewNum.end())
        {
            QStringList section=User[i].split(QRegExp("[|]"));
                display(i2,section);
                i2++;
                NowViewNum.push_back(i);
                //测试模糊拼音查询
                //qDebug()<<1<<" "<<section.at(1)<<"\""<<str1<<"\""<<(int)str1[0];
                //测试失败 12.29
                //测试成功 12.30
        }
    }
    //测试汉语转拼音
    //qDebug()<<ChineseLetterHelper::GetPinyins(User_Name[4]).toStdString().c_str();
    //测试通过 12.30
    for(int i = 0;i < (int)User.size();i++)
    {
        const char * str1 = User_Name[i].toUpper().toStdString().c_str();
        if(Model::strMatch(str1,str2)&&std::find(NowViewNum.begin(),NowViewNum.end(),i) == NowViewNum.end())
        {
            QStringList section=User[i].split(QRegExp("[|]"));
                display(i2,section);
                i2++;
                NowViewNum.push_back(i);
                //测试姓名查询
                //qDebug()<<2<<" "<<section.at(1);
                //测试通过 12.30
        }    
    }
    for(int i = 0;i < (int)User.size();i++)
    {
        const char * str1 = User_Number[i].toUpper().toStdString().c_str();
        if(Model::strMatch(str1,str2)&&std::find(NowViewNum.begin(),NowViewNum.end(),i) == NowViewNum.end())
        {
            QStringList section=User[i].split(QRegExp("[|]"));
                display(i2,section);
                i2++;
                NowViewNum.push_back(i);
        }
    }
    for(int i = 0;i < (int)User.size();i++)
    {
        const char * str1 = User_Phone[i].toUpper().toStdString().c_str();
        if(Model::strMatch(str1,str2)&&std::find(NowViewNum.begin(),NowViewNum.end(),i) == NowViewNum.end())
        {
            QStringList section=User[i].split(QRegExp("[|]"));
                display(i2,section);
                i2++;
                NowViewNum.push_back(i);
        }
    }
}
void FindUser::display(int row, QStringList subs)
{
    for(int i = 0;i < 4;i++)
    {
        this->model_view->setItem(row,i,new QStandardItem(subs.at(i)));
    }
    this->model_view->setItem(row,4,new QStandardItem((subs.at(4)=="1"?"管理员":"用户")));
}
