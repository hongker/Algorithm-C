/**
 * 栈相关操作定义
 * @author hongker
 * @version 1.0
 */
#include <stdlib.h>

#ifndef SIZE
#define SIZE 10
#endif

typedef struct {
  char name[15];
  int age;
} ElemType;

typedef struct {
  ElemType data[SIZE+1];
  int top;
} SeqStack;

SeqStack *Init(); //栈初始化
void Free(SeqStack *stack); //释放栈
int IsEmpty(SeqStack *stack); //判断栈是否为空
int IsFull(SeqStack *stack); //判断栈是否已满
void Clear(SeqStack *stack); //清空栈
int Push(SeqStack *stack, ElemType elem); //元素入栈
ElemType Pop(SeqStack *stack); //元素出栈
ElemType Peek(SeqStack *stack); //获取栈顶元素
