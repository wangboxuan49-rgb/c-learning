/* 功能:打印字符
   作者:wbx
   日期:2026-09-11 */

#include<stdio.h>
int main(void){
   int asc2;

   printf("请输入一个\" ASC2 \"码值");    //利用转义序列来实现打印出双引号
   scanf("%d",&asc2);
   printf("对应的\" ASC2 \"码值为 %c \n",asc2);    //利用 ASC2 码，特定的整数表示特定的字符

   return 0;
}