/*************************
 * 斐波那契数列
 *************************/
#include <stdio.h>
#define NUM 13

int main() {
  int i;
  long fib[NUM] = {1, 1};

  for(i=2;i<NUM;i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  for(i=0;i<NUM;i++) {
    printf("第%d个月的兔子数：%ld\n",i+1,fib[i]);
  }

  return 0;
}
