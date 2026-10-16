/* 功能:求最富有客户的资产总量
   作者:wbx
   日期:2026-09-29 */

//思路:逐行求和，与当前最大值比较；初值用第 0 行的行和打底
#include <stdio.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);   // 函数原型

/* LeetCode 提交版 */
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max = 0;

    /* 初值：把第 0 行的资产总额算出来，而不是取 accounts[0][0] */
    for (int j = 0; j < accountsColSize[0]; j++)
        max += accounts[0][j];

    /* 从第 1 行开始，逐行求和比较 */
    for (int i = 1; i < accountsSize; i++) {
        int sum = 0;
        for (int j = 0; j < accountsColSize[i]; j++)    //注意此处为一个指针（数组）要用下标取数据
            sum += accounts[i][j];
        if (sum > max)
            max = sum;
    }

    return max;
}

/* ---------- 以下是本地测试用，LeetCode 提交时不用交 ---------- */

static void test(const char *name, int **acc, int rows, int *cols, int expect) {
    int got = maximumWealth(acc, rows, cols);
    printf("%-34s 期望 %3d，得到 %3d   %s\n", name, expect, got, got == expect ? "OK" : "错");
}

int main(void) {
    int r1a[] = {1, 2, 3}, r1b[] = {3, 2, 1};
    int *a1[] = {r1a, r1b};                     int c1[] = {3, 3};

    int r2a[] = {1, 5}, r2b[] = {7, 3}, r2c[] = {3, 5};
    int *a2[] = {r2a, r2b, r2c};                int c2[] = {2, 2, 2};

    int r3a[] = {2, 8, 7}, r3b[] = {7, 1, 3}, r3c[] = {1, 9, 5};
    int *a3[] = {r3a, r3b, r3c};                int c3[] = {3, 3, 3};

    int r4a[] = {5};
    int *a4[] = {r4a};                          int c4[] = {1};

    int r5a[] = {0, 0}, r5b[] = {0, 1};
    int *a5[] = {r5a, r5b};                     int c5[] = {2, 2};

    int r6a[] = {0, 0}, r6b[] = {0, 0};
    int *a6[] = {r6a, r6b};                     int c6[] = {2, 2};

    test("[[1,2,3],[3,2,1]]",         a1, 2, c1, 6);
    test("[[1,5],[7,3],[3,5]]",       a2, 3, c2, 10);
    test("[[2,8,7],[7,1,3],[1,9,5]]", a3, 3, c3, 17);
    test("[[5]]",                     a4, 1, c4, 5);
    test("[[0,0],[0,1]]",             a5, 2, c5, 1);
    test("[[0,0],[0,0]]",             a6, 2, c6, 0);

    return 0;
}