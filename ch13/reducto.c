/* 功能:把文件压缩成原来的 1/3
   作者:wbx
   日期:2026-10-05 */

/* reducto.c -- 把文件压缩成原来的 1/3 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define SIZE 40

char * s_gets(char * arr, int n);

int main(void)
{
   FILE *in, *out;
   int ch;
   char name[LEN];
   int count = 0;
   char filename[SIZE];
   char * p;
   
   printf("请输入文件名：\n");
   p = s_gets(filename, SIZE);
   if (p == NULL)
   {
      printf("未读取到内容或读取失败\n");
      exit(EXIT_FAILURE);
   }

   if ((in = fopen(filename, "r")) == NULL)
   {
      fprintf(stderr, "I couldn't open the file \"%s\"\n", filename);
      exit(EXIT_FAILURE);
   }

   strncpy(name, filename, LEN - 5);     /* 拷贝文件名 */
   name[LEN - 5] = '\0';                /* 手动封口 */
   strcat(name, ".red");                /* 拼上 .red */

   if ((out = fopen(name, "w")) == NULL)
   {
      fprintf(stderr, "Can't create output file.\n");
      exit(EXIT_FAILURE);
   }

   while ((ch = getc(in)) != EOF)
      if (count++ % 3 == 0)
         putc(ch, out);               /* 每 3 个字符取第 1 个 */

   if (fclose(in) != 0 || fclose(out) != 0)
      fprintf(stderr, "Error in closing files\n");    //使用 stderr 指针，把错误消息发到标准错误

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