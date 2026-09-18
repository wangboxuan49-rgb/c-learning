/* 功能:各位相加
   作者:wbx
   日期:2026-09-18 */

//思路：内层循环用于将 num 的各位数字加起来，直至个位数除十变为 0，跳出循环
//外层循环用于判断相加结果是否为个位数，若不是则用新值再循环一遍，注意累加器要清零
//结果还可以是 num % 9 的值
#include <stdio.h>

int addDigits(int num)
{
    while (num >= 10) {              /* 还不是一位数,就继续 */
        int sum = 0;                 /* 每轮的各位之和,定义在循环内,自动清零 */
        while (num > 0) {
            sum += num % 10;         /* 取出最后一位,累加 */
            num /= 10;               /* 去掉最后一位 */
        }
        num = sum;                   /* 各位之和作为新的 num,回到外层判断 */
    }
    return num;                      /* 已经是一位数 */
}

int main(void)
{
    printf("%d\n", addDigits(38));      /* 2  */
    printf("%d\n", addDigits(0));       /* 0  */
    printf("%d\n", addDigits(10));      /* 1  */
    printf("%d\n", addDigits(999));     /* 9  */
    printf("%d\n", addDigits(12345));   /* 6  */
    return 0;
}