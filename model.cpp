#include "model.h"

Model::Model()
{

}
bool Model::strMatch(const char *str1, const char *str2)
{
   int slen1 = strlen(str1);
   int slen2 = strlen(str2); //实际使用时根据strl的长度来动态分配表的内存
   char matchmap[128][128];
   memset(matchmap, 0, 128*128);
   int i, j, k; //定义内循环的范围
   int lbound = 0;
   int upbound = 0; //遍历目标字符串符串
   for(i = 0; i< slen1; ++i)
    {
   //遍历通配符串
   int bMatched = 0;
   int upthis = upbound;
       for(j = lbound; j<=upthis ; ++j)
       {
       //匹配当前字符
       if(str1[i] == str2[j] || str2[j] == '?')
           {
           matchmap[i][j] = 1;
               if(0 == bMatched)
                   {
                   lbound = j+1;
                   }
           upbound = j+1;
           bMatched = 1;
               if(i == slen1 - 1)
               {
                //考虑末尾是*的特殊情况
                   for(k = j+1 ; k < slen2 && '*' == str2[k] ; ++k)
                   {
                   matchmap[i][k] = 1;
                   }
               }
           }
       else if(str2[j] == '*')
       {
           if(0 == bMatched)
           {
           lbound = j;
           }
           //遇到星号，目标字符串到末尾都能得到匹配
           for(k = i; k< slen1; ++k)
           {
           matchmap[k][j] = 1;
           }
           k = j;
           while( '*' == str2[++k])
           {
           matchmap[i][k] = 1;
           }
           if(str1[i] == str2[k] || str2[k] == '?')
           {
           matchmap[i][k] = 1;
           upbound = k+1;
               if(i == slen1 - 1)
               {
                   //考虑末尾是*的特殊情况
                   for(k = k+1 ; k < slen2 && '*' == str2[k] ; ++k)
                   {
                   matchmap[i][k] = 1;
                   }
               }
           }
           else
           {
           upbound = k;
           }
           bMatched = 1;
       }
       }
//居然没有匹配到
   if(!bMatched )
       {
   return 0;
       }
   }
   return matchmap[slen1-1][slen2-1];
}
