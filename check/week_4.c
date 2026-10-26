/* 功能:第四周验收
   作者:wbx
   日期:2026-10-04 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
   int cap = 4;
   char ** p = (char **)malloc(cap * sizeof(char *));
   int ch = 0;    //getchar() 的返回值是 int
   char temp[50];
   int i = 0;
   int count = 0;    //行数应从零开始，因为结尾提交缓冲区是也要一个换行，从一开始会在空输入时显示有一行输入

   printf("请输入若干行文本（输入 ctrl+D 停止输入）：");

   while((ch = getchar()) != EOF){
      if (i < (int)sizeof(temp) - 1) {    //防止超长行溢出，溢出的直接丢弃
         temp[i] = ch;
         i ++;
      }

      if(ch == '\n'){
         if(count == cap){
            int newcap = cap * 2;      //只要到边界，就会翻倍扩容
            char ** bigger = (char **)malloc(newcap * sizeof(char *));

            for(int x = 0; x < count; x ++){     //将原先指针搬过来
               bigger[x] = p[x];
            }
            free(p);    //销毁原先指针数组，按分配顺序反向释放内存的意思是，先释放内层再释放外层，两个不同名称的不用按顺序
            p = bigger;    //后续用新指针接续，把 bigger 里那个地址复制一份给 p,从此两个指针指向同一块内存
            cap = newcap;
         }
         temp[i] = '\0';
         p[count] = (char *)malloc(strlen(temp) * sizeof(char) + 1);
         //p[count] = temp;      错误！代码意思是将 p[i]指针指向 temp 数组首地址了，C 里的 = 对数组和指针永远只搬地址,从不搬内容。字符串复制只能靠函数
         strcpy(p[count], temp);      //从临时数组里把字符串存进新开辟的地址
         temp[0] = '\0';      //临时数组从头开始
         i = 0;
         count ++;      //总行数计数
      }
   }
   if(i > 0){        //解决输入最后一行没有换行符会丢
      temp[i] = '\0';          // 残余字符封口
      if(count == cap){        // 和循环里一样:判满、扩容、搬指针
         int newcap = cap * 2;
         char ** bigger = (char **)malloc((size_t)newcap * sizeof(char *));
         for(int x = 0; x < count; x++) bigger[x] = p[x];
         free(p);
         p = bigger;    //后续用新指针接续，把 bigger 里那个地址复制一份给 p,从此两个指针指向同一块内存
         cap = newcap;
      }
      p[count] = (char *)malloc(strlen(temp) + 1);
      strcpy(p[count], temp);
      count ++;
   }

   printf("一共有 %d 行\n",count);

   for (int k = 0; k < count; k++) {
      printf("%s", p[k]);
   }

   for (int k = 0; k < count; k++) {
      free(p[k]);                     //先释放每一行的内容
   }
   free(p);          //最后释放最终指针数组本体，free 认的是当时指针里的那个地址,不认变量名，所以可以释放扩容之后数组
   //不能再 free（bigger）了，要不然会把同一内存释放两次
   
   return 0;
}