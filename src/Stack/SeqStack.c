/**
 * 栈相关操作函数实现(顺序线性表)
 * @author hongker
 * @version 1.0
 */
#include <stdio.h>
#include "SeqStack.h"

/**
 * 栈初始化
 * @return [description]
 */
SeqStack *Init() {
  printf("栈初始化...\n");
  SeqStack *stack;
  if(!(stack=(SeqStack *)malloc(sizeof(SeqStack)))) {
    printf("为栈初始化分配空间失败.\n");
    return NULL;
  }

  stack->top = -1;
  return stack;
}

/**
 * 释放栈空间
 * @param stack [description]
 */
void Free(SeqStack *stack) {
  printf("释放栈空间...\n");
  if(stack) {
    free(stack);
  }
}

/**
 * 判断栈是否为空
 * @param  stack [description]
 * @return  为空返回1,否则返回0
 */
int IsEmpty(SeqStack *stack) {
  printf("判断栈是否为空...\n");
  if(stack->top==0) {
    return 1;
  }
  return 0;
}

/**
 * 判断栈是否已满
 * @param  stack [description]
 * @return       [description]
 */
int IsFull(SeqStack *stack) {
  printf("判断栈是否已满...\n");
  if(stack->top==SIZE) {
    return 1;
  }
  return 0;
}

/**
 * 清空栈
 * @param stack [description]
 */
void Clear(SeqStack *stack) {
  printf("清空栈...\n");
  stack->top = 0;
}

/**
 * 入栈
 * @param  stack [description]
 * @param  elem  [description]
 * @return       [description]
 */
int Push(SeqStack *stack, ElemType elem) {
  printf("入栈...\n");
  if(stack->top==SIZE) {
    printf("栈已满...\n");
    return -1;
  }

  stack->data[stack->top++] = elem;
  return 0;
}

/**
 * 出栈
 * @param  stack [description]
 * @return       [description]
 */
ElemType Pop(SeqStack *stack) {
  printf("出栈...\n");
  if(stack->top==0) {
    printf("栈已空...\n");
    exit(0);
  }

  return stack->data[stack->top--];
}

/**
 * 获取栈顶元素
 * @param  stack [description]
 * @return       [description]
 */
ElemType Peek(SeqStack *stack) {
  
  if(stack->top==0) {
    printf("栈已空...\n");
    exit(0);
  }

  return stack->data[stack->top-1];
}
