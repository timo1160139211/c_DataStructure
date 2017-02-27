#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType;
typedef int status;

typedef struct Queue
{
   ElemType data;
   struct Queue *next;
}Queue,*QueuePtr;

typedef struct
{
   Queue front;//对头指针
   Queue rear;//队尾指针
}LinkQueue;

status InitQueue(LinkQueue *Q)//建立空队列
{
   Q.front=Q.rear=(QueuePtr *)malloc(sizeof(Queue));//申请内存
   if(!Q.front)
   exit (-2);//存储分配失败
   Q.front->next=NULL;
   return 1;
}

status DestroyQueue(LinkQueue *Q)//销毁队列
{
   while(Q.front)
   {
   Q.rear=Q.front->next;
   free(Q.front);
   Q.front=Q.rear;
   }
   return 1;
}

status EnQueue(LinkQueue *Q,ElemType e)//插入元素
{
   QueuePtr p=(QueuePtr *)malloc(sizeof(Queue));
   if(!p)
   exit (-2);//存储分配失败
   p->data=e;
   p->next=NULL;
   Q.rear=p;//队尾插入元素
   return 1;
}

status DeQueue(LinkQueue *Q,ElemType e)//删除元素
{
   QueuePtr p;

   if(Q.front=Q.rear)
	   return 0;
   p=Q.front->next;
   e=p->next;
   Q.front->next=p->next;
   if(Q.rear==p)
	   Q.front=Q.rear;
   free(p);
   
   return 0;
}

void PrintQueue(LinkQueue *Q)//打印队列
{
   QueuePtr temp;
   
   temp=Q.front->next;
   while(temp!==NULL)
   {
   printf("%d",temp->data);
   temp=temp->next;
   }
}

int main()
{
   LinkQueue *Q;
   InitQueue(Q); 

   int i;
   for(i=0;i<10;i++)
   {
   EnQueue(Q,i);
   }

   printf("插入队列的元素为:\n");
   PrintQueue(Q);

   return 0;
}
