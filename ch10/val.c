/* 功能:变长数组
   作者:wbx
   日期:2026-09-29 */

#include <stdio.h>

//使用变长数组，数组维度可以用变量来表示，要求行数形参和列数形参位于数组形参之前
//函数应该能处理任意 N×M 数组，VLA 的「变长」意义就在于让两个数组的步长一致
void copy_arr(int rows, int cols, double const s_arr[rows][cols], double t_arr[rows][cols]); 
void show_arr(int rows, int cols, double const arr[rows][cols]);  //使用 const 来保护无需修改的数组

int main(void){
   double source[3][5] = {
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5}
   };
   double target[3][5];

   copy_arr(3, 5, source, target);
   printf("以下是源数组\n");
   show_arr(3, 5, source);
   printf("以下是目标数组\n");
   show_arr(3, 5, target);

   return 0;
}

void copy_arr(int rows, int cols, double const s_arr[rows][cols], double t_arr[rows][cols]){
   for(int i = 0; i < rows; i ++){
      for(int j = 0; j < cols; j ++){
         t_arr[i][j] = s_arr[i][j];
      }
   }

   return;
}

void show_arr(int rows, int cols, double const arr[rows][cols]){
   for(int i = 0; i < rows; i ++){
      for(int j = 0; j < cols; j ++){
         printf("%.2f\t", arr[i][j]);
      }
      printf("\n");
   }

   return;
}