/* 功能:Daphne 与 Deirdre 的利息
   作者:wbx
   日期:2026-09-18 */

#include <stdio.h>
#define MONEY 100

int main(void){
   int i_years = 0;     //计数器从 0 开始:初值 0 + 每轮 +1 = 总次数
   double d_Da_money,d_De_money;
   double d_De_profit;
   d_Da_money = MONEY;
   d_De_money = MONEY;

   //不能写小于，两个初值相等，无法进入循环
   for(d_De_profit = 0; d_De_money <= d_Da_money; i_years ++){ 
      d_De_profit = d_De_money * 0.05;
      d_De_money += d_De_profit;    //复利，利息为当前余额的 5%（包括之前的利息）
      d_Da_money += MONEY * 0.1;    //单利，本金不变，每年获利原始投资的 10%
   }
   printf("Need %d years\n",i_years);
   printf("Da has %.2f$, De has %.2f$\n",d_Da_money,d_De_money);

   return 0;
}