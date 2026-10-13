/* 功能:数组拷贝
   作者:wbx
   日期:2026-09-28 */

#include <stdio.h>

void copy_arr(double t[], double s[], int x);      //使用带数组表示法
void copy_ptr(double * t_arr, double * s_arr, int x);    //使用带指针表示法
void copy_ptrs(double * t_arr, double * start, double * end);     //使用首尾元素指针表示
void show_arr(double arr[], int x);
void show_2D_arr(double arr[][12], int x, int y);     //传二维数组时一定要定好列数


int main(void){
   double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
   double target1[5];
   double target2[5];
   double target3[5];
   double target4[3];
   double source2[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
   double source3[5][12] = 
   {
      { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
      { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
      { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
      { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
      { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
   };
   double target5[5][12];

   copy_arr(target1, source, 5);
   copy_ptr(target2, source, 5);
   copy_ptrs(target3, source, source + 5);

   copy_ptrs(target4, source2 + 2, source2 + 5);      //首指针地址小于尾指针，所以不能+4

   for(int i = 0; i < 5; i ++){
      //二维数组是数组的数组，target[0] 是「一行」的地址，会退化成指向 double 的指针，符合函数要求
      copy_arr(target5[i], source3[i], 12);    
   }

   show_arr(target1, 5);
   show_arr(target2, 5);
   show_arr(target3, 5);

   show_arr(target4, 3);

   show_2D_arr(target5, 5, 12);

   return 0;
}

void copy_arr(double t[], double s[], int x){
   for(int i = 0; i < x; i ++){
      t[i] = s[i];
   }

   return;
}

void copy_ptr(double * t_arr, double * s_arr, int x){ //数组名是数组首元素的地址，等同于指向数组首元素的指针
   for(int i = 0; i < x; i ++){
      *(t_arr + i) = *(s_arr + i);     //指针的值是数据地址，所以变更数据值需要解引用运算符，+i 目的是移动指针
   }

   return;
}

void copy_ptrs(double * t_arr, double * start, double * end){
   while(start < end){     //首指针不大于尾指针，本质上是对数组元素地址的比较
      *t_arr = *start;     //移动首指针
      t_arr ++;      //对指针值进行运算，本质是变更指向元素的地址
      start ++;
   }
   
   return;
}

void show_arr(double arr[], int x){
   for(int i = 0; i < x; i ++){
      printf("%.2f\t",arr[i]);
   }
   printf("\n");

   return;
}

void show_2D_arr(double arr[][12], int x, int y){
   for(int i = 0; i < x; i ++){
      for(int j = 0; j < y; j ++){
         printf("%.2f\t",arr[i][j]);
      }
      printf("\n");
   }
   return;
}