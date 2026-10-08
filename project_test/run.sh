#!/bin/bash
# 一键编译并运行 project_test（多文件项目）
clang -Wall -Wextra *.c -o caculator && ./caculator

# 有新项目的话，就复制 run.sh 到新项目中，并把 caculator 改成需要运行的文件名
# 运行指令为先 cd 进 project 文件夹，再 ./run.sh