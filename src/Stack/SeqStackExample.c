/**
 * 栈使用示例
 * @author hongker
 * @version 1.0
 */
#include <stdio.h>
#include <string.h>
#include "SeqStack.h"

int main() {
  SeqStack *stack;
  stack = Init();

  ElemType elem;
  printf("请输入姓名: ");
  scanf("%s", elem.name);
  printf("请输入年龄: ");
  scanf("%d", &elem.age);

  Push(stack, elem);

  if(IsEmpty(stack)) {
    printf("栈为空..\n");
  }else {
    printf("栈非空..\n");
  }

  ElemType value = Peek(stack);

  printf("出栈元素名称:%s,年龄:%d\n", value.name, value.age);
  return 0;
}
