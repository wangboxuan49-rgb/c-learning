/* 功能:区间平方和
   作者:wbx
   日期:2026-09-18 */

#include <stdio.h>

int main(void){
   int i_high,i_low;
   int i_sum=0;
   int i;

   printf("Enter lower and upper integer limits:");      //首先在循环外读一次
   scanf("%d %d",&i_low,&i_high);
   //用do while的话会执行最后一次不正确的结果，使用 if break 结构可以省去循环外的输入
   while(i_low < i_high){     //要求多次输入，要用嵌套循环
      for(i = i_low; i <= i_high; i ++){     //这样设置初值和判断条件可以扫到上界和下界
         i_sum += (i * i);    //自增，括号为最优先运算级
      }
      printf("The sums of the squares from %d to %d is %d\n",i_low * i_low,i_high * i_high,i_sum);
      i_sum = 0;     //总和每次循环要清零，否则会累加
      printf("Enter lower and upper integer limits:");   //循环末尾再读，用于下一个循环
      scanf("%d %d",&i_low,&i_high);
   }
   printf("Done\n");

   return 0;
}