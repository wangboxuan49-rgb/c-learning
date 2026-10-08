/* 功能:递归反转字符串
   作者:wbx
   日期:2026-09-25 */

//思路：使用递归的时候，必须有基准情况（也就是跳出递归的最小情况），每次递归必须向基准情况靠近，
//想清楚代码写在递归调用之前还是之后。
#include <stdio.h>
#include <string.h>

void reverseString(char *s, int sSize);        // 入口函数原型
void reverse(char *s, int left, int right);    // 辅助递归函数原型

int main(void){
    char s[100];

    printf("请输入一个字符串（输入 q 退出）：\n");

    while (scanf("%99s", s) == 1 && strcmp(s, "q") != 0){
        reverseString(s, (int)strlen(s));
        printf("反转后：%s\n", s);
        printf("请输入一个字符串（输入 q 退出）：\n");
    }

    printf("Done.\n");
    return 0;
}

void reverseString(char *s, int sSize){        // 入口:从整串的首尾开始
    reverse(s, 0, sSize - 1);
}

void reverse(char *s, int left, int right){    // 递归函数:交换首尾,再处理中间
    if (left >= right)                         // 基准情况:只剩一个字符或没有了
        return;

    char tmp = s[left];                        // 交换首尾两个字符
    s[left] = s[right];
    s[right] = tmp;

    reverse(s, left + 1, right - 1);           // 对中间剩下的部分做同样的事
}