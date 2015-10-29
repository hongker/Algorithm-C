/**
 * 链式线性表定义
 * @author hongker
 * @version 1.0
 */
#include <stdlib.h>

#ifndef ElemType
#define ElemType int
#endif

typedef struct Node {
    ElemType data;
    struct Node *next;
}ChainList;

ChainList *AddHead(ChainList *List, ElemType elem); //添加元素到头部
int Length(ChainList *List); //获取链表长度
ChainList *AddEnd(ChainList *List, ElemType elem); //添加元素到尾部
ChainList *Search(ChainList *List, ElemType elem); //搜索元素
ChainList *Insert(ChainList *List, ElemType key, ElemType elem); //插入元素
int Delete(ChainList *List, ElemType elem); //删除元素
