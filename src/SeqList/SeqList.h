/**
 * 顺序线性表定义
 * @author hongker
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>

#ifndef ElemType
#define ElemType int
#endif

//定义线性表的最大长度
#ifndef MAXSIZE
#define MAXSIZE 100
#endif

//定义顺序表的存储结构
typedef struct {
  ElemType data[MAXSIZE]; //存储数据
  int length; //顺序表长度
}SeqList;

void Init(SeqList *List); //初始化线性表
int Length(SeqList *List); //返回线性表的元素数量
int Add(SeqList *List, ElemType elem); //向线性表中添加元素
int Insert(SeqList *List, int location, ElemType elem); //向线性表中插入元素
int Delete(SeqList *List, int location); //从线性表中删除元素
ElemType Get(SeqList *List, int location); //根据位置查找元素
int Locate(SeqList *List, ElemType elem); //根据元素查找其在线性表中的位置
int GetAll(SeqList *List); //查看线性表中的全部元素
int IsEmpty(SeqList *List); //查看线性表是否为空
