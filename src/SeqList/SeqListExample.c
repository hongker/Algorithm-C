/**
 * 顺序线性表使用示例
 * @author hongker
 * @version 1.0
 */
#include <stdio.h>
#include "SeqList.h"

int main() {
  //初始化线性表
  SeqList List;
  Init(&List);

  printf("线性表长度: %d\n", Length(&List));

  Add(&List,1994);
  Add(&List,2008);

  if(IsEmpty(&List)) {
    printf("线性表为空\n");
  }else {
    printf("线性表不为空\n");
  }

  int location;
  location = 1;
  printf("线性表第%d个元素为：%d\n", location, Get(&List, location));

  Insert(&List, 1, 2015);

  location = 1;
  printf("线性表第%d个元素为：%d\n", location, Get(&List, location));

  Delete(&List,1);

  location = 1;
  printf("线性表第%d个元素为：%d\n", location, Get(&List, location));

  ElemType elem = 2008;
  printf("线性表元素为%d的位置为：%d\n",elem, Locate(&List, elem));

  return 0;
}
