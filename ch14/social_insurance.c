/* 功能:打印社保号信息
   作者:wbx
   日期:2026-10-06 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUMMAX 10
#define NAMEMAX 10
#define NUM 5

struct name {
   char first_name[NAMEMAX];
   char middle_name[NAMEMAX];
   char last_name[NAMEMAX];
};

struct insurance_info {
   char insurance_num[NUMMAX];
   struct name full_name;        //结构体嵌套，里面需要放一个定义后的结构体变量
};

char * s_gets(char * st, int n);
void show(struct insurance_info st);      //参数为结构体的函数声明要在结构体定义之后

int main(void){
   struct insurance_info insured[NUM];    //定义结构体数组
   int count = 0;

   printf("请输入参保人社会保险号：（输入回车退出）\n");
   while(count < NUM && s_gets(insured[count].insurance_num, NUMMAX) != NULL && insured[count].insurance_num[0] != '\0'){
      printf("请输入参保人名：\n");
      s_gets(insured[count].full_name.first_name, NAMEMAX);
      printf("请输入参保人中间名：（没有可以跳过）\n");
      s_gets(insured[count].full_name.middle_name, NAMEMAX);
      printf("请输入参保人姓氏：\n");
      s_gets(insured[count].full_name.last_name, NAMEMAX);

      count ++;
      if(count < NUM){
         printf("请输入下一个参保人社会保险号：（输入回车退出）\n");
      }
   }

   if(count > 0){
      for(int i = 0; i < count; i ++){
         show(insured[i]);    //遍历结构体数组，把整个结构体传递给整个函数
      }
   }
   else{
      printf("没有参保人信息\n");
   }

   return 0;
}

char * s_gets(char * st, int n){
   char * ret_val;      //返回指针，用于判断输入是否出错
   char * find;
   int ch = 0;

   ret_val = fgets(st, n, stdin);
   if(ret_val != NULL){
      find = strchr(st, '\n');      //在发现换行时自动替换成字符串的结尾
      if(find != NULL){
         *find = '\0';
      }
      else{
         while((ch = getchar()) != '\n'){    //如果一行输入一直没有回车，缓冲区大概率会溢出，把溢出的全部丢弃
            continue;
         }
      }
   }

   return ret_val;
}

void show(struct insurance_info st){
   //toupper 返回值为 int，存回 char 要强转，并且参数必须是 unsigned char 类型，不能传负数
   st.full_name.first_name[0] = (char)toupper((unsigned char)st.full_name.first_name[0]);
   st.full_name.last_name[0] = (char)toupper((unsigned char)st.full_name.last_name[0]);

   if(st.full_name.middle_name[0] != '\0'){
      st.full_name.middle_name[0] = (char)toupper((unsigned char)st.full_name.middle_name[0]);      
      printf("%s, %s %.1s. -- %s\n",st.full_name.last_name,st.full_name.first_name,st.full_name.middle_name,st.insurance_num);
   }
   else{
      printf("%s, %s -- %s\n",st.full_name.last_name,st.full_name.first_name,st.insurance_num);
   }

   return;
}