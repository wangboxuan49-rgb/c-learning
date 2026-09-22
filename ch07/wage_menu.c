/* 功能:工资等级菜单
   作者:wbx
   日期:2026-09-22 */

#include <stdio.h>
#define EXTRA_WAGE_TIME 1.5      //加班工资增幅
#define TAX_FIRST_300 0.15       //第一段税率
#define TAX_LAST_150 0.2         //第二段税率
#define TAX_REST 0.25            //第三段税率

int main(void){
   int num = 0;
   double d_workhour = 0;     //初值要全部归零
   double d_totalwage = 0;
   double d_tax = 0;
   double d_realwage = 0;
   double wage_per_h = 0;

   while(num != 5){
      printf("*****************************************************************\n");
      printf("Enter the number corresponding to the desired pay rate or action:\n");
      printf("1) $8.75/hr\t\t\t2) $9.33/hr\n3) $10.00/hr\t\t\t4) $11.20/hr\n5) quit\n");
      printf("*****************************************************************\n");
      
      if(scanf("%d",&num) != 1){    //防止用户输入字母或者字符等非数字，scanf返回成功读取项数
         printf("Enter the number!\n");
         while(getchar() != '\n')      //scanf 遇到非法字符停下不会清空，getchar 来清除缓存区
            ;      //循环内不做任何操作
         continue;      //不执行循环后续内容，从头开始循环      
      }

      switch(num){
         case 1:
            wage_per_h = 8.75;
            break;
         case 2:
            wage_per_h = 9.33;
            break;
         case 3:
            wage_per_h = 10.00;
            break;
         case 4:
            wage_per_h = 11.20;
            break;
         case 5:
            break;
         default:
            printf("Please enter again!\n");
      }

      if(num >= 1 && num <= 4){
         printf("请输入一周工作的小时数：");
         scanf("%lf",&d_workhour);

         if(d_workhour <= 40){         //没有加班的情况
            d_totalwage = d_workhour * wage_per_h;
         }
         else if(d_workhour > 40){     //有加班的情况，可以直接用 else，此处为了程序可读性
            d_totalwage = 40 * wage_per_h + (d_workhour - 40) * EXTRA_WAGE_TIME * wage_per_h;
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
      }
   }

   return 0;
}