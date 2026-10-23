/* 功能:不使用全局变量
   作者:wbx
   日期:2026-10-02 */

/* global.c -- 使用外部变量 */
#include <stdio.h>

//int units = 0;         /* 外部变量 */

int critic(void);

int main(void)
{
   //extern int units; /* 可选的重复声明 */     //extern主要用于声明函数要使用该外部变量，可省略
   int units = 0;          //有外部变量再在函数内部定义，会隐藏外部变量

   printf("How many pounds to a firkin of butter?\n");
   scanf("%d", &units);
   while (units != 56){
      units = critic();
   }
   printf("You must have looked it up!\n");

   return 0;
}

int critic(void)
{
   int num = 0;
   /* 删除了可选的重复声明 */
   printf("No luck, my friend. Try again.\n");
   scanf("%d", &num);

   return num;
}