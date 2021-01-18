#include <stdio.h>

// 一、顺序表的定义
// 定义默认最大长度
#define MaxSize 10

// 定义结构体
typedef struct
{
   // 定义一个数组
   int data[MaxSize];
   // 定义一个存储长度的变量
   int length;
}SqList;

// 初始化顺序表函数
void InitSqList(SqList *L){
    for(int i = 0; i < MaxSize; i++)
        L->data[i] = 0;
    L->length = 0;
}


// 主函数
int main(){
    // 定义一个顺序表数据
    SqList L;
    // 初始化顺序表（将内存清零、长度归零）
    InitSqList(&L);

    return 0;
}
