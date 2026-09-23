/* 功能:四则运算计算器菜单
   作者:wbx
   日期:2026-09-23 */

#include <stdio.h>

void add(void);
void subtract(void);
void multiply(void);
void divide(void);

int main(void){
   int ch;  //避免 EOF

   while(1){
      printf("Enter the operation of your choice:\n"
         "a.add     \ts.subtract\nm.multiply\td.divide\nq.quit\n");  //printf 如果要折行的话每行都要有完整双引号
      ch = getchar();
      
      switch(ch){
         case 'a':
            add();      //可以将输入两个数字功能再抽取出，成为另一个函数，还未学到，待优化
            break;
         case 's':
            subtract();
            break;
         case 'm':
            multiply();
            break;
         case 'd':
            divide();
            break;
         default:
            break;
      }

      if(ch == 'q')
         break;

      //scanf（）函数把换行符留在了输入队列中，getchar（）不会跳过换行符，所以在下一轮迭代的时，还没有输入就读取了换行符   
      while(getchar() != '\n')   //用于跳过无关输入
         continue;
   }

   printf("Bye.\n");

   return 0;
}

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