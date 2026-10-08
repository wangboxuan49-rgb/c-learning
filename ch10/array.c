/* 功能:返回数组值
   作者:wbx
   日期:2026-09-26 */

#include <stdio.h>

int array_max(int a[], int x);   //在函数声明和定义时数组要加[]
double array_diff(double a[], int x);

int main(void){
   int i_array[5] = {3, 0, 2, 9, 6};
   int i_max;
   double d_array[5] = {4.3, 9.1, 3.8, 5.4, 6.6};
   double d_diff;

   i_max = array_max(i_array, 5);   //在函数调用时数组直接写名字
   printf("数组当中最大值为：%d\n",i_max);

   d_diff = array_diff(d_array, 5);
   printf("数组当中最大值和最小值之间的差值是：%.2f\n",d_diff);

   return 0;
}

int array_max(int a[], int x){
   int max = a[0];

   for(int i = 0; i < x; i ++){
      if(a[i] > max)
         max = a[i];    //遍历数组，寻找到最大值就改变 max 值
   }

   return max;
}

double array_diff(double a[], int x){
   double max = a[0];
   double min = a[0];

   for(int i = 0; i < x; i ++){
      if(a[i] > max)
         max = a[i];    //遍历数组，寻找到最大值就改变 max 值
      if(a[i] < min)
         min = a[i];
   }

   return max - min;
}