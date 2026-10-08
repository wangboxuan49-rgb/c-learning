/* 功能:求二进制数组中连续 1 的最大个数
   作者:wbx
   日期:2026-09-26 */

//思路:一遍扫描，count 记当前这段 1 的长度，在计数的同时，用 max 记历史最大值
#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize);   // 函数原型

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;    // 当前这段连续 1 的长度
    int max = 0;      // 目前为止的最大长度

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;
            if (count > max)   // 每加一次就结算，末尾那段才不会被漏掉
                max = count;
        } else {
            count = 0;         // 碰到 0，这一段结束，重新计数
        }
    }

    return max;
}

int main(void) {
    int n;

    printf("请输入数组长度（输入 q 退出）：\n");
    while (scanf("%d", &n) == 1 && n > 0) {
        int nums[1000];

        printf("请输入 %d 个 0 或 1（用空格或回车分隔）：\n", n);
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &nums[i]) != 1) {
                printf("输入有误，请重新输入。\n");
                return 1;
            }
        }

        printf("最大连续 1 的个数：%d\n", findMaxConsecutiveOnes(nums, n));
        printf("请输入数组长度（输入 q 退出）：\n");
    }

    printf("Done.\n");
    return 0;
}