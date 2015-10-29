/**
 * 队列相关操作函数实现(顺序线性表)
 * @author hongker
 * @version 1.0
 */
#include "SeqQueue.h"
#include <stdio.h>

/**
 * 队列初始化
 * @return [description]
 */
SeqQueue *Init() {
  printf("队列初始化......\n");

  SeqQueue *queue;
  if(queue=(SeqQueue *)malloc(sizeof(SeqQueue))) {
    queue->head = 0; //设置队头
    queue->tail = 0; //设置队尾
    return queue;
  }else {
    printf("队列初始化分配空间失败......\n");
    return NULL;
  }
}

/**
 * 判断队列是否为空
 * @param  Queue [description]
 * @return       [description]
 */
int IsEmpty(SeqQueue *Queue) {
  return (Queue->head==Queue->tail);
}

/**
 * 判断队列是否已满
 * @param  Queue [description]
 * @return       [description]
 */
int IsFull(SeqQueue *Queue) {
  return (Queue->tail==QUEUEMAX);
}

/**
 * 获取队列长度
 * @param  Queue [description]
 * @return       [description]
 */
int Length(SeqQueue *Queue) {
  return (Queue->tail-Queue->head);
}

/**
 * 元素入列
 * @param  Queue [description]
 * @param  elem  [description]
 * @return       [description]
 */
int GetIn(SeqQueue *Queue, ElemType elem) {
  printf("元素入列......\n");
  if(Queue->tail==QUEUEMAX) {
    printf("队列已满......\n");
    return -1;
  }

  Queue->data[Queue->tail] = elem;
  Queue->tail++;
  return 0;
}

/**
 * 元素出列
 * @param  Queue [description]
 * @return       [description]
 */
ElemType * GetOut(SeqQueue *Queue) {
  printf("元素出列......\n");

  if(Queue->head==Queue->tail) {
    printf("队列已空......\n");
    return NULL;
  }

  //返回指向队头元素的指针，并修改队头序号
  /**
   * ElemType *elem;
   * elem = &(Queue->data[Queue->head]);
   * Queue->head++;
   * return elem;
   */
  return &(Queue->data[Queue->head++]);
}

/**
 * 获取队列头部元素
 * @param  Queue [description]
 * @return       [description]
 */
ElemType * Peek(SeqQueue *Queue) {
  if(Queue->head==Queue->tail) {
    printf("队列已空......\n");
    return NULL;
  }

  return &(Queue->data[Queue->head]);
}
