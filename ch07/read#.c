/* 功能:读取输入
   作者:wbx
   日期:2026-09-21 */

#include <stdio.h>
#define STOP '#'     //宏定义停止字符，字符要带单引号

int main(void){
   int i_space = 0;   //空格数量
   int i_line = 0;    //换行符数
   int i_ch = 0;      //所有其他字符数量
   char c;

   while((c = getchar()) != STOP){     //设置停止字符
      if(c == ' '){
         i_space ++;
      }
      else if(c == '\n'){
         i_line ++;
      }
      else{
         i_ch ++;
      }
   }

   printf("空格数量为 %d，换行符数量为 %d，所有其他字符数量为 %d\n",i_space,i_line,i_ch);

   return 0;
}