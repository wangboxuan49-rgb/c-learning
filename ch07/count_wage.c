/* 功能:计算工资
   作者:wbx
   日期:2026-09-21 */

#include <stdio.h>
#define WAGE_PER_H 1000          //时薪
#define EXTRA_WAGE_TIME 1.5      //加班工资增幅
#define TAX_FIRST_300 0.15       //第一段税率
#define TAX_LAST_150 0.2         //第二段税率
#define TAX_REST 0.25            //第三段税率

int main(void){
   double d_workhour = 0;     //初值要全部归零
   double d_totalwage = 0;
   double d_tax = 0;
   double d_realwage = 0;

   printf("请输入一周工作的小时数：");
   scanf("%lf",&d_workhour);

   if(d_workhour <= 40){         //没有加班的情况
      d_totalwage = d_workhour * WAGE_PER_H;
      
   }
   else if(d_workhour > 40){     //有加班的情况，可以直接用 else，此处为了程序可读性
      d_totalwage = 40 * WAGE_PER_H + (d_workhour - 40) * EXTRA_WAGE_TIME * WAGE_PER_H;
   }

   printf("工资总额为：%.2f\n",d_totalwage);

   if(d_totalwage <= 300){    //分段计算税金
      d_tax = d_totalwage * TAX_FIRST_300;
   }
   else if(d_totalwage > 300 && d_totalwage <= 450){     //可以不写>300，此处为了程序可读性
      d_tax = 300 * TAX_FIRST_300 + (d_totalwage - 300) * TAX_LAST_150;
   }
   else if(d_totalwage > 450){      //可以写为 else
      d_tax = 300 * TAX_FIRST_300 + 150 * TAX_LAST_150 + (d_totalwage - 450) * TAX_REST;
   }

   printf("税金为 %.2f\n",d_tax);

   d_realwage = d_totalwage - d_tax;      //计算净收入
   printf("净收入为：%.2f\n",d_realwage);

   return 0;
}