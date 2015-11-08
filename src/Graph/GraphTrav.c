/**
 * 图的遍历
 */
#include <stdio.h>
#include "AdjMatrixGraph.h"

#ifndef QUEUE_MAX
#define QUEUE_MAX 30
#endif

typedef struct {
  int data[QUEUE_MAX]; //数据域
  int head; //队首指针
  int tail; //队尾指针
} SeqQueue;

/**
 * 队列初始化
 * @param queue [description]
 */
void QueueInit(SeqQueue *queue) {
  queue->head = queue->tail = 0;
}

/**
 * 判断队列是否为空
 * @param  queue [description]
 * @return       [description]
 */
int QueueIsEmpty(SeqQueue *queue) {
  return (queue->head==queue->tail);
}

int QueueIn(SeqQueue *queue, int ch) {
  if((queue->tail+1)%QUEUE_MAX == queue->head) {
    printf("队列已满!\n");
    return 0;
  }

  queue->data[queue->tail] = ch;
  queue->tail = (queue->tail+1) % QUEUE_MAX;
  return 1;
}

int QueueOut(SeqQueue *queue, int *ch) {
  if(queue->head==queue->tail) {
    printf("队列为空!\n");
    return 0;
  }

  *ch = queue->data[queue->head];
  queue->head = (queue->head+1) % QUEUE_MAX;
  return 1;

}

/**
 * 广度优先遍历
 * [BFSTraverse description]
 * @param graph [description]
 */
 void BFSM(MatrixGraph *graph, int k) {

   int i, j;
   SeqQueue queue;
   QueueInit(&queue);
   graph->isTrav[k] = 1;

   printf("->%c", graph->vertex[k]);

   QueueIn(&queue, k);

   while (!QueueIsEmpty(&queue)) {
     QueueOut(&queue, &i);
     for(j=0;j<graph->vertexNum;j++) {
       if(graph->edges[i][j]!=MAXVALUE && !graph->isTrav[j]) {
         printf("->%c", graph->vertex[j]);
         graph->isTrav[j] = 1;
         QueueIn(&queue, j);
       }
     }
   }
 }

void BFSTraverse(MatrixGraph *graph) {
  int i;
  for(i=0;i<graph->vertexNum;i++)
    graph->isTrav[i] = 0;

  printf("广度优先遍历结点:\n");
  for(i=0;i<graph->vertexNum;i++)
    if(!graph->isTrav[i])
      BFSM(graph, i);

  printf("\n");
}



/**
 * 深度优先遍历
 * @param graph [description]
 */
 void DFSM(MatrixGraph *graph, int i) {
   int j;
   graph->isTrav[i]= 1;
   printf("->%c", graph->vertex[i]);

   for(j=0;j<graph->vertexNum;j++) {
     if(graph->edges[i][j]!=MAXVALUE && !graph->isTrav[i]) {
       DFSM(graph, j);
     }
   }
 }

void DFSTraverse(MatrixGraph *graph) {
  int i;
  for(i=0;i<graph->vertexNum;i++)
    graph->isTrav[i] = 0;

  printf("深度优先遍历结点:\n");
  for(i=0;i<graph->vertexNum;i++)
    if(!graph->isTrav[i])
      DFSM(graph, i);

  printf("\n");
}
