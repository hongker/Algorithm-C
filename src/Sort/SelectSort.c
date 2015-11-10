/**
 * 简单选择排序
 */
 #include <stdio.h>
 #include "CreateData.c"
 #define ARRAYLEN 10
 /**
  * 简单选择排序
  * @param a [description]
  * @param n [description]
  */
 void SelectSort(int a[], int n) {
   int i, j, k, temp;
   for(i=0;i<n-1;i++) {
     k = i;
     for(j=i+1;j<n;j++) {
       if(a[k]>a[j])
        k = j; //找到最小的数
     }

     //交换元素
     temp = a[i];
     a[i] = a[k];
     a[k] = temp;
   }
 }
