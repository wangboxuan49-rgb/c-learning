/* 功能:找出最大可达成数字
   作者:wbx
   日期:2026-09-11 */

//思路：在一次操作当中，给定整数与可达成数字最大相差 2，即用操作次数乘 2 可得出最大相差距离，再加上基数
#include<stdio.h>
int theMaximumAchievableX(int num, int t);   //函数声明，需要带类型声明
int main(void){
   int num , t;

   printf("请给定一个整数以及操作数\n");
   scanf("%d %d",&num,&t);
   //函数调用时不能带类型声明,有返回值的函数可以视为变量
   printf("最大可达成数字为 %d\n",theMaximumAchievableX(num, t)); 

   return 0;
}

int theMaximumAchievableX(int num, int t) {     //函数定义，需要带类型声明
    return num + 2 * t;    //可以直接 return 一个变量计算的值
}