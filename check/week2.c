/* 功能:第二周验收
   作者:wbx
   日期:2026-09-20 */

#include <stdio.h>

int main(void)
{
    int i_sum = 0;
    int i;

    for (i = 1; i <= 100; i++) {    //在 1～100 整数里遍历
        if (i % 2 == 0) {   //判断是否为偶数
            i_sum += i;
        }
    }

    printf("%d\n", i_sum);

    return 0;
}