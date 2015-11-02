/**
 * 二叉树操作函数使用示例
 */
#include <stdio.h>
#include <stdlib.h>
#include "ChainBinTree.h"

void oper(ChainBinTree *node) {
  printf("%c\n", node->data);
}

/**
 * 初始化根结点
 * @return [description]
 */
ChainBinTree *InitRoot() {
  ChainBinTree *node;
  if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))) {
    printf("输入根结点数据：");
    scanf("%s", &node->data);
    node->left = NULL;
    node->right = NULL;
    return node;
  }
  printf("分配空间失败!\n") ;
  return NULL;
}

/**
 * 为根结点添加子树
 * @param bt [description]
 */
void AddNode(ChainBinTree *bt) {
  ChainBinTree *node, *parent;
  ElemType elem;
  char select;
  if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))) {
    printf("输入二叉树结点数据：");
    fflush(stdin); //清空输入缓冲区
    scanf("%s", &node->data);
    node->left = NULL;
    node->right = NULL;
    printf("输入父结点数据：\n");
    fflush(stdin);
    scanf("%s", &elem);
    parent = Search(bt, elem);

    if(parent) {
      printf("1:添加到左子树，2：添加到右子树\n");
      do {
        select = getchar();
        select -= '0';
        if(select==1||select==2) {
          Add(parent,node,select);
        }
      }while (select!=1&&select!=2) ;
    }else {
      printf("未找到父结点!\n");
      free(node);
      return;
    }
  }
}

int main() {
  ChainBinTree *root = NULL;
  char select;
  void (*oper1)(); //指向函数的指针
  oper1 = oper;
  do {

    printf("\n1.设置二叉树根元素    2.添加二叉树结点\n");
    printf("3.前序遍历    4.中序遍历\n");
    printf("5.后序遍历    6.二叉树深度\n");
    printf("0.退出\n");
    printf("你的选择：");
    select = getchar();
    switch (select) {
      case '1':
        root = InitRoot();
        break;
      case '2':
        AddNode(root);
        break;
      case '3':
        printf("------------------------------\n");
        printf("前序遍历的结果:\n");
        BinTree_DLR(root,oper1);

        printf("------------------------------\n");
        break;
      case '4':
        printf("------------------------------\n");
        printf("中序遍历的结果:\n");
        BinTree_LDR(root,oper1);
        printf("------------------------------\n");
        break;
      case '5':
        printf("------------------------------\n");
        printf("后序遍历的结果:\n");
        BinTree_LRD(root,oper1);
        printf("------------------------------\n");
        break;
      case '6':
        printf("------------------------------\n");
        printf("二叉树的深度为：%d\n", Depth(root));
        printf("------------------------------\n");
        break;
      case '0':
        break;
      }
      getchar(); //抵消 \n
    }while(select!='0');
    Clear(root);
    return 0;

}
