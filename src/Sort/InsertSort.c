/**
 * 插入排序
 */
#include <stdio.h>
#include "CreateData.c"
#define ARRAYLEN 10

void InsertSort(int a[], int n) {
  int i, j, t;
  for(i=1;i<n;i++) { //遍历除第1个数
    t = a[i]; //用作比较的数
    for(j=i-1;j>=0 && t < a[j];--j) { //遍历已排序的数列，如果temp较小，则已排序的数往后移动
        a[j+1] = a[j];
    }
    a[j+1] = t; //直到temp>a[j],此时便把值放于此处
  }
}
