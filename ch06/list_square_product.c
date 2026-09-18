/* 功能:平方立方表
   作者:wbx
   日期:2026-09-18 */

#include <stdio.h>

int main(void){
   int i_high, i_low;
   int i;
   int num,square,product;

   printf("请输入表格上界:\n");
   scanf("%d",&i_high);
   printf("请输入表格下界:\n");
   scanf("%d",&i_low);
   printf("整数        整数的平方  整数的立方\n");    //创建表格的表头
   for(i = 0; i <= (i_high - i_low); i++){
      num = i_low + i;
      square = num * num;
      product = square * num;
      printf("%-11d %-11d %-11d\n",num,square,product);     //规定字段宽度并使其左对齐
   }
   
   return 0;
}