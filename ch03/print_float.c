/* 功能:打印浮点数
   作者:wbx
   日期:2026-09-12 */

#include<stdio.h>
int main(void){
    float f_dec;    //变量命名前用 i_(int)、f_(float)、ui_(unsigned)简要表示数据类型
    // 使用十六进制浮点数，方便观察底层尾数差异
    double d_dec = 0x1.3c0ca428c59fb1p+0;
    long double ld_dec = 0x1.3c0ca428c59fb12345678p+0L;//浮点数后缀加上 L

    printf("\aEnter a floating-point value:");  //用转义字符发出警报
    scanf("%f",&f_dec);
    printf("fixed-point notation:%.20f\n",f_dec);  //打印为小数点形式，提高到20位
    printf("fixed-point notation:%.20e\n",f_dec);  //打印为指数形式
    printf("fixed-point notation:%.20a\n",f_dec);  //打印为 p 计数法（十六进制记数法）

    /*
    printf("\aEnter a double value:");  //用转义字符发出警报
    scanf("%lf",&d_dec);    //输入scanf：double用%lf；输出printf：double用%f
    */
    printf("fixed-point notation:%.20f\n",d_dec);  //打印为小数点形式
    printf("fixed-point notation:%.20e\n",d_dec);  //打印为指数形式
    printf("fixed-point notation:%.20a\n",d_dec);  //打印为 p 计数法（十六进制记数法）

    /*
    printf("\aEnter a long double value:");  //用转义字符发出警报
    scanf("%Lf",&ld_dec);   //均要大写 L
    */
    printf("fixed-point notation:%.20Lf\n",ld_dec)  ;  //打印为小数点形式
    printf("fixed-point notation:%.20Le\n",ld_dec);  //打印为指数形式
    printf("fixed-point notation:%.20La\n",ld_dec);  //打印为 p 计数法（十六进制记数法） 

    return 0;
}