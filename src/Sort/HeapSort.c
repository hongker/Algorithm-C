/**
 * 堆排序
 */
 #include <stdio.h>
 #include "CreateData.c"
 #define ARRAYLEN 10

/**
 * 构成堆
 * @param a [description]
 * @param s [description]
 * @param n [description]
 */
 void HeapAdjust(int a[], int s, int n) {
   int j, temp;
   while(2*s+1<n) { //判断第s个结点上是否有右子树
     j = 2*s +1;
     if((j+1)<n) {
       if(a[j]<a[j+1]) //左子树小于右子树，则需要比较右子树
        j++;
     }
     if(a[s]<a[j]) { //如果子结点上的数据比父结点的大，则交换数据
       temp = a[s];
       a[s] = a[j];
       a[j] = temp;
       s = j; //同时调整堆
     }else {
       break; //退出循环
     }
   }
 }

/**
 * 堆排序
 */
void HeapSort(int a[], int n) {
  int temp, i, j;
  for(i=n/2-1;i>=0;i--)
    HeapAdjust(a, i, n);

  for(i = n-1;i>0;i--) {
    temp = a[0];
    a[0] = a[i];
    a[i] = temp;
    HeapAdjust(a, 0, i);
  }
}
