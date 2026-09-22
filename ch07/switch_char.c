/* 功能:替换字符进阶
   作者:wbx
   日期:2026-09-22 */

#include <stdio.h>
#define STOP '#'     //宏定义停止字符，字符要带单引号

int main(void){
   int i_change = 0;
   char c;

   while((c = getchar()) != STOP){     //设置停止字符
      switch(c){     //用 switch 语句进行分支选择，适用于等值判断
         case '.':
            putchar('!');
            i_change ++;
            break;      //用于跳出 switch 语句，否则就会按顺序执行 default 部分
         case '!':
            printf("!!");
            i_change ++;
            break;
         default:
            putchar(c);
      }
   }

   printf("替换次数为 %d\n",i_change);

   return 0;
}