/**
 * 快速排序使用示例
 */
#include "QuickSort.c"
int main() {
  int i, a[ARRAYLEN];
  for(i=0;i<ARRAYLEN;i++)
    a[i] = 0;

  if(!CreateData(a, ARRAYLEN, 1, 100)) {
    printf("随机数生成失败!\n");
    exit(0);
  }

  printf("原数据：\n");
  for(i=0;i<ARRAYLEN;i++)
    printf("%d ", a[i]);
  printf("\n");

  QuickSort(a, 0, ARRAYLEN-1);

  printf("排序后：\n");
  for(i=0;i<ARRAYLEN;i++)
    printf("%d ", a[i]);
  printf("\n");
}
