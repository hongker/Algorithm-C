/**
 * 求三角形的面积
 */
 #include <stdio.h>
 #include <math.h>

 int main() {
   float a, b, c; //三条边

   printf("请输入三角形的三条边长，(示例: 3,4,5)：\n");
   scanf("%f,%f,%f", &a,&b,&c);

   float s;
   s = (a+b+c)/2;

   float x;
   x = s*(s-a)+s*(s-b)+s*(s-c);
   if(x>0) {
     float area;
     area = sqrt(x);

     printf("三角形的面积为:%f\n", area);
   }else {
     printf("两边之和需要大于第三边\n");
   }

   return 0;
 }
