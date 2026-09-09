/* 功能:函数调用练习
   作者:wbx
   日期:2026-09-09 */

#include <stdio.h>
void jolly(void);  //声明调用函数
void deny(void);
int main(void) {
   jolly();    //调用第一个函数
   jolly();
   jolly();
   deny();     //调用第二个函数
   getchar();     //用于暂停程序，按键才能继续

   return 0;
}

void jolly(void) {
   printf("For he's a jolly good fellow!\n");
}

void deny(void) {
   printf("Which nobody can deny!\n");
}