#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERLOW -2
#define MAXSIZE 100

typedef int Status;
typedef int QElemType;

//队列的顺序存储结构
typedef struct{
   QElemType *base;//指针
   int front;//对头指针
   int rear;//队尾指针
}SqQueue;//结构体名

Status InitQueue(SqQueue *Q);
int QueueLength(SqQueue *Q);
Status EnQueue(SqQueue *Q,QElemType e);
Status DeQueue(SqQueue *Q,QElemType e);

int main(void)
{
   int i,e;
   SqQueueu *Q;
    Q=NULL;
   InitQueue(Q);

   for(i=0;i<MAXSIZE;i++)
   EnQueue(Q,i);
   i=QueueLength(Q);
   printf("队列里由%d个元素\n",i);
   
   for(i=0;i<3;i++)
   {
   DeQueue(Q,e);
   printf("%d",e);
   }
   printf("\n");
}

//基本操作算法
//构造空队列
Status InitQueue(SqQueue *Q){
   Q->base=(QElemType *)malloc(MAXSIZE * sizeof(QElemType));
   if(!Q->base)
   exit(OVERLOW);//存储分配失败
   Q->front=Q->rear;

   return OK;
}
//队列长度
int QueueLength(SqQueue *Q){
   return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}
//查入元素
Status EnQueue(SqQueue *Q,QElemType e){
   if((Q->rear+1)%MAXSIZE==Q->front)
   return ERROR;//队列已满
   Q->base[Q->rear]=e;
   Q->rear=(Q->rear=1)%MAXSIZE;

   return OK;
}
//删除元素
Status DeQueue(SqQueue *Q,QElemType e){
   if(Q->front==Q->rear)
   return ERROR;//队列为空
   e=Q->base[Q->front];
   Q->front=(Q->front+1)%MAXSIZE;

   return OK;
}
