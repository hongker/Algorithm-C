/**
 * 如果一个数恰好等于其因子之和，那么这个数被称为完数。
 * 如 6 = 1 + 2 +3
 * 求10000以内的完数
 * 解决过程：
 * (1)用n去除1～n之间的整数，将能被整除的被除数保存到一个数组中，作为n的一个因子。
 * (2)用n减去该因子，以方便计算各因子之和是否等于n。
 * (3)继续重复步骤(1)和步骤(2),直至将所有整数除完为止。
 * (4)最后判断各因子之和是否等于n，若相等，则n是完数。
 */
#include <stdio.h>
int main() {
  long p[30]; //保存因子
  long i,num, count, s, total = 0;
  for(num=2;num<=10000;num++) {
    count = 0;
    s = num;
    for(i=1;i<num;i++) {
      if(num%i==0) {
        p[count++] = i; //保存因子
        s -= i; //减去一个因子
      }
    }
    if(s==0) {
      //已经分解完
      printf("%ld是完数!因子为：",num);
      printf("%ld=%ld", num, p[0]);
      for(i=1;i<count;i++)
        printf("+%ld", p[i]);
      printf("\n");
      total++;
    }
  }

  printf("10000以内一共%ld个完数\n", total);
  
  return 0;
}
