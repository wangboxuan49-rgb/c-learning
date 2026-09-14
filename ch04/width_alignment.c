/* 功能:printf宽度对齐
   作者:wbx
   日期:2026-09-14 */

#include <stdio.h>
#include <string.h>     //为了能使用 strlen()函数的头文件
#define WIDTH 20    //定义明示常量，便于修改多处使用的变量

int main(void){
   char c_first[20];
   char c_last[20];

   printf("请输入名和姓:\n");
   scanf("%s %s",c_first,c_last);   //scanf 只会读取字符串中的一个单词而不是一整句，所以要分名和姓
   printf("名是\"%s\",姓是\"%s\"\n",c_first,c_last);    //打印双引号使用转义字符\"
   //在宽度 20 的字段右端打印（默认在右），*指代最大字段宽度，要在后面加上待打印项变量（按顺序）
   printf("名是\"%*s\"\n姓是\"%*s\"\n",WIDTH,c_first,WIDTH,c_last);
   // - 为待打印项左对齐
   printf("名是\"%-*s\"\n姓是\"%-*s\"\n",WIDTH,c_first,WIDTH,c_last);
   //使用strlen()函数获取字符串长度，strlen()的返回值类型是size_t(一种无符号整数)，要使用(int)强制类型转换
   //整个名字放在比名字宽3的字段里(右对齐)
   printf("\"%*s %s\"\n", (int)strlen(c_first) + 3, c_first, c_last);

   return 0;
}