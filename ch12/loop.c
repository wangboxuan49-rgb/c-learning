/* 功能:检查循环调用次数
   作者:wbx
   日期:2026-10-02 */

#include <stdio.h>

unsigned int loop(void);

int main(void){
   int i = 0;
   unsigned int loop_num = 0;
   
   printf("请输入一个或多个整数：（按0 退出）");
   while(scanf("%d",&i) == 1 && i > 0){      //按回车不会结束循环，输入多个数字会一直增加函数调用次数
      while(i > 0){        //不加内部循环，会陷入一直 scanf 的死循环
         loop_num = loop();
         i --;
      }
   }
   printf("函数被调用 %u 次\n",loop_num);

   return 0;
}

unsigned int loop(void){
   //static 静态存储，静态变量只在编译时初始化一次，值储存在静态内存里原地不动，从程序被载入到程序结束期间都存在，但是作用域会被限制，无链接时外部不可用
   static unsigned int count = 0;   
   count ++;

   return count;
}