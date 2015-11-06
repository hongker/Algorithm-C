/**
 * 邻接表存储图使用示例
 */
#include "AdjListGraph.h"

int main() {
  ListGraph graph;
  printf("输入生成图的类型(0：无向图，1：有向图): ");
  scanf("%d" , &graph.graphType);

  printf("输入顶点数量和边数量：");
  scanf("%d,%d", &graph.vertexNum, &graph.edgeNum);

  printf("输入构成各边的两个顶点及权值(用逗号隔开):\n");

  Create(&graph);

  printf("输出的邻接表：\n");
  OutPut(&graph);
  return 0;
}
