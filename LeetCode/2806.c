/* 功能:取整购买后的账户余额
   作者:wbx
   日期:2026-09-16 */

//思路：+5 是为了四舍五人的满五进一，/10 整数除法会进行截断（只保留十位以上），*10 变回十的倍数
//思路可以应用到取整到最近的整数（也可以用(int)强制类型转换截断），取整到最近的 0.5（先乘二再除二）
#include <stdio.h>

int accountBalanceAfterPurchase(int purchase) {     //purchase 是实参
    return 100 - (purchase + 5) / 10 * 10;
}

int main(void) {
    printf("%d\n", accountBalanceAfterPurchase(9));    // 应输出 90，9 是实参
    printf("%d\n", accountBalanceAfterPurchase(15));   // 应输出 80
    printf("%d\n", accountBalanceAfterPurchase(4));    // 应输出 100
    
    return 0;
}