/* 功能:二维数组
   作者:wbx
   日期:2026-09-26 */
   
#include <stdio.h>

void show_array(int a[][5], int x, int y);   //二维数组作参数时的列数必须写死，内存中二维数组排成一列，必须要知道列数
void double_array(int a[][5], int x, int y);

int main(void){
   int i_array[3][5] = {      //定义二维数组
      {4, 8, 3, 1, 7},
      {3, 4, 0, 6, 5},
      {1, 2, 2, 5, 7}
   };

   show_array(i_array, 3, 5);
   printf("\n");
   double_array(i_array, 3, 5);
   show_array(i_array, 3, 5);
   printf("\n");

   return 0;
}

void show_array(int a[][5], int x, int y){      //二维数组遍历的时候需要用双层嵌套
   for(int i = 0; i < x; i ++){
      for(int j = 0; j < y; j ++){
         printf("%d\t",a[i][j]);
      }
      printf("\n");
   }
}

void double_array(int a[][5], int x, int y){    //二维数组修改时也要双层嵌套
   for(int i = 0; i < x; i ++){
      for(int j = 0; j < y; j ++)
         a[i][j] *= 2;
   }
}