/**
 * 邻接表存储图的函数实现
 */
#include <stdio.h>
#include "AdjListGraph.h"

/**
 * 创建邻接表结构图
 * @param graph [description]
 */
void Create(ListGraph *graph) {
  int i, weight;
  int start, end;
  EdgeNode *s;

  for(i=1;i<=graph->vertexNum;i++)
    graph->AdjList[i] = NULL;

  for(i=1;i<=graph->edgeNum;i++) {
    getchar();
    printf("第%d条边:",i);
    scanf("%d,%d,%d", &start,&end,&weight); //输入边的起点，终点，权值

    s = (EdgeNode *)malloc(sizeof(EdgeNode));

    s->next = graph->AdjList[start]; //插入到邻接表中
    s->weight = weight;
    s->vertex = end;  //  保存终点编号
    graph->AdjList[start] = s; //邻接表对应顶点指向该点

    if(graph->graphType==0) { //如果是无向图，再插入到终点的边
      s = (EdgeNode *)malloc(sizeof(EdgeNode));
      s->next = graph->AdjList[end];
      s->vertex = start;
      s->weight = weight;
      graph->AdjList[end] = s;
    }
  }

}

/**
 * 输出
 * @param graph [description]
 */
void OutPut(ListGraph *graph) {
  int i;
  EdgeNode *s;
  for(i=1;i<=graph->vertexNum;i++) {
    printf("顶点%d", i);
    s = graph->AdjList[i];
    while (s) {
      printf("->%d(%d)", s->vertex,s->weight);
      s = s->next;
    }
    printf("\n");
  }
}
