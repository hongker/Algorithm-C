/**
 * 队列使用示例
 * @author hongker
 * @version 1.0
 */
#include <stdio.h>
#include "SeqQueue.h"

int main() {
  SeqQueue *queue;
  queue = Init();

  ElemType elem;
  elem.name = 'A';
  elem.age = 20;
  GetIn(queue, elem);
  printf("队列长度:%d\n", Length(queue));

  if(IsEmpty(queue)) {
    printf("队列为空......\n");
  }else {
    printf("队列非空......\n");
  }

  ElemType * head;
  head = Peek(queue);
  printf("队列头部元素名称：%c，年龄：%d\n", head->name,head->age);
  printf("队列长度:%d\n", Length(queue));

  ElemType *out;
  out = GetOut(queue);
  printf("出列元素名称：%c，年龄：%d\n", out->name,out->age);

  if(IsFull(queue)) {
    printf("队列已满......\n");
  }else {
    printf("队列未满......\n");
  }

  printf("队列长度:%d\n", Length(queue));
  return 0;
}
