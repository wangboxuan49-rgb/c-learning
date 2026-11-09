/* 功能:垒球队信息（文本文件）
   作者:wbx
   日期:2026-10-06 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMESIZE 20
#define TEAMSIZE 19

struct name {
   char first_name[NAMESIZE];
   char last_name[NAMESIZE];
};

struct player_info {
   int team_num;             // 球员号
   struct name full_name;
   int    at_bats;           // 上场次数
   int    hits;              // 击中数
   int    walks;             // 走垒数 
   int    rbi;               // 打点 
   double batting_average;   // 安打率 = hits / at_bats
   int used;                 // 是否有信息记录
};

double batting_average_calculate(double hits, double at_bats);
void show(struct player_info * player);

int main(void){
   struct player_info player[TEAMSIZE] = {0};      //全部清零
   FILE * fp = fopen("baseball.txt", "r");
   if (fp == NULL) {
      fprintf(stderr, "打不开 baseball.txt\n");
      return EXIT_FAILURE;    //定义在<stdlib.h>里
   }

   char line[128];
   while(fgets(line, sizeof(line), fp) != NULL){
      int temp_team_num, temp_at_bats, temp_hits, temp_walks, temp_rbi;
      char temp_first_name[NAMESIZE], temp_last_name[NAMESIZE];

      if(sscanf(line, "%d %19s %19s %d %d %d %d", &temp_team_num, temp_first_name, temp_last_name, 
         &temp_at_bats, &temp_hits, &temp_walks, &temp_rbi) != 7){
            printf("已跳过格式不对的行\n");
            continue;
      }
      if(temp_team_num < 0 || temp_team_num >= TEAMSIZE){
         printf("跳过非法球员号 %d：%s", temp_team_num, line);
         continue;
      }

      player[temp_team_num].team_num = temp_team_num;
      //player[temp_team_num].full_name.last_name = temp_last_name;        //数组不可以直接赋值
      //player[temp_team_num].full_name.first_name = temp_first_name;
      strcpy(player[temp_team_num].full_name.last_name, temp_last_name);    //数组成员一律 strcpy/snprintf 拷内容
      strcpy(player[temp_team_num].full_name.first_name, temp_first_name);
      player[temp_team_num].at_bats += temp_at_bats;
      player[temp_team_num].hits += temp_hits;
      player[temp_team_num].walks += temp_walks;
      player[temp_team_num].rbi += temp_rbi;
      player[temp_team_num].used = 1;
   }

   printf("%-4s%-15s%6s%6s%6s%6s%8s\n", "号", "姓名", "上场", "击中", "走垒", "打点", "安打率");
   for(int i = 0; i < TEAMSIZE; i ++){
      if(player[i].used != 1){
         printf("未找到第 %d 号球员记录\n",i);
         continue;
      }
      player[i].batting_average = batting_average_calculate(player[i].hits, player[i].at_bats);
      show(&player[i]);
   }

   fclose(fp);
   
   return 0;
}

double batting_average_calculate(double hits, double at_bats){
   double batting_average;
   
   if(at_bats == 0){
      return 0.00;
   }

   batting_average = hits / at_bats;

   return batting_average;
}

void show(struct player_info * p){
   printf("%d %s %s %d %d %d %d %.2f\n",p->team_num,p->full_name.first_name,p->full_name.last_name,p->at_bats,
      p->hits,p->walks,p->rbi,p->batting_average);
   
   return;
}