/* 功能:计算负指数幂
   作者:wbx
   日期:2026-09-24 */

#include <stdio.h>

double power(double n, int p); // ANSI 函数原型

int main(void){
    double x, xpow;
    int exp;

    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");

    while (scanf("%lf%d", &x, &exp) == 2){
        if(x != 0 && exp != 0){
            xpow = power(x, exp); // 函数调用
            //%g :用 %e（科学计数法）或 %f（普通小数）中更短的那个来自动选择
            printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        }
        else if(x == 0 && exp > 0){
            printf("%.3g to the power %d is 0\n", x, exp);
        }
        else if(x == 0 && exp < 0){     //0的负指数幂趋近于无穷，未定义
            printf("0 to the power %d is undefined (division by zero)\n", exp);
        }
        else if(x != 0 && exp == 0){
            printf("%.3g to the power %d is 1\n", x, exp);
        }
        else{
            printf("0 to the power 0 is undefined\n");
        }

        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    
    return 0;
}

double power(double n, int p){ // 函数定义
    double pow = 1;
    int i;

    if(p > 0){
        for (i = 1; i <= p; i++)
            pow *= n;
        return pow; // 返回 pow 的值
    }
    else{
        for (i = 1; i <= -p; i++)   //负指数幂计算
            pow *= n;
        return 1 / pow;
    }
}