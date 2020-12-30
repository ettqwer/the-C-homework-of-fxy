#include "small_shop_sql.h"
#include "add_user.h"
#include <QApplication>
#include "rootview.h"
#include "pooruserview.h"
#include "addgoods.h"
#include"searchgoods.h"
#include"deletegoods.h"
#include"changegoods.h"
#include"ingoods.h"
#include"allinformation.h"
#include"outgoods.h"
#include"thenumbeeofgoodscharts.h"
#include"setting.h"
#include"usersudo.h"
#include"pooruserview.h"
#include"sudonumberchange.h"
#include<ALLIN.h>
/****************************定义全局变量****************************/
std::vector<QString> User,Goods,Record,Sudo;
std::vector<QString> User_Number,User_Name,User_password,User_Phone,User_Sudo;
QString User_Number_Now;
int User_Sort_Now;
/**************************定义全局变量结束**************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //从Small_Shop_Sql 开始执行程序
    Small_Shop_SQL w;
    //从Add_User 开始执行程序
    //Add_User w;
    //从RootView 开始执行程序
    //RootView w;
    //从AddGoods 开始执行程序
    //AddGoods w;
    //从SearchGoods 开始执行程序
    //SearchGoods w;
    //从DeleteGoods 开始执行程序
    //DeleteGoods w;
    //从ChangeGoods 开始执行程序
    //ChangeGoods w;
    //从InGoods 开始执行程序
    //InGoods w;
    //从AllInformation 开始执行程序
    //AllInformation w;
    //从OutGoods 开始执行程序
    //OutGoods w;
    //从TheNumbeeOfGoodsCharts 开始执行程序
    //TheNumbeeOfGoodsCharts w;
    //从Setting 开始执行程序
    //Setting w;
    //从UserSudo 开始执行程序
    //UserSudo w;
    //从PoorUserView 开始执行程序
    //PoorUserView w;
    //从SudoNumberChange 开始执行程序
    //SudoNumberChange w;
    w.show();
    return a.exec();
}
