/**
 * 假设有a，b两个数，如果a的所有正因子和等于b，b的所有正因子和等于a，并且a和b不相等，则称a和b是一对亲密数。
 * @example:
 * 	220的因子数之和为284,而284的因子数之和为220,则220和284是一对亲密数
 *
 * 求10000以内的亲密数
 *
 * 解决思想：
 * 	(1)对每一个数a,将其因子分解出来，并将因子保存到数组中，再将因子之和保存到变量b1。
 * 	(2)将因子之和b1再进行分解，并将因子保存到数组中，将因子之和保存到比那量b2。
 * 	(3)若b2=a,并且b1!=b2，则a和b1是亲密数。
 *
 */
#include <stdio.h>
int main() {
  int i, max;
  printf("输入最大范围:");
  scanf("%d", &max);

  int arr1[100],arr2[100]; //保存因子的数组
  int count ; //保存下标

  int a, b1, b2;
  for(a=1;a<max;a++) {
    for(i=0;i<100;i++)
      arr1[i] = arr2[i] = 0; //初始化数组

    count = 0;
    b1 = 0;
    for(i=1;i<a/2+1;i++) {
      if(a%i==0) { //保存因子
        arr1[count++] = i;
        b1 += i;
      }
    }

    count = 0;
    b2 = 0;
    for(i=1;i<b1/2+1;i++) {
      if(b1%i==0) { //保存因子
        arr2[count++] = i;
        b2 += i;
      }
    }

    if(b2==a && a<b1) {
      printf("\n%d,%d是一对亲密数,各因子为\n", a, b1);
      printf("%d =1", a);
      count = 1;
      while(arr1[count]!=0) {
        printf("+%d", arr1[count]);
        count++;
      }
      printf("\n");
      printf("%d =1", b1);
      count = 1;
      while(arr2[count]!=0) {
        printf("+%d", arr2[count]);
        count++;
      }
      printf("\n");
    }

  }
  return 0;
}
