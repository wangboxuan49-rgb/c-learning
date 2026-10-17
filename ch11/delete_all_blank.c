/* 功能:删除所有空白
   作者:wbx
   日期:2026-09-30 */

#include <stdio.h>
#define N 10

//函数功能：接受一个字符串作为参数，并删除字符串中的空白
void delete_all_blank(char * arr);

int main(void){
   char arr[N + 1];  //定义数组提供 fgets 需要的存放字符串的空间，定义指针只提供地址
   int ch = 0;

   //fgets 没读到任何字符就遇到 EOF 会返回 NULL
   while(fgets(arr, N + 1, stdin) != NULL){     //循环读取输入行，直到输入一行空行
      // 判断：是否直接按回车
      if(arr[0] == '\n'){
         break;
      }
      
      int i = 0;
      while(arr[i] != '\0' && arr[i] != '\n'){     //找到字符串的末尾或者换行的位置
         i ++;
      }

      if(arr[i] == '\n'){     //去掉读入的换行，标记为字符串结尾
         arr[i] = '\0';
      }
      else{       //数组没装下整行时，丢弃本行剩余输入
         while((ch = getchar()) != '\n' && ch != EOF)
            ;
      }

      delete_all_blank(arr);
      fputs(arr, stdout);
   }

   return 0;
}

void delete_all_blank(char * arr){
   char * read = arr;      //一个读指针一个写指针都指向 arr 的地址，利用*指针可以更改 arr 的值
   char * write = arr;

   while(*read != '\0'){
      if(*read != ' '){
         *write = *read;
         write ++;      //写入一个值后，前进一步
      }

      read ++;    //遍历字符串
   }

   *write = '\0';

   return;
}