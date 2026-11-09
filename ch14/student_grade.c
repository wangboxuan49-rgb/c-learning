/* 功能:学生成绩信息
   作者:wbx
   日期:2026-10-06 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define GRADESIZE 3
#define CSIZE 4
#define NAMESIZE 10

struct name {
   char * first_name;      //用指针代替数组
   char * last_name;
};

struct student {
   struct name * full_name;
   double grade[GRADESIZE];
   double average;
};

bool getinfo(struct student * p);      //分配内存
double average_calculate(struct student * p);
void cleanup(struct student * p);      //释放内存
void show(struct student * p);
char * s_gets(char * st, int n);

int main(){
   struct student person[CSIZE];
   int count = 0;
   bool is_exit = false;
   double sum_grade = 0;

   while(count < CSIZE){
      is_exit = getinfo(&person[count]);
      if(is_exit){      //判断用户是否想要退出程序
         cleanup(&person[count]);      //提前退出之后要清理 getinfo 分配的内存
         break;
      }

      person[count].average = average_calculate(&person[count]);
      sum_grade +=person[count].average; 

      count ++;
   }
   
   if(count > 0){
      printf("学生姓名 第一门成绩 第二门成绩 第三门成绩 平均分\n");
      for(int i = 0; i < count; i ++){
         show(&person[i]);
         cleanup(&person[i]);    //用于清理已经存入信息的内存
      }
      printf("班级的平均分为 %.2f\n",sum_grade / count);
   }
   else{
      printf("没有学生成绩信息\n");
   }

   printf("程序结束\n");
   
   return 0;
}

bool getinfo(struct student * p){
   bool is_exit = false;

   p->full_name = malloc(sizeof(struct name));     //先给外层嵌套分配内存，否则这个就是野指针，存着垃圾值
   if (p->full_name == NULL) {
      return true;
   }
   p->full_name->first_name = NULL;   // 加了这两行,cleanup 就能安全跑,不会释放未知内存
   p->full_name->last_name  = NULL;

   printf("请输入学生姓氏：（输入回车退出）\n");
   p->full_name->last_name = (char *)malloc((NAMESIZE + 1) * sizeof(char));
   if (p->full_name->last_name == NULL) {
      return true;                        // 分配失败，直接当"退出"处理
   }
   if(s_gets(p->full_name->last_name, NAMESIZE + 1) == NULL || p->full_name->last_name[0] == '\0'){
      is_exit = true;
      return is_exit;
   }
   printf("请输入学生名字：\n");
   p->full_name->first_name = (char *)malloc((NAMESIZE + 1) * sizeof(char));
   if (p->full_name->first_name == NULL) {
      return true;                        // 分配失败，直接当"退出"处理
   }
   if (s_gets(p->full_name->first_name, NAMESIZE + 1) == NULL) {
      return true;
   }

   for(int i = 0; i < GRADESIZE; i ++){
      int ch;
      int ret;

      printf("请输入第 %i 门成绩：（总共三门）\n",i+1);
      while((ret = scanf("%lf",&p->grade[i])) != 1){
         if(ret == EOF){
            is_exit = true;
            return is_exit;
         }
         printf("非法输入，请重新输入第 %i 门成绩：（总共三门）\n",i+1);
         while ((ch = getchar()) != '\n' && ch != EOF) { //溢出输入丢弃
            continue;
         }
      }
   }

   return is_exit;
}

double average_calculate(struct student * p){
   double result = 0;
   double sum = 0;

   for(int i = 0; i < GRADESIZE; i ++){
      sum += p->grade[i];
   }
   result = sum / GRADESIZE;

   return result;
}

void cleanup(struct student * p){
   if (p->full_name == NULL) {
      return;
   }

   free(p->full_name->first_name);
   free(p->full_name->last_name);
   free(p->full_name);

   p->full_name = NULL;      // 清空,下次调用直接返回，防止二次释放内存

   return;
}

void show(struct student * p){
   printf("%-10s%s",p->full_name->last_name, p->full_name->first_name);
   for(int i = 0; i < GRADESIZE; i ++){
      printf("%8.2f",p->grade[i]);
   }
   printf("%8.2f\n",p->average);
   
   return;
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
         while((ch = getchar()) != '\n' && ch != EOF){    //如果一行输入一直没有回车，缓冲区大概率会溢出，把溢出的全部丢弃
            continue;
         }
      }
   }

   return ret_val;
}