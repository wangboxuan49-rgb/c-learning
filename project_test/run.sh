#!/bin/bash
# 一键编译并运行 project_test（多文件项目）
clang -Wall -Wextra *.c -o caculator && ./caculator
