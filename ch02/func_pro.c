/* 功能:函数调用练习_进阶
   作者:wbx
   日期:2026-09-09 */

#include <stdio.h>
void one_three(void);      //声明子函数
void two(void);
int main(void) {
   printf("starting now:\n");
   one_three();      //调用其中一个子函数
   printf("done!\n");
   getchar();     //用于暂停输出结果

   return 0;
}

void one_three(void) {
   printf("one\n");
   two();      //嵌套另一个子函数
   printf("three\n");
}

void two(void) {
   printf("two\n");
}