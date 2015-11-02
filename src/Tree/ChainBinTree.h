/**
 * 二叉树(链式)
 */
#ifndef SIZE
#define SIZE 50
#endif

#ifndef ElemType
#define ElemType char
#endif

typedef struct ChainTree{
  ElemType data;
  struct ChainTree *left;
  struct ChainTree *right;
} ChainBinTree;

ChainBinTree *Init(ChainBinTree *node); //初始化二叉树根结点
int Add(ChainBinTree *bt, ChainBinTree *node, int type); //添加数据到二叉树
ChainBinTree *Left(ChainBinTree *bt); //获取左子树
ChainBinTree *Right(ChainBinTree *bt); //获取右子树
int IsEmpty(ChainBinTree *bt); //判断二叉树是否为空
int Depth(ChainBinTree *bt); //获取二叉树的深度
ChainBinTree *Search(ChainBinTree *bt,ElemType elem); //查找值为elem的结点
void Clear(ChainBinTree *bt); //清空二叉树
