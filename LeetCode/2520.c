/* 功能:统计能整除数字的位数
   作者:wbx
   日期:2026-09-17 */

//思路：用original存住原值、拿它去做整除判断,同时用n做取位循环。"一个变量走循环、一个变量守住原值"
//不存住原值的话，if 语句判断时 num 是跟着循环变的
#include <stdio.h>

int countDigits(int num)
{
    int original = num;   /* 保存原始数字,用于整除判断 */
    int n = num;          /* 取位用的副本,循环中会不断缩小 */
    int count = 0;        /* 能整除的位数,初值 0 */

    while (n > 0) {
        int digit = n % 10;              /* 取出最后一位 */
        if (original % digit == 0) {     /* 用原始数字判断是否能整除 */
            count++;                     /* 能整除就 +1 */
        }
        n /= 10;                         /* 自除，去掉最后一位 */
    }

    return count;
}

int main(void)
{
    printf("%d\n", countDigits(7));      /* 1 */
    printf("%d\n", countDigits(121));    /* 2 */
    printf("%d\n", countDigits(1248));   /* 4 */
    printf("%d\n", countDigits(123));    /* 2 */
    return 0;
}