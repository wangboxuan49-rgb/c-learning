/* 功能:两整数相加
   作者:wbx
   日期:2026-09-10 */


#include <stdio.h>
int sum(int num1, int num2) {
    return num1 + num2;     //函数要返回整型数据，可以直接返回两变量相加
}

int main(void) {
    printf("%d\n", sum(12, 5));   //可以直接打印返回值为整型的函数
    return 0;
}