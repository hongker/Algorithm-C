/**
 * 邻接矩阵图
 */

//图的最大顶点数
#ifndef VERTEX_MAX
#define VERTEX_MAX 20
#endif

#ifndef MAXVALUE
#define MAXVALUE 32767
#endif

typedef struct {
  char vertex[VERTEX_MAX]; //保存顶点信息
  int edges[VERTEX_MAX][VERTEX_MAX]; //保存边的权
  int isTrav[VERTEX_MAX];
  int vertexNum; //顶点数量
  int edgeNum; //边数量
  int graphType; //图的类型:(0:无向图，1：有向图)
} MatrixGraph;
void Create(MatrixGraph *graph); //创建邻接矩阵图
void OutPut(MatrixGraph *graph);  //输出邻接矩阵
