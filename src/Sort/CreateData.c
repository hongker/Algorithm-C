/**
 * 随机生成大量数据
 */
#include <stdlib.h>

/**
 * 生成随机数
 * @param  arr 保存生成随机数的数组
 * @param  n   生成个数
 * @param  min 最小值
 * @param  max 最大值
 * @return     [description]
 */
int CreateData(int arr[], int n, int min, int max) {
  int i, j, flag;
  srand(time(NULL));

  if((max-min+1<n)) {
    return 0;
  }

  for(i=0; i<n; i++) {
    do {
      int d = rand();
      arr[i] = (int)((max-min+1.0)*rand()/(RAND_MAX+1.0)+min);
      flag = 0;
      for(j=0;j<i;j++) {
        if(arr[i]==arr[j])
          flag = 1;
      }
    }while(flag);
  }

  return 1;
}
