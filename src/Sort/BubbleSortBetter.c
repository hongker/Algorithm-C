/**
 * 改进版冒泡排序
 */
 void BubbleSort(int a[], int n) {
   int i, j, temp, flag = 0;
   for(i=0;i<n;i++) {

     for(j=n-1;j>i;j--) {
       if(a[j-1]>a[j]) { //比较元素，满足条件就交换
         temp = a[j-1];
         a[j-1] = a[j];
         a[j] = temp;
         flag = 1;
       }
     }

     if(flag==0) //如果没有发生交换，则直接跳出
       break;
     else
      flag = 0;
   }
 }
