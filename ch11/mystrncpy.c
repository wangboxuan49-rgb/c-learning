/* 功能:自写拷贝字符串函数
   作者:wbx
   日期:2026-10-01 */

#include <stdio.h>
#include <string.h>
#define SIZE 20
#define N 5

char * mystrncpy(char * s1, char * s2, unsigned int n);
char * mystrncat(char * s1, char * s2, unsigned int n);
static char *get_line(char *s, int size);

int main(void){
   char str1[SIZE];
   char str2[SIZE];
   char str3[SIZE];
   char * p1;
   char * p2;

   printf("请输入第一个和第二个字符串：(输入 quit 退出)");
   //使用 fgets 函数会导致换行符没去掉，同时剩下的输入在缓冲区里下次输入
   while(get_line(str1, SIZE) != NULL && get_line(str2, SIZE) != NULL){    
      p1 = mystrncat(str1, str2, N);
      
      if(strncmp(str1, "quit", 4) == 0 || strncmp(str2, "quit", 4) == 0){     //字符串字面量必须用双引号，字符常量用单引号
         break;
      }

      p2 = mystrncpy(str3, str1, N);

      printf("拼接两个字符串\n");
      puts(p1);
      printf("拷贝第一个字符串\n");
      puts(p2);
   }
   
   return 0;
}

char * mystrncat(char * s1, char * s2, unsigned int n){
   unsigned int size = strlen(s1);
   unsigned int i = 0;
   
   while(i < n && s2[i] != '\0'){
      s1[size + i] = s2[i];
      i ++;
   }

   s1[size + i] = '\0';      //结尾补'\0'，strncat 总是补终止符

   return s1;
}

char * mystrncpy(char * s1, char * s2, unsigned int n){
   unsigned int i = 0;
   
   while(i < n && s2[i] != '\0'){
      s1[i] = s2[i];
      i ++;
   }
   for (; i < n; i++){  //标准行为是剩余位置全部补 '\0'
      s1[i] = '\0';
   }
   
   return s1;
}

// 读一行并去掉换行；若这一行超过缓冲区，把剩余字符丢掉
static char * get_line(char *s, int size){
    char *ret = fgets(s, size, stdin);
    if (ret == NULL)
        return NULL;

    char *p = strchr(s, '\n');
    if (p != NULL)
        *p = '\0';              // 正常情况：换行在缓冲区里，改成 '\0'
    else
        while (getchar() != '\n' && !feof(stdin))
            ;                   // 超长行：丢掉本行剩下的部分

    return ret;
}