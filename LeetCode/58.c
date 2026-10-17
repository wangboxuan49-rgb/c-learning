/* 功能:最后一个单词的长度
   作者:wbx
   日期:2026-09-30 */

//思路：从字符串末尾往前扫描，先找到 '\0' 的位置，得到长度，跳过末尾的空格，从后往前数字母，直到遇到空格或到达字符串开头
#include <stdio.h>

int lengthOfLastWord(char *s);

int main(void)
{
    const char *cases[] = {
        "Hello World",
        "   fly me   to   the moon  ",
        "luffy is still joyboy",
        "a",
        " a ",
        "   a   ",
        "a ",
        "ab cd"
    };
    int n = (int)(sizeof(cases) / sizeof(cases[0]));

    for (int k = 0; k < n; k++)
        printf("s = \"%s\"  ->  %d\n", cases[k], lengthOfLastWord((char *)cases[k]));

    return 0;
}

int lengthOfLastWord(char *s)
{
    int i = 0;          /* 下标，最终停在最后一个单词之前 */
    int count = 0;      /* 最后一个单词的字母数 */

    /* 1. 走到字符串末尾，i 等于长度，也可以用 strlen 函数测量字符串长度代替 */
    while (s[i] != '\0')
        i++;

    /* 2. 跳过末尾空格
     *    i > 0 是下界保护：若整个字符串都是空格，i 最多减到 0，不会越界 */
    while (i > 0 && s[i - 1] == ' ')
        i--;

    /* 3. 从后往前数最后一个单词的字母
     *    i > 0 防止读到 s[-1]：最后一个单词可能从下标 0 开始（如 "a"） */
    while (i > 0 && s[i - 1] != ' ') {
        i--;
        count++;
    }

    return count;
}