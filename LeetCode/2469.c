/* 功能:温度转换
   作者:wbx
   日期:2026-09-12 */

#include <stdio.h>

int main(void){
    double celsius;      // 摄氏温度
    double kelvin;       // 开尔文 
    double fahrenheit;   // 华氏度

    printf("请输入摄氏温度: ");
    scanf("%lf", &celsius);   //输入 double 用 %lf

    kelvin = celsius + 273.15;   //不用加 F 后缀，会降低精度，当需要省内存或者给 float 赋值时使用
    fahrenheit = celsius * 1.80 + 32.00;

    printf("摄氏温度: %.2f\n", celsius);  //输出 double 用 %f
    printf("开尔文  : %.5f\n", kelvin);
    printf("华氏度  : %.5f\n", fahrenheit);

    return 0;
}