/* 功能:循环打印整数
   作者:wbx
   日期:2026-09-16 */

#include <stdio.h>

int main(void){
   int i_num;
   int i_value;      //设置一个临时变量用于存储i_num+10，否则循环判断中i_num会一直变（因为i_num++）

   printf("请输入一个整数：\n");
   scanf("%d",&i_num);
   i_value = i_num + 10;
   printf("比该数大 10 的所有整数有：\n");
   while(i_num <= i_value){      //使用循环，条件为真循环，为假则跳出循环
      printf("%d\t",i_num);
      i_num ++;      //因为要包含输入的整数，所以不能在循环条件中输入
   }

   return 0;
}