/**
 * 邻接矩阵图的函数实现
 */
#include <stdio.h>
#include "AdjMatrixGraph.h"

/**
 * 创建邻接矩阵图
 * @param graph [description]
 */
void Create(MatrixGraph *graph) {
  int i, j, k, weight;
  char start, end; //边的起始顶点

  printf("输入各顶点信息：\n");
  for(i=0;i<graph->vertexNum;i++) {
    getchar(); //暂停输入
    printf("第%d个顶点\n", i+1);
    scanf("%c", &(graph->vertex[i]));
  }

  printf("输入构成各边的两个顶点及权值(用逗号隔开):\n");

  for(k=0;k<graph->edgeNum;k++) {
    getchar();
    printf("第%d条边\n", k+1);
    scanf("%c,%c,%d", &start,&end,&weight);
    for(i=0;start!=graph->vertex[i];i++); //查找起点
    for(j=0;end!=graph->vertex[j];j++); //查找终点
    graph->edges[i][j] = weight;
    if(graph->graphType==0)
      graph->edges[j][i] = weight;

  }
}

/**
 * 输出邻接矩阵图
 * @param graph [description]
 */
void OutPut(MatrixGraph *graph) {
  int i, j;
  //在第一行输出顶点信息
  for(i=0;i<graph->vertexNum;i++)
    printf("\t%c", graph->vertex[i]);

  printf("\n");
  for(i=0;i<graph->vertexNum;i++) {
    printf("%c", graph->vertex[i]);

    for(j=0;j<graph->vertexNum;j++) {
      if(graph->edges[i][j]==MAXVALUE)
        printf("\t ∞"); //输出无穷大
      else
        printf("\t%d", graph->edges[i][j]); //输出权值
    }
    printf("\n");
  }
}
