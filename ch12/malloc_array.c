/* 功能:动态创建数组
   作者:wbx
   日期:2026-10-03 */

// pe12-8.c
#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar [], int n);

int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);       //释放之前动态分配的内存
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}

int * make_array(int elem, int val){
    //动态分配内存，返回动态分配内存的首地址
    int * p = (int *)malloc(elem * sizeof(int));        //为 elem 个 int 类型的值申请内存空间，并设置 p 指向该位置
    int i = 0;

    while(i < elem){
        p[i] = val;
        i ++;
    }

    return p;
}

void show_array(const int ar [], int n){
    int i;
    
    for(i = 0; i < n; i ++){
        printf("%d\t",ar[i]);

        if(i % 8 == 7){     //数组每八个元素换行
            printf("\n");
        }
    }
    if(i % 8 != 0){         //用于判断数组最后一行是不是满的（满 8 个元素），不满就补一个换行，防止后续输出黏住
        printf("\n");
    }
    printf("Done.\n");
    
    return;
}