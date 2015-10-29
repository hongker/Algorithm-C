/**
 * 顺序线性表函数实现
 * @author hongker
 * @version 1.0
 */
#include "SeqList.h"

/**
 * 线性表初始化
 * @param List [description]
 */
void Init(SeqList *List) {
  printf("线性表初始化...\n");
  List->length = 0;
}

/**
 * 获取线性表长度
 * @param  List [description]
 * @return      [description]
 */
int Length(SeqList *List) {
  return List->length;
}

/**
 * 添加元素
 * @param  List [description]
 * @param  elem [description]
 * @return      [description]
 */
int Add(SeqList *List, ElemType elem) {
  printf("添加元素...\n");
  if(List->length==MAXSIZE) { //检查线性表是否已满
    return -1;
  }

  List->data[List->length] = elem;
  List->length++;
  return 0;
}

/**
 * 将元素插入线性表
 * @param  List     [description]
 * @param  location [description]
 * @param  elem     [description]
 * @return          [description]
 */
int Insert(SeqList *List, int location, ElemType elem) {
  printf("插入线性表......\n");
  if(location>List->length-1||location<0) {
    printf("插入位置非法!\n");
    return -1;
  }

  int i;
  for(i=List->length;i>=location;i--) {
    List->data[i] = List->data[i-1];
  }
  List->data[location-1] = elem;
  List->length++;

  return 0;
}

/**
 * 删除元素
 * @param  List     [description]
 * @param  location [description]
 * @return          [description]
 */
int Delete(SeqList *List, int location) {
  printf("删除元素......\n");
  if(location>List->length||location<=0) {
    printf("删除位置非法!\n");
    return -1;
  }

  int i;
  for(i=location;i<List->length;i++) {
    List->data[i-1] = List->data[i];
  }
  List->length--;
  return 0;
}

/**
 * 根据位置获取元素
 * @param  List     [description]
 * @param  location [description]
 * @return          [description]
 */
ElemType Get(SeqList *List, int location) {
  if(location>List->length||location<=0) {
    return -1;
  }
  return List->data[location-1];
}

/**
 * 根据元素找到在线性表中的位置
 * @param  List [description]
 * @param  elem [description]
 * @return      [description]
 */
int Locate(SeqList *List, ElemType elem) {
  if(List->length==0) {
    printf("线性表为空......\n");
    return -1;
  }

  int i, location;
  location = -1;
  for(i=0;i<List->length;i++) {
    if(List->data[i]==elem) {
      location = i + 1;
      break;
    }
  }
  if(location==-1) {
    printf("未找到元素\n");
  }
  return location;
}

/**
 * 判断线性表是否为空
 * @param  List [description]
 * @return   为空返回1,否则返回0
 */
int IsEmpty(SeqList *List) {
  if(List->length==0) {
    return 1;
  }
  return 0;
}
