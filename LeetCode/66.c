/* 功能:加一
   作者:wbx
   日期:2026-10-05 */

//思路：函数实现表示大整数的数组加一，并返回结果数字数组，将数组转成数字加一之后再转成数组，
//这个操作会导致即使 longlong 类型也存不下超过上限的整数，数组长度最多一百位，转成整数最多有 20 位，所以不能实现。
//故采取直接在数组上进行操作，对数组逐位判断，如果一位不是 9 的话，直接加一返回原数组，如果一位是 9 的话，当前位置零，下一位加一返回原数组
//如果每一位都是 9 的话，所有位置零，数组开始应多加一位，进一
#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            digits[i] += 1;
            int *res = (int *)malloc((size_t)digitsSize * sizeof(int));     //将数据传入一个新数组返回，防止主函数中内存释放两次
            if (res == NULL) {
                *returnSize = 0;
                return NULL;
            }
            for (int j = 0; j < digitsSize; j++) {      //不能直接 res = digits，这样仅赋值了地址，分配的内存没有用上
                res[j] = digits[j];
            }
            *returnSize = digitsSize;
            return res;
        }
        digits[i] = 0;
    }

    int *res = (int *)malloc((size_t)(digitsSize + 1) * sizeof(int));
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }
    res[0] = 1;
    for (int i = 1; i < digitsSize + 1; i++) {
        res[i] = 0;
    }
    *returnSize = digitsSize + 1;
    return res;
}

/* ---------- 以下为本地测试代码,提交 LeetCode 时删掉 ---------- */

static void run_case(const int *input, int n, const char *desc)
{
    int *digits = malloc((size_t)n * sizeof(int));
    if (digits == NULL) return;
    for (int i = 0; i < n; i++) digits[i] = input[i];

    int size = 0;
    int *result = plusOne(digits, n, &size);

    printf("%-10s 输入:", desc);
    for (int i = 0; i < n; i++) printf(" %d", input[i]);
    printf("  ->  长度 %d,结果:", size);
    for (int i = 0; i < size; i++) printf(" %d", result[i]);
    printf("\n");

    free(digits);
    free(result);
}

int main(void)
{
    int a[] = {1, 2, 3};
    int b[] = {4, 3, 2, 1};
    int c[] = {9};
    int d[] = {9, 9, 9};
    int e[] = {1, 9, 9};
    int f[] = {8, 9, 9, 9};
    int g[] = {0};

    run_case(a, 3, "普通");
    run_case(b, 4, "普通");
    run_case(c, 1, "单个9");
    run_case(d, 3, "全9");
    run_case(e, 3, "中间进位");
    run_case(f, 4, "末尾连续9");
    run_case(g, 1, "数字0");

    return 0;
}

/* 先转成数字，再转回数组的思路，不能用于表示大整数的数组
#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 1) 数组 → 数字
    unsigned long long num = 0;
    for (int i = 0; i < digitsSize; i++)
        num = num * 10 + (unsigned long long)digits[i];

    num += 1;

    // 2) 数位数：do-while —— 至少一位，去掉一位，直到没有为止
    unsigned long long tmp = num;
    int len = 0;
    do {
        len++;
        tmp /= 10;
    } while (tmp > 0);

    // 3) 分配 + 从后往前填回
    int *res = malloc(len * sizeof(int));
    if (res == NULL)
        return NULL;

    unsigned long long v = num;
    for (int i = len - 1; i >= 0; i--) {
        res[i] = (int)(v % 10);   // 最后一位放到数组最后
        v /= 10;                  // 去掉最后一位
    }

    *returnSize = len;
    return res;
}
*/