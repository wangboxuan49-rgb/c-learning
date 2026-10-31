/* 功能:逐字符打印并计数
   作者:wbx
   日期:2026-10-05 */

/* count.c -- 使用标准 I/O */
#include <stdio.h>
#include <stdlib.h>     /* 提供 exit() 的原型 */
#include <string.h>
#define SIZE 50

char * s_gets(char * arr, int n);      //函数用于解决 scanf 函数输入遇到空格就停止，fgets 函数末尾有换行的问题

int main(void)
{
   int ch;                     /* 读取文件时,储存每个字符的地方 */
   FILE *fp;                   /* "文件指针" */
   unsigned long count = 0;
   char filename[SIZE];
   char * p;

   printf("请输入文件名：\n");
   p = s_gets(filename, SIZE);

   if(p == NULL){             //函数返回指针的目的，仅是为了判断有没有输入，内容在函数里就传进去了
      printf("未读取到内容或读取失败\n");
      exit(EXIT_FAILURE);
   }
   /*if (filename == NULL)    //错误，filename 被分配内存之后，没有空的状态
   {
      printf("文件不存在\n");
      exit(EXIT_FAILURE);
   }*/

   if ((fp = fopen(filename, "r")) == NULL)
   {
      printf("Can't open %s\n", filename);
      exit(EXIT_FAILURE);
   }

   while ((ch = getc(fp)) != EOF)
   {
      putc(ch, stdout);       /* 与 putchar(ch); 相同 */
      count++;
   }

   fclose(fp);
   printf("File %s has %lu characters\n", filename, count);

   return 0;
}
/* 使用命令行参数获取输入

int main(int argc, char *argv[])    //第一个参数是命令行参数个数，第二个参数是参数字符串数组
{
    int ch;                    
    FILE *fp;            
    unsigned long count = 0;

    if (argc != 2)      //用户真正传的参数个数 = argc - 1，此处是传错了参数，程序给出提示
    {
        printf("Usage: %s filename\n", argv[0]);   //argv[0] 通常是程序自己，argc 永远 ≥ 1(至少包含程序名)
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)     
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); 
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", argv[1], count);

    return 0;
}*/

char * s_gets(char * arr, int n){
   char * p;
   char * find;

   p = fgets(arr, n, stdin);     //函数返回指针，遇到 EOF 就返回 NULL，一次最多读 n-1 个字符

   if(p != NULL){
      find = strchr(arr, '\n');  //找到数组中的换行符，并返回一个地址
      if(find != NULL){
         *find = '\0';        //将换行符替换为一个字符串的结尾，去掉换行
      }
      else{
         int ch;
         //用于处理fgets 没读取完的缓冲区，直接丢弃，如果输入超长且没有换行就遇到 EOF，getchar 永远不等于'\n'，是死循环
         while((ch = getchar()) != '\n' && ch != EOF){   
            continue;
         }
      }
   }

   return p;
}