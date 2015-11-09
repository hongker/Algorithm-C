/**
 * 冒泡排序
 */
void BubbleSort(int a[], int n) {
  int i, j, temp;
  for(i=0;i<n;i++) {

    for(j=n-1;j>i;j--) {
      if(a[j-1]>a[j]) { //比较元素
        temp = a[j-1];
        a[j-1] = a[j];
        a[j] = temp;
      }
    }
  }
}
