/**
 * 希尔排序
 */
#include <stdio.h>
#include "CreateData.c"
#define ARRAYLEN 10

void ShellSort(int a[], int n) {
  int d,i,j,x;
  d = n/2; //第1次的增量

  while(d>=1) {
    for(i=d;i<n;i++) {
      x = a[i]; //获取序列中的下一个数据
      j = i-d; //序列前一个数据

      while(j>=0 && a[j]>x) {
        a[j+d] = a[j];
        j = j-d; //修改序号，继续向前比较,如增量为2时，先第6和第4比，然后第4和第2比

      }
      a[j+d] = x;
    }
    d = d/2; //缩小增量
  }
}
