/* 功能:文件拷贝
   作者:wbx
   日期:2026-10-05 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

char * s_gets(char * arr, int n);

int main(void){
   char source_filename[SIZE];
   char target_filename[SIZE];
   char * s_p;
   char * t_p;
   FILE * s_fp;
   FILE * t_fp;
   int ch;

   printf("请输入用于拷贝的文件名（源文件）：\n");
   s_p = s_gets(source_filename, SIZE);
   if(s_p == NULL){
      printf("未读取到内容或读取失败\n");
      exit(EXIT_FAILURE);
   }
   if((s_fp = fopen(source_filename, "r")) == NULL){
      printf("无法读取文件\n");
      exit(EXIT_FAILURE);
   }

   printf("请输入想要拷贝到文件名（目标文件）：\n");
   t_p = s_gets(target_filename, SIZE);
   if(t_p == NULL){
      printf("未读取到内容或读取失败\n");
      exit(EXIT_FAILURE);
   }
   if(strcmp(source_filename, target_filename) == 0){    //“w“会截断文件，同名会把源文件截断
      printf("源文件和目标文件不能重名\n");
      exit(EXIT_FAILURE);
   }
   if((t_fp = fopen(target_filename, "w")) == NULL){
      printf("无法写入文件\n");
      exit(EXIT_FAILURE);
   }

   while((ch = getc(s_fp)) != EOF){
      ch = toupper(ch);
      putc(ch, t_fp);
   }

   fclose(s_fp);
   fclose(t_fp);
   if(fclose(s_fp) != 0 || fclose(t_fp) != 0){
      fprintf(stderr, "文件关闭失败\n");     //使用 stderr 指针，把错误消息发到标准错误
   }

   return 0;
}

char * s_gets(char * arr, int n){
   char * p;
   char * find;

   p = fgets(arr, n, stdin);
   if(p != NULL){
      find = strchr(arr, '\n');
      if(find != NULL){
         *find = '\0';
      }
      else{
         int ch;
         while((ch = getchar()) != '\n' && ch != EOF){
            continue;
         }
      }
   }

   return p;
}