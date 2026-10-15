/* 功能:数组程序
   作者:wbx
   日期:2026-09-29 */

#include <stdio.h>
#define ROWS 3
#define COLS 5

void storage_data(int rows, int cols, double arr[rows][cols]); //函数作用将输入存至二维数组
//函数作用计算二维数组中一行元素的平均值，只需要传一维数组，因为只读不写，使用 const 防止对函数造成修改
double average_line_data(double const arr[], int cols);  
double average_all_data(int rows, int cols, double const arr[rows][cols]); //函数作用计算所有元素平均值
double max_data(int rows, int cols, double const arr[rows][cols]);   //函数作用计算所有元素最大值
void show_arr(int rows, int cols, double const arr[rows][cols]);  //函数作用展示二维数组

int main(void){
   double d_array[ROWS][COLS];
   double averages[ROWS];

   storage_data(ROWS, COLS, d_array);
   show_arr(ROWS, COLS, d_array);

   for(int i = 0; i < ROWS; i ++){     //利用循环来计算每一行元素的平均值
      averages[i] = average_line_data(d_array[i], COLS);    //二维数组规定某行，变成一维数组
      printf("第 %d 组数据的平均值为：%.2f\n",i + 1,averages[i]);
   }
   printf("所有数据的平均数为 %.2f\n",average_all_data(ROWS, COLS, d_array));

   printf("所有数据的最大值为 %.2f\n",max_data(ROWS, COLS, d_array));

   return 0;
}

void storage_data(int rows, int cols, double arr[rows][cols]){
   printf("请输入 %d 组值，每组包含 %d 个 double 类型的数\n",rows,cols);
   for(int i = 0; i < rows; i ++){
      printf("请输入第 %d 组值：\n",i + 1);
      for(int j = 0; j < cols; j ++){
         scanf("%lf",&arr[i][j]);
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

double average_line_data(double const arr[], int cols){
   double sum = 0;

   for(int i = 0; i < cols; i ++){
      sum += arr[i];
   }

   return sum / cols;
}

double average_all_data(int rows, int cols, double const arr[rows][cols]){
   double sum = 0;
   
   for(int i = 0; i < rows; i ++){
      for(int j = 0; j < cols; j ++){
         sum += arr[i][j];
      }
   }

   return sum / (rows * cols);
}

double max_data(int rows, int cols, double const arr[rows][cols]){
   double max = arr[0][0];

   for(int i = 0; i < rows; i ++){
      for(int j = 0; j < cols; j ++){
         if(arr[i][j] > max){
            max = arr[i][j];
         }
      }
   }

   return max;
}