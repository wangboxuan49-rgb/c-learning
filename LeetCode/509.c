/* 功能:斐波那契数
   作者:wbx
   日期:2026-09-24 */

//思路：使用递归函数的思想
#include <stdio.h>

int fib(int n);          // 函数原型

int fib(int n){         // 函数定义
    if (n < 2) {
        return n;        // F(0)=0, F(1)=1
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void){
    int n;

    printf("Enter a non-negative integer n (q to quit): ");
    while (scanf("%d", &n) == 1) {
        if (n < 0) {
            printf("n must be >= 0, try again.\n");
        } else {
            printf("fib(%d) = %d\n", n, fib(n));
        }
        printf("Enter a non-negative integer n (q to quit): ");
    }
    printf("bye!\n");
    return 0;
}