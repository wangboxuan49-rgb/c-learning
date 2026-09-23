/* 功能:统计字符数
   作者:wbx
   日期:2026-09-23 */

#include <stdio.h>
#include <ctype.h>

int main(void){
   int ch;           //char 类型只能表示 0～255 无符号整数，但是 EOF 的值是 -1，并且 getchar（）实际返回值类型是 int
   int count = 0;
   int upper_count = 0;
   int lower_count = 0;

   //当文件结尾时停止，mac 用 control+D，win 用control+Z，默认为行缓冲，终端识别到换行符才提交，直到缓冲区为空才可以到达 EOF
   while((ch = getchar()) != EOF){    
      if(ch != '\n'){    //不把换行符计入
         count ++;
         if(isupper(ch) == 1)
            upper_count ++;
         else if(islower(ch) == 1)
            lower_count ++;
      }
   }
   printf("\nTotal number of character is %d\n",count);
   printf("Total number of upper character is %d\n",upper_count);
   printf("Total number of lower character is %d\n",lower_count);

   return 0;
}