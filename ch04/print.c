/* 功能:打印文本
   作者:wbx
   日期:2026-09-13 */

#include <stdio.h>

int main(void){
    char c_name[40];
    double d_cash;

    printf("请输入姓名：\n");
    scanf("%s",c_name);   //数组不用&
    printf("请输入金额：\n");
    scanf("%lf",&d_cash);     //double 类型输入用 %lf
    printf("The %s family just may be $%.2f dollars richer!\n",c_name,d_cash); //double 类型输出用 %f

    return 0;
}