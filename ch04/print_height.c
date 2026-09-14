/* 功能:打印姓名身高
   作者:wbx
   日期:2026-09-14 */

#include <stdio.h>

int main(void){
    float f_height;
    char c_name[20];

    printf("请你输入身高（厘米）和姓名：\n");
    scanf("%f %s",&f_height,c_name);   //字符数组不需要&，其余需要
    printf("%s,you are %.3f meter tall\n",c_name,f_height / 100);  //由厘米转换为米

    return 0;
}