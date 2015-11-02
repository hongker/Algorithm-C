/**
 * 二叉树操作函数实现
 */

/**
 * 初始化
 * @param  node [description]
 * @return      [description]
 */
ChainBinTree *Init(ChainBinTree *node) {
  if(node!=NULL)
    return node;

  return NULL;
}

/**
 * 添加数据到二叉树
 * @param bt 父结点
 * @param  node 目标结点
 * @param  type    结点类型(1:添加为左子树，2：添加为右子数)
 * @return      [description]
 */
int Add(ChainBinTree *bt, ChainBinTree *node, int type) {
  if(bt==NULL) {
    printf("父结点不存在!\n");
    return 0;
  }

  switch (n) {
    case 1: //添加到左子树
      if(bt->left) {
        printf("左子树不为空\n");
        return 0;
      }else {
        bt->left = node;
        break;
      }
    case 2: //添加到右子树
      if(bt->right) {
        printf("右子树不为空!\n");
        return 0;
      }else {
        bt->right = node;
        break;
      }
    default:
      printf("参数错误!\n");
      return 0;
  }

  return 1;
}

/**
 * 获取左子树
 * @param  bt [description]
 * @return    [description]
 */
ChainBinTree *Left(ChainBinTree *bt) {
  if(bt) {
    return bt->left;
  }
  printf("结点为空!\n");
  return NULL;
}

/**
 * 获取右子树
 * @param  bt [description]
 * @return    [description]
 */
ChainBinTree *Right(ChainBinTree *bt) {
  if(bt) {
    return bt->right;
  }
  printf("结点为空!\n");
  return NULL;
}

/**
 * 判断二叉树是否为空
 * @param  bt [description]
 * @return    [description]
 */
int IsEmpty(ChainBinTree *bt){
  if(bt==NULL)
    return 1;

  return 0;
}

/**
 * 获取二叉树的深度
 * @param  bt [description]
 * @return    [description]
 */
int Depth(ChainBinTree *bt) {
  int left_depth,right_depth;
  if(bt==NULL)
    return 0;
  else {
    left_depth = Depth(bt->left); //左子树深度，递归求得
    right_depth = Depth(bt->right); //右子树深度，递归求得

    if(left_depth>right_depth) {
      return left_depth+1;
    }else {
      return right_depth+1;
    }
  }
}

/**
 * 查找值为elem的结点
 * @param  bt   [description]
 * @param  elem [description]
 * @return      [description]
 */
ChainBinTree *Search(ChainBinTree *bt,ElemType elem) {
  ChainBinTree *p;
  if(bt==NULL) {
    return NULL;
  }else {
    if(bt->data==elem) {
      return bt;
    }else {
      //分别向左右子树递归查找
      if(p=Search(bt->left,elem)) {
        return p;
      }else if(p=Search(bt->right, elem)) {
        return p;
      }else {
        return NULL;
      }
    }
  }
}

/**
 * 清空二叉树
 * @param bt [description]
 */
void Clear(ChainBinTree *bt) {
  if(bt) {
    Clear(bt->left);
    Clear(bt->right);
    free(bt);
    bt=NULL;
  }
  return;
}
