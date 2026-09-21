/* 功能:替换字符
   作者:wbx
   日期:2026-09-21 */

#include <stdio.h>
#define STOP '#'     //宏定义停止字符，字符要带单引号

int main(void){
   int i_change = 0;
   char c;

   while((c = getchar()) != STOP){     //设置停止字符
      if(c == '.'){
         putchar('!');
         i_change ++;
      }
      else if(c == '!'){
         putchar('!');     //getchar()和 putchar()都是处理字符的函数，不能处理字符串，所以不能一下输出两个'!'
         putchar('!');
         i_change ++;
      }
      else{
         putchar(c);    //其余原样输出
      }
   }

   printf("替换次数为 %d",i_change);

   return 0;
}