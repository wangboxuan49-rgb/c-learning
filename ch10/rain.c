/* 功能:计算降水量
   作者:wbx
   日期:2026-09-28 */

/* rain.c -- 计算每年的总降水量、年平均降水量和 5 年中每月的平均降水量 */
#include <stdio.h>
#define MONTHS 12     // 一年的月份数
#define YEARS   5     // 年数

int main(void)
{
    // 用 2010～2014 年的降水量数据初始化数组
    const float rain[YEARS][MONTHS] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };
    int year, month;
    float subtot, total;
    const float * pt;   //数组元素只读，float * 指针可写，这是不对的

    //退化：数组名出现在表达式中时，会自动变成「指向它首元素的指针」。
    //二维数组退化成指向一整行的指针，如 pt = rain 为指向 12 个 float 的数组的指针，float (*)[12]
    pt = &rain[0][0];       //定义的 float * 指针是指向单个 float 的指针，所以要取第一行第一列元素
    printf(" YEAR   RAINFALL (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++)
    {                     // 每一年，各月的降水量总和
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += *(pt + year * MONTHS + month);        //二维数组当成一片连续的内存，可以用指针计算偏移
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;    // 5 年的总降水量
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
    printf(" Nov Dec\n");

    for (month = 0; month < MONTHS; month++)
    {                       // 每个月，5 年的总降水量
        for (year = 0, subtot = 0; year < YEARS; year++)
            subtot += *(pt + year * MONTHS + month);
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\n");

    return 0;
}