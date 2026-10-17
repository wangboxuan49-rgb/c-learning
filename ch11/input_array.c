/* 功能:输入储存数组
   作者:wbx
   日期:2026-09-30 */
   
#include <stdio.h>
#define N 10   

//函数功能：从标准输入读取至多 size 个字符（含空白、制表、换行），存入 arr，并在末尾补 '\0'。
char * input_array(char * arr, int size);

int main(void){
   char arr[N + 1];     // N 个输入字符，加一个 '\0'
   char * ret;     // 接收返回值，用来判断是否读到结尾

   while(1){
      printf("请输入：（按 ctrl+D 结束）\n");   //有待提交字符，没有按回车，ctrl+d 会提交字符；没有待提交字符，ctrl+d 会遇到 EOF

      ret = input_array(arr, N);
      if(ret == NULL){
         break;
      }

      printf("\n输出结果为：\n");
      printf("%s", arr);

      // 本次读取已经遇到 EOF，输出已有内容后直接结束
      if(feof(stdin)){
         break;
      }
   }

   return 0;
}

char * input_array(char * arr, int size){
   int i = 0;
   int ch = 0;    //getchar() 返回 int
   
   //i < size - 1 —— 留出最后一格给 '\0'，防止越界，空行时按 control+D 标记文件结尾，退出循环
   // Ctrl+D 在空行处才表示 EOF；输入未结束时按 Ctrl+D 只是把当前行交给程序
   while(i < size - 1 && (ch = getchar()) != EOF){    
      arr[i ++] = (char)ch;      // 先存，再把下标往后挪一位
   }
   arr[i] = '\0';    //手动封口：无论读了多少个，都要成为合法字符串

   // 新增：数组已满，且最后保存的字符不是换行
   // 丢弃本行剩余输入，包括末尾的换行
   if(i == size - 1 && ch != '\n'){
      while((ch = getchar()) != '\n' && ch != EOF)
      ;
   }

   if(i == 0 && ch == EOF){      //输入流已结束且未读到任何字符时返回 NULL。
      return NULL;
   }

   return arr;    //成功时返回 arr（便于链式调用）；
}