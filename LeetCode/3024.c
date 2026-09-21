/* 功能:三角形类型
   作者:wbx
   日期:2026-09-21 */

//思路：首先要用 if 语句判断是否能构成三角形，再用嵌套 if 语句来判断三角形类型
#include <stdio.h>

char* triangleType(int* nums, int numsSize) {
    (void)numsSize;        /* 告诉编译器"我知道有这个参数,故意不用" */
    /* ① 能不能构成三角形:任意两边之和必须大于第三边 */
    if (nums[0] + nums[1] > nums[2] &&
        nums[1] + nums[2] > nums[0] &&
        nums[0] + nums[2] > nums[1]) {

        /* ② 能构成,判断类型 */
        if (nums[0] == nums[1] && nums[1] == nums[2]) {     //不能写成链式相等，从左到右计算会出错
            return "equilateral";       /* 三边全相等 */
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2] ||
                 nums[0] == nums[2]) {
            return "isosceles";         /* 恰好两边相等 */
        }
        else {
            return "scalene";           /* 三边都不等 */
        }
    }
    else {
        return "none";                  /* 构不成三角形 */
    }
}

int main(void) {
    int t[][3] = {{3,3,3},{3,4,4},{3,4,5},{1,1,3},{4,4,4},{2,3,5}};
    for (int i = 0; i < 6; i++)
        printf("[%d,%d,%d] -> %s\n",
               t[i][0], t[i][1], t[i][2], triangleType(t[i], 3));
    return 0;
}