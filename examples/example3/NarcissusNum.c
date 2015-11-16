/**
 * 一个三位数，如果它的个十百位上的数的三次方之和等于这个数本身，那么称它为水仙花数
 * @example
 * 	153 = 1^3 + 5^3 + 3^3
 */
#include <stdio.h>
int main() {
  int i;
  int num1,num2,num3;
  printf("100~999之间的水仙花数：\n");
  for(i=100;i<=999;i++) {
    num1 = i%10; //个位数
    num2 = i/10%10; //十位数
    num3 = i/100; //百位数

    if(i==num1*num1*num1+num2*num2*num2+num3*num3*num3) {
      printf("%4d", i);
    }

  }
  printf("\n");
  return 0;
}
