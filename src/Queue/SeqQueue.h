/**
 * 队列相关操作定义(顺序线性表)
 * @author hongker
 * @version 1.0
 */
 #include <stdlib.h>

 //队列最大长度
 #ifndef QUEUEMAX
 #define QUEUEMAX 15
 #endif

 typedef struct {
   char name; //名称
   int age; //年龄
 }ElemType;

 typedef struct {
   ElemType data[QUEUEMAX];
   int head;
   int tail;
 }SeqQueue;

 SeqQueue *Init(); //初始化队列
 int IsEmpty(SeqQueue *Queue); //判断队列是否为空
 int IsFull(SeqQueue *Queue); //判断队列是否已满
 int Length(SeqQueue *Queue); //获取队列长度
 int GetIn(SeqQueue *Queue, ElemType elem); //入列
 ElemType * GetOut(SeqQueue *Queue); //出列
 ElemType * Peek(SeqQueue *Queue); //获取队首元素
