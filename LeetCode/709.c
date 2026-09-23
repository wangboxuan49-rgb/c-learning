/* 功能:转换小写字母
   作者:wbx
   日期:2026-09-23 */

//思路：大写字母与小写字母asc2 码值相差 32，即'a'-'A'=32，字符串也可以遍历
#include <stdio.h>

char* toLowerCase(char* s)
{
    for (int i = 0; s[i] != '\0'; i++) {      /* 逐字符遍历,直到字符串结尾 */
        if (s[i] >= 'A' && s[i] <= 'Z') {     /* 如果这个字符是大写字母 */
            s[i] = s[i] + ('a' - 'A');        /* 转成小写(相当于 +32) */
        }
    }
    return s;
}

int main(void)
{
    char a[] = "Hello";
    char b[] = "here";
    char c[] = "LOVELY";
    char d[] = "abc123XYZ";

    printf("%s\n", toLowerCase(a));   /* hello     */
    printf("%s\n", toLowerCase(b));   /* here      */
    printf("%s\n", toLowerCase(c));   /* lovely    */
    printf("%s\n", toLowerCase(d));   /* abc123xyz */

    return 0;
}