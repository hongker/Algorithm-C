/**
 * Prim算法查找最小生成树
 */
#include <stdio.h>

#define USED 0
#define NOADJ -1
/**
 * 查找最小生成树
 * @param graph [description]
 */
void Prim(MatrixGraph graph) {
  int i, j, k, min, sum = 0;
  int weight[VERTEX_MAX]; //保存权值
  char tempVertex[VERTEX_MAX]; //保存临时顶点

  for(i=1;i<graph.vertexNum;i++) { //保存邻接矩阵中的一行数据
    weight[i] = graph.edges[0][i];
    if(weight[i]==MAXVALUE)
      tempVertex[i] = NOADJ; //表示非邻接顶点
    else
      tempVertex[i] = graph.vertex[0];
  }

  tempVertex[0] = USED;
  weight[0] = MAXVALUE;

  for(i=1;i<graph.vertexNum;i++) {
    min = weight[i]; //最小权值
    k = i;
    for(j=1;j<graph.vertexNum;j++) {
      if(weight[j]<min && tempVertex[j] != 0) { //找出最小权值
        min = weight[j];
        k = j;
      }
    }

    sum += min; //累加权值
    printf("(%c,%c),", tempVertex[k],graph.vertex[k]); //输出生成树的一条边
    tempVertex[k] = USED;
    weight[k] = MAXVALUE; //已使用顶点的权值设为最大值

    for(j=0;j<graph.vertexNum;j++) { //重新选择权值最小边
      if(graph.edges[k][j]<weight[j] && tempVertex[j]!=0) {
        weight[j] = graph.edges[k][i];
        tempVertex[j] = graph.vertex[k];
      }
    }
  }

  printf("最小生成树的总权值为：%d\n", sum);
}
