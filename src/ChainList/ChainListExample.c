/**
 * 链式线性表使用示例
 * @author hongker
 * @version 1.0
 */
#include <stdlib.h>
#include <stdio.h>
#include "ChainList.h"

int main() {
  ChainList *node, *head = NULL;

  head = AddHead(head, 1);

  printf("链表长度：%d\n", Length(head));

  head = AddEnd(head,2);

  printf("链表长度：%d\n", Length(head));

  ChainList *target;
  ElemType elem = 2;
  target = Search(head,elem);
  if(target!=NULL) {
    printf("在链表中找到了为%d的元素\n", elem);
  }else {
    printf("在链表中没有找到为%d的元素\n", elem);
  }

  head = AddEnd(head,4);
  Insert(head, 2, 3);
  printf("链表长度：%d\n", Length(head));

  Delete(head,2);
  printf("链表长度：%d\n", Length(head));
  return 0;
}
