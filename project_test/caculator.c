/* 功能:头文件应用
   作者:wbx
   日期:2026-09-25 */

#include <stdio.h>      //尖括号：找系统的标准库
#include "mymath.h"     //自建头文件，双引号：先找当前目录，再找系统

int main(void){
   int ch;  //避免 EOF

   while(1){
      printf("Enter the operation of your choice:\n"
         "a.add     \ts.subtract\nm.multiply\td.divide\nq.quit\n");  //printf 如果要折行的话每行都要有完整双引号
      ch = getchar();
      
      switch(ch){
         case 'a':
            add();      //可以将输入两个数字功能再抽取出，成为另一个函数，还未学到，待优化
            break;
         case 's':
            subtract();
            break;
         case 'm':
            multiply();
            break;
         case 'd':
            divide();
            break;
         default:
            break;
      }

      if(ch == 'q')
         break;

      //scanf（）函数把换行符留在了输入队列中，getchar（）不会跳过换行符，所以在下一轮迭代的时，还没有输入就读取了换行符   
      while(getchar() != '\n')   //用于跳过无关输入
         continue;
   }

   printf("Bye.\n");

   return 0;
}

