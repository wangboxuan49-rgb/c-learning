/* 功能:删除空白
   作者:wbx
   日期:2026-09-30 */

#include <stdio.h>
#include <ctype.h>    // isspace() 判断空白字符
#define N 10

//函数功能：从一行输入中把一个单词读入一个数组中，并丢弃输入行中的剩余字符。同时跳过第一个非空白字符之前的所有空白
void delete_blank(char * arr, int size);

int main(void){
   char arr[N + 1];

   delete_blank(arr, N);
   fputs(arr, stdout);
   printf("\n");

   return 0;
}

void delete_blank(char * arr, int size){
   int i = 0;
   int ch = EOF;     //给 ch 初始化，避免以后传入 size == 0 时，循环没有执行，下面却使用了未初始化的 ch
   int sign = 0;     //用来标记第一次非空白字符出现，0：单词尚未开始，1：单词已经开始

   while(i < size && (ch = getchar()) != EOF){
      if(ch == '\n'){
         break;      // 当前行已经结束
      }
      
      if(!isspace((unsigned char)ch)){    //判断 ch 是否为空白，若是，isspace（）返回值非零
         sign = 1;
      }

      if(sign == 0){
         continue;
      }
      else if(sign == 1){
         if(isspace((unsigned char)ch)){     //单词开始后，遇到空白就停止保存
            break;
         }
         arr[i ++] = (char)ch;
      }
   }
   arr[i] = '\0';    //给字符串结尾

   // 如果还没到行尾，丢弃本行剩余字符
   if(ch != '\n' && ch != EOF){
      while((ch = getchar()) != '\n' && ch != EOF){
         // 只读取，不保存
      }
   }

   return;
}