/* 功能:将数字变成 0 的操作次数
   作者:wbx
   日期:2026-09-23 */

#include <stdio.h>

int numberOfSteps(int num)
{
    int step;

    for (step = 0; num != 0; step++) {
        if (num % 2 == 0) {
            num /= 2;          /* 偶数:除以 2 */
        }
        else {
            num -= 1;          /* 奇数:减 1 */
        }
    }

    return step;
}

int main(void)
{
    printf("%d\n", numberOfSteps(14));    /* 6  */
    printf("%d\n", numberOfSteps(8));     /* 4  */
    printf("%d\n", numberOfSteps(123));   /* 12 */
    printf("%d\n", numberOfSteps(0));     /* 0  */
    printf("%d\n", numberOfSteps(1));     /* 1  */
    return 0;
}