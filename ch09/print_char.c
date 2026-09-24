/* 功能:打印字符
   作者:wbx
   日期:2026-09-24 */

#include <stdio.h>

void print_char(char, int, int);

int main(void){
   char c_ch;
   int i_frequency;
   int i_line;

   printf("请输入待打印字符：");
   c_ch = getchar();
   printf("请输入一行打印字符次数：");
   scanf("%d",&i_frequency);
   printf("请输入打印指定字符的行数：");
   scanf("%d",&i_line);
   print_char(c_ch,i_frequency,i_line);

   return 0;
}

void print_char(char ch, int fre, int line){
   int i;

   for(; line > 0; line --){
      i = fre;
      for(; i > 0; i --){
         putchar(ch);
      }
      printf("\n");
   }
}