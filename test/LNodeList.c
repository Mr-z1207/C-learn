#include <stdio.h>
#include <stdlib.h>

typedef struct LNODE
{
    int data;
    struct LNODE *next;
} LNode;

LNode *creatLNode()
{
    LNode *p = (LNode *)malloc(sizeof(LNode));

    LNode *temp = p;
    for (int i = 1; i < 5; ++i)
    {
        LNode *a = (LNode *)malloc(sizeof(LNode));
        a->data = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

int main()
{
    LNode *L = creatLNode();

    printf("%d", L->next->data);

    // while ()
    // {
    //     /* code */
    // }
    

    return 0;
}