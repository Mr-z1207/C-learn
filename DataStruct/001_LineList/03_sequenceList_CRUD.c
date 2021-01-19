#include <stdio.h>
//导入 stdbool.h 来使用布尔类型
#include <stdbool.h>

#define MaxSize 10
typedef struct
{
   int data[MaxSize];
   int length;
}SqList;

// 初始化顺序表函数
void InitSqList(SqList *L){
    for(int i = 0; i < MaxSize; i++)
        L->data[i] = 0;
    L->length = 0;
}

void PrintList(SqList L){
    for(int i = 0; i < L.length; i++)
        printf("data[%d] = %d \n", i, L.data[i]);
    printf("结束 \n\n");
}

/* 函数名：ListInsert
*  作用：  在第i个位置，插入元素e
*  参数：  SqList *L： 待操作顺序表
*          int i： 插到第i个位置
*          int e： 插入元素
*  返回值： 无
*/
bool ListInsert(SqList *L, int i, int e){
    // 判断i取值范围是否合理
    if(i < 1 || i > L->length +1)
        return false;
    // 判断顺序表是否已满
    if(L->length >= MaxSize)
        return false;
    // i之后的元素向后移动一位
    for(int k = L->length; k >= i; k--)
        L->data[k] = L->data[k-1];
    // 第i个位置加入e
    L->data[i-1] = e;
    // 长度加一
    L->length += 1;
    return true;
}

/* 函数名：ListDelet
*  作用：  在第i个位置，插入元素e
*  参数：  SqList *L： 待操作顺序表
*          int i： 插到第i个位置
*          int e： 插入元素
*  返回值： 无
*/
bool ListDelet(SqList *L, int i, int *e){
    // 判断i取值范围是否合理
    if(i < 1 || i > L->length)
        return false;
    // 将删除的值存在e上
    *e = L->data[i-1];
    // i之后的元素向后移动一位
    for(int k = i; k < L->length; k++)
        L->data[k-1] = L->data[k];
    // 长度减一
    L->length -= 1;
    return true;
}

/* 函数名：GetElem
*  作用：  查找第i个位置的元素
*  参数：  SqList L： 待查找顺序表
*          int i： 第i个位置
*  返回值： 元素值
*/
int GetElem(SqList L, int i){
    return L.data[i-1];
}

/* 函数名：GetElemForValue
*  作用：  按值查找
*  参数：  SqList L： 待查找顺序表
*          int i： 查找的值
*  返回值： 元素索引序号
*/
int GetElemForValue(SqList L, int i){
    int e = -1;
    for(int k = 0; k < L.length; k++){
        if (L.data[k] == i){
            e = k;
        }
    }
    return e;
}

// 主函数
int main(){
    SqList L;
    // 初始化顺序表
    InitSqList(&L);

    // 插入元素
    ListInsert(&L, 1, 2);

    // 插入元素
    ListInsert(&L, 2, 5);

    PrintList(L);

    // 插入元素
    ListInsert(&L, 2, 8);

    PrintList(L);

    // 删除元素
    int e = -1;  // 用来存放删除的数据
    if(ListDelet(&L, 2, &e))
        printf("删除成功，删除了 %d \n", e);
    else
        printf("删除失败");
    
    PrintList(L);

    // 查找元素
    // --按位查找
    printf("按位查找结果：%d \n", GetElem(L, 2));
    // --按值查找
    printf("按值查找结果：%d \n", GetElemForValue(L, 2));

    return 0;
}
