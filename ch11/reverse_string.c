/* 功能:反序字符串
   作者:wbx
   日期:2026-10-01 */

#include <stdio.h>
#include <string.h>
#define N 10

char * reverse(char * str);
char * s_gets(char * str, unsigned int size);

int main(void){
   char str[N];
   char * rev;
   unsigned int i = 0;

   printf("请输入要反转的字符串：");
   while(s_gets(str, N) != NULL && str[i] != '\0'){
      rev = reverse(str);
      i ++;
      puts(rev);
   }

   return 0;
}

char * reverse(char * str){
   unsigned int size = strlen(str);
   char * head = str;            //用头指针和尾指针表达从两端向中间走的思想
   char * end = &str[size - 1];

   while(head < end){
      char temp;      //指针未初始化就解引用，会指向随机地址，要用字符类型存字符，并且指针交换不会发生变化
      temp = *end;
      *end = *head;
      *head = temp;
      head ++;    //头指针前移
      end --;     //尾指针后移
   }
   
   return str;
}

char * s_gets(char *s, unsigned int size){
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