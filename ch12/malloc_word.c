/* 功能:动态存储单词
   作者:wbx
   日期:2026-10-03 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

char * storage_words(void);
void show_words(int num, char **word);

int main(void){
   int num = 0;
   char ** p;  
   //char *a[SIZE] 是指针数组，一堆指针排成一行，每个指向各自的数据，指向指针的指针 char ** p 也是指针数组
   //char (*a)[SIZE] 是数组指针，只有一个指着，指向 SIZE 个字符的连续内存，内存里装的是字符不是指针

   printf("How many words do you wish to enter?");
   scanf("%d",&num);
   printf("Enter %d words now:\n",num);

   p = (char **)malloc(num * sizeof(char *));   //为 num 个 char * 指针申请内存，设置 p 指向该位置
   for(int i = 0; i < num; i ++){
      p[i] = storage_words();
   }
   
   show_words(num, p);

   for (int i = 0; i < num; i++)    //分配两次就要释放两次，释放顺序和分配顺序相反
      free(p[i]);
   free(p);

   return 0;
}

char * storage_words(void){
   char temp[SIZE];     //临时字符串数组，用作中转
   char * word;

   scanf("%8s",temp);      //数组名就是指针，不用写取地址符
   word = (char *)malloc((strlen(temp) + 1) * sizeof(char));

   strcpy(word, temp);     //从临时数组搬到动态内存

   return word;
}

void show_words(int num, char **word){
   printf("Here are your words:\n");

   for(int i = 0; i < num; i ++){
      printf("%s\n",word[i]);
   }

   return;
}