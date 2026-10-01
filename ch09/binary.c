/* 功能:以指定进制形式打印整数
   作者:wbx
   日期:2026-09-25 */

#include <stdio.h>

void to_base_n(unsigned long n, unsigned long num);

int main(void){
   unsigned long number;
   unsigned long value;

   printf("请输入一个数和进制数(2~10进制)：（输入 q 退出）\n");

   while (scanf("%lu %lu", &number, &value) == 2){
      if (value < 2 || value > 10){
        printf("进制数必须在 2~10 之间，请重新输入。\n");
        continue;          // 跳过本次输出，回到输入循环
      }
      printf("%lu的%lu进制数为：",number, value);
      to_base_n(number, value);
      putchar('\n');
      printf("请输入一个数和进制数：（输入 q 退出）\n");
   }

   printf("Done.\n");

   return 0;
}

void to_base_n(unsigned long n, unsigned long num){      //递归函数
   int r;

   r = n % num;   //暂存余数，为最后输出结果

   if(n >= num)
      to_base_n(n / num, num);      //递归调用  

   printf("%d",r);      //倒序，在递归调用之后的语句，按被调函数相反的顺序执行
}