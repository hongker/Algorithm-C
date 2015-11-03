/**
 * 赫夫曼树实现
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int weight; //权值
  int parent; //父结点序号
  int left; //左子树序号
  int right; //右子树序号
} HuffmanTree;

typedef char *HuffmanCode; //赫夫曼编码指针

/**
 * 从n个结点中选出权重最小的两个结点
 * @param bt  指向赫夫曼树的指针
 * @param n   [description]
 * @param bt1 [description]
 * @param bt2 [description]
 */
void SelectNode(HuffmanTree *ht, int n, int *bt1, int *bt2) {
  int i;
  HuffmanTree *ht1, *ht2, *t;
  ht1 = ht2 = NULL;

  //循环处理n个结点
  for(i=1;i<=n;++i) {
    if(!ht[i].parent) { //如果父结点序号为0
      if(ht1==NULL) {
        ht1 = ht + i; //指向第i个结点
        continue;
      }
      if(ht2==NULL) {
        ht2 = ht + i;

        //比较权重,使ht2指向权重大的,ht1指向权重小的
        if(ht1->weight>ht2->weight) {
          t = ht2;
          ht2 = ht1;
          ht1 = t;
        }
        continue;
      }

      //如果ht1和ht2都不为NULL
      if(ht1 && ht2) {
        if(ht[i].weight<ht1->weight) {
          //如果第i个结点权重小于ht1指向的结点的权重
          ht2 = ht1;
          ht1 = ht+ i;
        }else if(ht[i].weight<ht2->weight) {
          ht2 = ht + i;
        }
      }
    }
  }

  //判断ht1和ht2的位置
  if(ht1>ht2) {
    *bt1 = ht2 - ht;
    *bt2 = ht1 - ht;
  }else {
    *bt1 = ht1 - ht;
    *bt2 = ht2 - ht;
  }
}

/**
 * 创建赫夫曼树
 * @param ht [description]
 * @param n  结点总数量
 * @param w  [description]
 */
void Create(HuffmanTree *ht, int n, int *w) {
  printf("创建赫夫曼树!\n");
  int i, m =2*n-1;
  int bt1, bt2;

  if(n<=1) return; //只有一个结点时，无法创建

  //初始化叶结点
  for(i=1;i<=n;++i) {
    printf("初始化叶结点!权重为：%d\n",w[i-1]);
    ht[i].weight = w[i-1];
    ht[i].parent = 0;
    ht[i].left = 0;
    ht[i].right = 0;
  }

  //初始化后续结点
  for(;i<=m;++i) {
    ht[i].weight = 0;
    ht[i].parent = 0;
    ht[i].left = 0;
    ht[i].right = 0;
  }

  //逐个计算非叶结点，创建赫夫曼树
  for(i=n+1;i<=m;++i) {
    SelectNode(ht, i-1, &bt1, &bt2); //得到权重最小的两个结点
    ht[bt1].parent = i;
    ht[bt2].parent = i;
    ht[i].left = bt1;
    ht[i].right = bt2;
    ht[i].weight = ht[bt1].weight+ht[bt2].weight; //保存权值
    printf("两个结点：bt1:%d,bt2:%d,父结点:%d,权重：%d\n", bt1,bt2,i,ht[i].weight);
  }
}

/**
 * 根据赫夫曼树生成每个字符的赫夫曼编码
 * @param ht [description]
 * @param n  [description]
 * @param hc [description]
 */
void Coding(HuffmanTree *ht, int n, HuffmanCode *hc) {
  char *cd;
  int start, i;
  int current, parent;
  cd = (char *)malloc(sizeof(char)*n); //存放临时字符编码
  cd[n-1] = '\0';
  for(i = 1;i<=n;i++) {
    start = n-1;
    current = i;
    parent = ht[current].parent; //获取当前结点的父结点
    while (parent) {

      if(current==ht[parent].left) {
        //当前结点为左子树时
        cd[--start] = '0';
      }else {
        //右子树
        cd[--start] = '1';
      }
      //直接指向父结点
      current = parent;
      parent = ht[parent].parent;
    }
    
    hc[i-1] = (char *)malloc(sizeof(char)*(n-start));
    strcpy(hc[i-1], &cd[start]); //复制编码
  }
  free(cd);
}

/**
 * 根据赫夫曼编码将字符串进行编码
 * @param hc       [description]
 * @param alphabet [description]
 * @param str      [description]
 * @param code     [description]
 */
void Encode(HuffmanCode *hc, char *alphabet, char *str, char *code) {
  int len=0, i=0, j;
  code[0] = '\0';

  while (str[i]) {
    j=0;
    //查赫夫曼编码
    while (alphabet[j]!=str[i]) {
      j++;
    }

    strcpy(code+len,hc[j]); //赋值编码到指定位置
    len = len + strlen(hc[j]); //累加字符串长度
    i++;
  }
  code[len] = '\0';
}

/**
 * 将赫夫曼编码转换为明文
 * @param ht       [description]
 * @param m        [description]
 * @param code     [description]
 * @param alphabet [description]
 * @param decode   [description]
 */
void Decode(HuffmanTree *ht, int m, char *code, char *alphabet, char *decode) {
  int position = 0, i, j = 0;
  m = 2*m -1;
  while (code[position]) {
    for(i=m;ht[i].left&&ht[i].right;position++) {
      if(code[position]=='0')
        i = ht[i].left;
      else
        i = ht[i].right;
    }
    decode[j] = alphabet[i-1];
    j++;
  }
  decode[j] = '\0';
}

int main() {
  int i, n=4, m;
  char test[] = "DBCBDABDABCDCADBD"; //需要转码的字符串
  char code[100],code1[100];
  char alphabet[] = {'A','B','C','D'}; //字符
  int w[] = {5,7,2,13}; //对应权重
  HuffmanTree *ht;
  HuffmanCode *hc;

  m = 2*n - 1; //所有结点树
  ht = (HuffmanTree *)malloc(sizeof(HuffmanTree)*(m+1));

  if(!ht) {
    printf("分配空间失败!\n");
    exit(0);
  }

  hc = (HuffmanCode *)malloc(sizeof(char *)*n);

  if(!hc) {
    printf("分配空间失败!\n");
    exit(0);
  }

  Create(ht, n, w); //创建赫夫曼树
  Coding(ht, n, hc);
  for(i=1;i<=n;i++) {
    printf("字母：%c,权重:%d,编码为:%s\n", alphabet[i-1],ht[i].weight, hc[i-1]);
  }

  Encode(hc, alphabet, test, code);
  printf("\n字符串：\n%s\n转换后为：\n%s\n", test, code);

  Decode(ht, n, code, alphabet,  code1);
  printf("\n编码：\n%s\n解码后为：\n%s\n", code, code1);
  return 0;
}
