/* 功能:打印浮点数
   作者:wbx
   日期:2026-09-12 */

#include<stdio.h>
int main(void){
    float f_dec;    //变量命名前用 i_(int)、f_(float)、ui_(unsigned)简要表示数据类型
    double d_dec = 1.234567890123456789012345;
    long double ld_dec = 1.234567890123456789012345L;//浮点数后缀加上 F 或 L 后缀可以覆盖默认设置

    printf("\aEnter a floating-point value:");  //用转义字符发出警报
    scanf("%f",&f_dec);
    printf("fixed-point notation:%.15f\n",f_dec);  //打印为小数点形式  
    printf("fixed-point notation:%.15e\n",f_dec);  //打印为指数形式
    printf("fixed-point notation:%.15a\n",f_dec);  //打印为 p 计数法（十六进制记数法）

    /*
    printf("\aEnter a double value:");  //用转义字符发出警报
    scanf("%lf",&d_dec);    //输入scanf：double用%lf；输出printf：double用%f
    */
    printf("fixed-point notation:%.15f\n",d_dec);  //打印为小数点形式
    printf("fixed-point notation:%.15e\n",d_dec);  //打印为指数形式
    printf("fixed-point notation:%.15a\n",d_dec);  //打印为 p 计数法（十六进制记数法）

    /*
    printf("\aEnter a long double value:");  //用转义字符发出警报
    scanf("%Lf",&ld_dec);   //均要大写 L
    */
    printf("fixed-point notation:%.15Lf\n",ld_dec);  //打印为小数点形式
    printf("fixed-point notation:%.15Le\n",ld_dec);  //打印为指数形式
    printf("fixed-point notation:%.15La\n",ld_dec);  //打印为 p 计数法（十六进制记数法） 

    return 0;
}