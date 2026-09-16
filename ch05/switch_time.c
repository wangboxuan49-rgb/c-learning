/* 功能:时间转换
   作者:wbx
   日期:2026-09-16 */

#include <stdio.h>
const int M_PER_H = 60;    //常量定义一小时的分钟数

int main(void){      
   int i_min = 1;    //给变量赋一个初值，满足进入循环条件，后续再重新赋值
   int i_sh , i_smin;

   //i_min 小于等于 0 时，条件为假，退出循环
   //输入 0 时，输出0 小时0 分钟，这行不该出现，后续可以用if break 解决
   while(i_min > 0){    
      printf("请输入分钟表示的时间（输入小于等于 0 退出）：\n");
      scanf("%d",&i_min);
      i_sh = i_min / M_PER_H;       //整数除法，利用截断特性
      i_smin = i_min % M_PER_H;     //取模，取其余数
      printf("%d 小时%d 分钟\n",i_sh,i_smin);
   }
   return 0;
}