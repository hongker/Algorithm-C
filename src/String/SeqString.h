/**
 * 字符串结构定义
 */
 #define MAXSIZE 100
 #define ElemType char
 
 
 typedef struct {
  ElemType data[MAXSIZE];
  int len;
}SeqString;

int isEmpty(SeqString *s); //判断字符串是否为空

int getLength(SeqString *s); //获取字符串的长度

int setValue(SeqString *s); //给字符串设置值

SeqString strConcat(SeqString *s1, SeqString *s2); //连接字符串

SeqString getSubstr(SeqString *s, int i, int n); //获取子字符串

ElemType getElem(SeqString *s, int i); //获取字符串中的元素 

int insert(SeqString *s, int i, ElemType e); //插入元素

int delete(SeqString *s, int i); //删除元素

