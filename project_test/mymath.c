//源文件，放函数定义（函数怎么实现）

#include <stdio.h>      //因为下面用了 printf等
#include "mymath.h"     //头文件里有函数声明,不包含的话编译器会警告"隐式函数声明"

void add(void){
   float f_num_1, f_num_2;
   float result;

   printf("Enter first number:");
   while(1){
      if(scanf("%f",&f_num_1) != 1){   //返回值非一个，则为读取失败
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");      //回显错误输入还未学到，待优化
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         break;
   }

   printf("Enter second number:");
   while(1){
      if(scanf("%f",&f_num_2) != 1){
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         break;
   }

   result = f_num_1 + f_num_2;
   printf("%.2f + %.2f = %.2f\n",f_num_1,f_num_2,result);
}

void subtract(void){
   float f_num_1, f_num_2;
   float result;

   printf("Enter first number:");
   while(1){
      if(scanf("%f",&f_num_1) != 1){
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         break;
   }

   printf("Enter second number:");
   while(1){
      if(scanf("%f",&f_num_2) != 1){
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         break;
   }

   result = f_num_1 - f_num_2;
   printf("%.2f - %.2f = %.2f\n",f_num_1,f_num_2,result);
}

void multiply(void){
   float f_num_1, f_num_2;
   float result;

   printf("Enter first number:");
   while(1){
      if(scanf("%f",&f_num_1) != 1){
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         break;
   }

   printf("Enter second number:");
   while(1){
      if(scanf("%f",&f_num_2) != 1){
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         break;
   }

   result = f_num_1 * f_num_2;
   printf("%.2f * %.2f = %.2f\n",f_num_1,f_num_2,result);
}

void divide(void){
   float f_num_1, f_num_2;
   float result;

   printf("Enter first number:");
   while(1){
      if(scanf("%f",&f_num_1) != 1){
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         break;
   }

   printf("Enter second number:");
   while(1){
      if(scanf("%f",&f_num_2) != 1){
         while(getchar() != '\n')     //scanf读取失败，字母留在缓冲区没有被取走，死循环，需要清空缓冲区这一行
            ;
         printf("It is not an number.\n");
         printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
         continue;
      }
      else
         if(f_num_2 == 0){    //除数不能为 0
            printf("Enter a number other than 0:");
            continue;
         }
         break;
   }

   result = f_num_1 / f_num_2;
   printf("%.2f / %.2f = %.2f\n",f_num_1,f_num_2,result);
}