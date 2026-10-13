/* 功能:原地移除数组中等于 val 的元素
   作者:wbx
   日期:2026-09-28 */

//思路:读指针 p 一路前进，写指针 nums 只在元素该留下时(元素不等于要删除的值时)才写并前进
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val);   // 函数原型

/* LeetCode 提交版：只有一个函数 */
int removeElement(int* nums, int numsSize, int val) {
    int * p = nums;

    for (int i = 0; i < numsSize; i++) {
        if (*(p + i) != val) {
            *(nums) = *(p + i);   // 该留：写到写指针处
            nums++;               // 写指针前进
        }
    }

    return nums - p;              // 指向差 = 留下的元素个数
}


static void test(const char *name, int *a, int n, int val, int expect) {
    int got = removeElement(a, n, val);

    printf("%-26s 期望 %d，得到 %d   前段: ", name, expect, got);
    for (int i = 0; i < (got < n ? got : n); i++)
        printf("%d ", a[i]);
    printf("  %s\n", got == expect ? "OK" : "错");
}

int main(void) {
    int a1[] = {3, 2, 2, 3};
    int a2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int a3[] = {1};
    int a4[] = {2};
    int a5[] = {2, 2, 2, 2};
    int a6[] = {1, 3, 5, 7};
    int a7[] = {1, 2, 3, 2};
    int a8[] = {0};

    test("[3,2,2,3] val=3",         a1, 4, 3, 2);
    test("[0,1,2,2,3,0,4,2] val=2", a2, 8, 2, 5);
    test("[1] val=1",               a3, 1, 1, 0);
    test("[2] val=3",               a4, 1, 3, 1);
    test("[2,2,2,2] val=2",         a5, 4, 2, 0);
    test("[1,3,5,7] val=9",         a6, 4, 9, 4);
    test("[1,2,3,2] val=2",         a7, 4, 2, 2);
    test("空数组 val=5",            a8, 0, 5, 0);

    return 0;
}