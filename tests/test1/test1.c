/**
 * 输入一个三位自然数，把百位数和个位数对调，输出对调后的数
 * 如:
 * 	123 => 321
 */
#include <stdio.h>

int main() {
  int inputNum;
  printf("请输入一个三位自然数：");
  scanf("%d", &inputNum);

  if(inputNum>99&&inputNum<1000) {
    int a, b, c;
    a = inputNum/100;
    b = inputNum/10%10;
    c = inputNum%10;

    int targetNum;
    targetNum = c*100 + b*10 + a;
    printf("对调后的数为：%d\n", targetNum);
  }else {
    printf("%d不是三位自然数\n", inputNum);
  }
  return 0;
}
