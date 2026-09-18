/* 功能:26个字母数组
   作者:wbx
   日期:2026-09-18 */

#include <stdio.h>

int main(void){
   char c_letters[30];
   int index;

   for(index = 0; index < 26; index ++){     //用数组下标来进行循环
      //字符在运算时会自动变成整数,参与算术运算时,char会自动提升为int,在赋值回char类型时又转回字符
      c_letters[index] = 'a' + index;  //创建 26 字母数组
      printf("%c",c_letters[index]);   //打印数组
   }
   printf("\n");

   return 0;
}