#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef struct
{
   int data;
   int *next;
}StackNode,*LinkStackPtr;
typedef struct
{
   LinkStackPtr top;
   int count;
}LinkStack;

int PushLinkStack(LinkStack *S,int e);
int PopLinkStack(LinkStack *S,int *e);
void main()
{
   LinkStack S;
   int e;
   int *e;

   PushLinkStack(&S,e);
   PopLinkStack(&S,&e);
}
int PushLinkStack(LinkStack *S,int e)
{
   LinKStackPtr s=(LinkStackPtr *)malloc(sizeof(StackNode));

   printf("请输入元素\n");
   scanf("%d",&e);

   s->data=e;//赋值给data
   s->next=S->top;//把当前栈顶元素赋值给新节点的直接后继
   S->top=s;
   S->count++;//长度加1

   return OK;
}

int PopLinkStack(LinkStack *S,int *e)
{
   LinkStackPtr p;
   if(*S==NULL)
	   return ERROR;

   *e=S->top->data;
   p=S->top;
   S->top=S->top->next;
   free(p);
   S->count--;
   printf("%d\n",*e);
   return OK;
}
