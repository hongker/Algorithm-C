/**
 * 求最短路径
 */
void Dijkstra(MatrixGraph graph) {
  int weight[VERTEX_MAX]; //源点到各顶点的最短路径长度
  int path[VERTEX_MAX]; //源点到终点经过的顶点集合
  int tempVertex[VERTEX_MAX]; //最短路径的终点集合

  int i, j, k, v0, min;

  printf("\n请输入源点的编号:");
  scanf("%d", &v0);

  v0--;

  for(i=0;i<graph.vertexNum;i++) {
    weight[i] = graph.edges[v0][i];
    if(weight[i]<MAXVALUE && weight[i]>0)
      path[i] = v0;
    tempVertex[i] = v0;
  }

  tempVertex[v0] = 1;
  weight[v0] = 0;

  for(i=0;i<graph.vertexNum;i++) {
    min = MAXVALUE;
    k = v0;
    for(j=0;j<graph.vertexNum;j++) {
      if(tempVertex[j]==0 && weight[j]<min) {
        min = weight[j];
        k = j;
      }
    }

    tempVertex[k] = 1;
    for(j=0;j<graph.vertexNum;j++) {
      if(tempVertex[j]==0 && weight[k]+graph.edges[k][j]<weight[j]) {
        weight[j] = weight[k]+graph.edges[k][j];
        path[j] = k;
      }
    }
  }

  printf("\n顶点%c到各顶点的最短路径为(终点 < 源点):\n",graph.vertex[v0] );

  for(i=0;i<graph.vertexNum;i++) {
    if(tempVertex[i]==1) {
      k = i;
      while (k!=v0) {
        j = k;
        printf("%c < ", graph.vertex[k]);
        k = path[k];
      }
      printf("%c\n", graph.vertex[k]);
    }else {
      printf("%c<-%c没有路径\n", graph.vertex[i],graph.vertex[v0]);
    }
  }
}
