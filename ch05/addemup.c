/* 功能:累加赚钱
   作者:wbx
   日期:2026-09-16 */

#include <stdio.h>

int main(void){
   int count , sum;
   int i_day;

   count = 0;
   sum = 0;
   printf("请输入总共的赚钱天数：\n");
   scanf("%d",&i_day);
   //因为初值为 0，所以才能在循环条件里用 count++
   //循环条件判断完之后就完成递增操作
   while(count++ < i_day)     
      sum = sum + count;
   printf("总共%d 天赚到的钱为%d\n",i_day,sum);

   return 0;
}