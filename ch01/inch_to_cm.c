/* 功能:英寸转厘米换算
   作者:wbx
   日期:2026-09-09 */

#include <stdio.h>
int main() {
    float inch;   //声明英寸单位
    float cm;     //声明厘米单位

    printf("请输入英寸数：");
    scanf("%f",&inch);  //输入英寸数
    cm = inch * 2.54;   //1英寸等于 2.54 厘米
    printf("\n 换算成厘米数为：%f\n",cm);  //输出程序目标

    return 0;
}