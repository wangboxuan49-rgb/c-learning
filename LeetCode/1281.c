/* 功能:整数的各位积和之差
   作者:wbx
   日期:2026-09-16 */

//思路：利用求模运算取出整数的个位，再利用循环以及整数除法截断特性，来依次把个位去掉，再依次求模
#include <stdio.h>

int subtractProductAndSum(int n)
{
    int sum = 0;        /* 各位数字之和,初值 0(加法单位元) */
    int product = 1;    /* 各位数字之积,初值 1(乘法单位元) */

    while (n > 0) {
        int digit = n % 10;   /* 取出最后一位，存至临时变量里，避免后续多次操作 */
        sum += digit;         /* 累加 */
        product *= digit;     /* 累乘 */
        n /= 10;              /* 去掉最后一位 */
    }

    return product - sum;
}

int main(void)
{
    printf("%d\n", subtractProductAndSum(234));    /* 15 */
    printf("%d\n", subtractProductAndSum(4421));   /* 21 */
    printf("%d\n", subtractProductAndSum(1));      /* 0  */
    printf("%d\n", subtractProductAndSum(10));     /* -1 */
    return 0;
}