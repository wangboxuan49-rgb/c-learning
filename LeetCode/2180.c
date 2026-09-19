/* 功能:统计各位数字之和为偶数的整数个数
   作者:wbx
   日期:2026-09-19 */

//思路："嵌套循环 = 外层遍历 + 内层处理"
#include <stdio.h>

int countEven(int num)
{
    int count = 0;

    while (num > 0) {                /* 外层:从 num 逐个递减到 1 */
        int value = num;             /* 副本,保护外层循环变量 */
        int sum = 0;                 /* 每个数都重新累加 */

        while (value > 0) {          /* 内层:求当前数的各位之和 */
            sum += value % 10;
            value /= 10;
        }

        if (sum % 2 == 0) {          /* 各位和为偶数就计数 */
            count++;
        }

        num--;                       /* 检查下一个数 */
    }

    return count;
}

int main(void)
{
    printf("%d\n", countEven(4));      /* 2  */
    printf("%d\n", countEven(30));     /* 14 */
    printf("%d\n", countEven(1));      /* 0  */
    printf("%d\n", countEven(100));    /* 49 */
    return 0;
}