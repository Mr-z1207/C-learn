#include <stdio.h>
#include <stdlib.h>

// 一、顺序表的定义
// 定义默认初始长度
#define InitSize 10

// 定义结构体
typedef struct
{
   // 定义一个数组指针
   int *data;
   // 定义数组最大长度变量
   int MaxSize;
   // 定义一个存储当前长度的变量
   int length;
}SqList;

// 初始化顺序表函数
void InitSqList(SqList *L){
    // malloc ： 分配一片空间；参数是空间大小
    // (int *)强制类型转换，将malloc返回的指针转换成定义的数组的类型
    L->data = (int *)malloc(sizeof(int) * InitSize);
    // 最大长度 = 初始长度
    L->MaxSize = InitSize;
    // 默认长度归零;
    L->length = 0;
}

// 动态增加顺序表长度
void IncreaseSize(SqList *L, int size){
    // 将旧空间指针备份
    int *p = L->data;
    // L里的指针换成新分配的空间的指针
    L->data = (int *)malloc(sizeof(int) * (L->MaxSize + size));
    // 从旧空间中把数据复制到新空间
    for(int i = 0; i < L->length; i++)
        L->data[i] = p[i];
    // 更改最大长度
    L->MaxSize = L->MaxSize + size;
    // 释放旧空间
    free(p);
}

// 主函数
int main(){
    // 定义一个顺序表数据
    SqList L;
    // 初始化顺序表（将内存清零、长度归零）
    InitSqList(&L);
    printf("L.MaxSize = %d \n", L.MaxSize);

    // 增加长度
    IncreaseSize(&L, 5);
    printf("L.MaxSize = %d \n", L.MaxSize);

    return 0;
}