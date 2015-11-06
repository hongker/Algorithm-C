/**
 * 邻接表存储图
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef MAX
#define MAX 20
#endif

typedef struct edgeNode {
  int vertex; //顶点序号
  int weight; //权值
  struct edgeNode * next; //指向有边的下一个顶点
} EdgeNode;

typedef struct {
  EdgeNode * AdjList[MAX]; //指向每个顶点的指针数组
  int vertexNum, edgeNum; //顶点数量，边数量
  int graphType; //图的类型(0:无向图，1：有向图)
} ListGraph;

void Create(ListGraph *graph); //创建
void OutPut(ListGraph *graph); //输出
