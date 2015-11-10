/**
 * 快速排序
 */
#include <stdio.h>
#include "CreateData.c"
#define ARRAYLEN 10

/**
 * 分割函数
 * @param  a     [description]
 * @param  left  [description]
 * @param  right [description]
 * @return       [description]
 */
int Devision(int a[], int left, int right) {
  int base = a[left]; //选择基准数
  while(left<right) {
    while(left<right && a[right]>base) //未找到比基准数小的时候，右侧指针一直往左移动
      --right;

    //发现比基准数小的值，替换位置
    a[left] = a[right];

    while(left<right && a[left]<base) //未找到比基准数大的时候，左侧指针一直往右移动
      ++left;

    //发现比基准数大的值，替换位置
    a[right] = a[left];
  }
  a[left] = base;
  return left; //返回基准数最终位置，即分割点
}

/**
 * 快速排序
 * @param a     [description]
 * @param left  [description]
 * @param right [description]
 */
void QuickSort(int a[], int left, int right) {
  int i;
  if(left<right) {
    i = Devision(a, left, right); //分割
    QuickSort(a, left, i-1); //对左则进行递归排序
    QuickSort(a, i+1, right); //对右侧进行递归排序
  }
}
