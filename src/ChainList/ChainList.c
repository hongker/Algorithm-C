/**
 * 链式线性表函数实现
 * @author hongker
 * @version 1.0
 */
#include <string.h>
#include <stdio.h>
#include "ChainList.h"

/**
 * 添加元素到链表头部
 * @param  List [description]
 * @param  elem [description]
 * @return      [description]
 */
ChainList *AddHead(ChainList *List, ElemType elem) {
  printf("插入元素到头部...\n");
  ChainList *node;
  if(!(node=(ChainList * )malloc(sizeof(ChainList)))) {
    printf("为保存节点数据申请内存失败...\n");
    return NULL;
  }

  node->data = elem;
  node->next = List;
  List = node;
  printf("元素：%d\n", List->data);
  return List;

}

/**
 * 获取链表长度
 * @param  List [description]
 * @return      [description]
 */
int Length(ChainList *List) {
  int length = 0;
  ChainList *p = List;
  while (p!=NULL) {
    length++;
    p = p->next;
  }
  return length;
}

/**
 * 添加元素到链表尾部
 * @param  List [description]
 * @param  elem [description]
 * @return      [description]
 */
ChainList *AddEnd(ChainList *List, ElemType elem) {
  printf("添加元素到链表尾部......\n");

  ChainList *node; //定义一个节点
  if(!(node=(ChainList *)malloc(sizeof(ChainList)))) {
    printf("动态分配空间失败...\n");
    return NULL;
  }
  node->data = elem;
  node->next = NULL;

  ChainList *p;
  p = List;
  while (p->next!=NULL) {
    p = p->next;
  }
  p->next = node;
  return List;
}

/**
 * 搜索元素
 * @param  List     [description]
 * @param  ElemType [description]
 * @return          [description]
 */
ChainList *Search(ChainList *List, ElemType elem) {
  printf("搜索元素......\n");
  ChainList *p;
  p = List->next;
  while (p->next!=NULL) {
    if(p->data==elem) {
      break;
    }
  }
  return p;
}

/**
 * 插入元素
 * @param  List [description]
 * @param  key  [description]
 * @param  elem [description]
 * @return      [description]
 */
ChainList *Insert(ChainList *List,ElemType key, ElemType elem) {
  printf("插入元素......\n");
  ChainList *node, *p;
  if(!(node=(ChainList *)malloc(sizeof(ChainList)))) {
    printf("动态分配空间失败....");
    return NULL;
  }

  node->data = elem;
  p = Search(List, key); //找到需要插入的元素
  node->next = p->next;
  p->next = node;
  return List;
}

/**
 * 删除元素
 * @param  List [description]
 * @param  elem [description]
 * @return      [description]
 */
int Delete(ChainList *List, ElemType elem) {
  printf("删除元素\n");
  ChainList *q, *p;
  q = p = List;
  while (p->next!=NULL) {
    if(p->data==elem) {
      q->next = p->next;
      free(p);
      break;
    }
    q = p;
    p = p->next;
  }

  return 0;
}
