//头文件，放函数声明（函数长什么样）

//头文件守卫,防止同一个头文件被重复包含两次导致重复定义错误
#ifndef MYMATH_H        // 如果没定义过 MYMATH_H
#define MYMATH_H        // 就定义它
void add(void);
void subtract(void);
void multiply(void);
void divide(void);

#endif                   // 结束守卫