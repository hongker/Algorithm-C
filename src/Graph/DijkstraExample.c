/**
 * 最短路径算法使用示例
 */
#include <stdio.h>
#include "AdjMatrixGraph.h"
#include "Dijkstra.c"

int main() {
  MatrixGraph graph;
  int path[VERTEX_MAX];
  int i, j;
  char select;

  do {
    printf("输入生成图的类型(0:无向图，1：有向图)：");
    scanf("%d", &graph.graphType);

    printf("输入图的顶点数量和边数量(n,m)：");
    scanf("%d,%d", &graph.vertexNum,&graph.edgeNum);

    for(i=0;i<graph.vertexNum;i++)
      for(j=0;j<graph.vertexNum;j++)
        graph.edges[i][j] = MAXVALUE;

    Create(&graph);
    printf("邻接矩阵数据如下：\n");
    OutPut(&graph);

    printf("最短路径：\n");
    Dijkstra(graph);

    printf("图遍历完毕，是否要继续？Y/N: \n");
    getchar();
    scanf("%c", &select);
  }while(select !='N' && select != 'n');

  return 0;
}
