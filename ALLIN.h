#ifndef ALLIN_H
#define ALLIN_H



/****************公用头文件******************/
#include<algorithm>
#include<vector>
#include<QDebug>
#include<QMessageBox>
#include<QPushButton>
#include<QList>
#include<QAbstractButton>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<chineseletterhelper.h>
#include<model.h>
#include<QStandardItemModel>
#include<QHeaderView>
/****************公用头文件结束******************/




/****************声明全局变量******************/
extern std::vector<QString> User,Goods,Record,Sudo;
extern std::vector<QString> User_Number,User_Name,User_password,User_Phone,User_Sudo;
extern QString User_Number_Now;
extern int User_Sort_Now;
/****************声明全局变量结束******************/






#endif // ALLIN_H
