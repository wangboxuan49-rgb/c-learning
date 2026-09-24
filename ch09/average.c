/* 功能:调和平均数
   作者:wbx
   日期:2026-09-24 */

#include <stdio.h>

double average(double, double);      //函数原型（函数声明），变量名是假名，不必与函数定义的形参名一样，省略也可

int main(void){
   double d_x, d_y;
   double d_result;

   printf("请输入两个 double 类型值：\n");
   scanf("%lf %lf",&d_x,&d_y);

   d_result = average(d_x,d_y);         //函数调用，这里传实参，实参的值赋给形参
   printf("调和平均数为 %f\n",d_result);

   return 0;
}

double average(double x, double y){     //函数定义，这里写形参
   double res;

   res = (1 / x + 1 / y) / 2;

   return 1 / res;
}