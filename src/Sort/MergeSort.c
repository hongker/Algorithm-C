/**
 * 合并排序
 */
#include <stdio.h>
#include "CreateData.c"
#define ARRAYLEN 10

/**
 * 合并相邻有序段
 * @param a 待排序数组
 * @param r 保存合并后的数组
 * @param s 序列起始号
 * @param m 第1个序列的结束序号
 * @param n 有序列长度
 */
void MergeStep(int a[], int r[], int s, int m, int n) {
  int i, j, k;
  k = s;
  i = s;
  j = m+1;

  while(i<=m && j<=n) { //当两个有序表都未结束，循环比较
    if(a[i]<=a[j])
      r[k++] = a[i++];
    else
      r[k++] = a[j++];
  }

  while(i<=m) { //将未合并的部分赋值到r中
    r[k++] = a[i++];
  }

  while(j<=n) {
    r[k++] = a[j++];
  }
}

/**
 * 完成一遍二路合并
 * @param a   待排序序列
 * @param r   保存合并后的序列
 * @param n   需要进行排序的元素综合
 * @param len 每个有序列的长度
 */
void MergePass(int a[], int r[], int n,int len) {
  int s, e;
  s = 0; //第1个序列的起始号
  while(s+len<n) {
    e = s + 2*len -1; //第1个序列的结束序号
    if(e>=n) //最后一段可能少于len个结点
      e = n-1; //重新计算结束序号
    MergeStep(a, r,s,s+len-1,e); //合并
    s = e + 1;
  }
  if(s<n)
    for(;s<n;s++)
      r[s] = a[s];
}

/**
 * 合并排序
 * @param a [description]
 * @param n [description]
 */
void MergeSort(int a[], int n) {
  int *p;
  int len = 1;
  int f = 0;

  if(!(p=(int *)malloc(sizeof(int)*n))) {
    printf("分配临时内存空间失败!\n");
    exit(0);
  }

  while(len<n) {
    if(f)
      MergePass(p,a,n,len);
    else
      MergePass(a,p,n,len);

    len *= 2;
    f = 1-f; //使f在0和1之间切换
  }

  if(f)
    for(f=0;f<n;f++)
      a[f] = p[f]; //将数组p中的数据复制到数组a

  free(p);
}
