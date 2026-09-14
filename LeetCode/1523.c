/* 功能:在区间范围内统计奇数数目
   作者:wbx
   日期:2026-09-14 */

/*思路：首先思考 1～n 有多少个奇数，利用整数除法 / 截断的特性，可知有（n+1）/ 2 个奇数，
   区间为【low，high】，区间内奇数个数为【1，high】的奇数个数 -【1，low-1】的奇数个数*/

#include <stdio.h>

int countOdds(int low, int high) {
   return (high + 1)/2 - low/2;
}

int main(void) {
   printf("%d\n", countOdds(3, 7));     // 应输出 3
   printf("%d\n", countOdds(8, 10));    // 应输出 1

   return 0;
}