/* 功能:数组相加
   作者:wbx
   日期:2026-09-26 */

#include <stdio.h>

void array_add(int a[], int b[], int sum[], int x);

int main(void){
   int i_array1[4] = {2, 4, 5, 8};
   int i_array2[4] = {1, 0, 4, 6};
   int sum[] = {0};

   array_add(i_array1, i_array2, sum, 4);
   
   for(int i = 0; i < 4; i ++){
      printf("%d ",sum[i]);
   }
   printf("\n");

   return 0;
}

void array_add(int a[], int b[], int sum[], int x){   //数组不能直接回传，可以在函数中直接修改数组
   for(int i = 0; i < x; i ++){
      sum[i] = a[i] + b[i];
   }

   return;
}