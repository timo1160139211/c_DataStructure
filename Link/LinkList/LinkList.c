#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef struct
{
   int data;
   int *next;
}Node;
typedef struct Node *LinkList;//定义LinkList

int CreateLinkList(LinkList *L,int n);
int SearchLinkList(LinkList *L,int i, int e);

int main()
{
   LinkList L;
   int i,n,e;
`   
   printf("***创建表***\n");
   CreateLinkList(&L,n);
   printf("***查找元素***\n");
   SearchLinkList(&L,i,e);
}

int CreateLinkList(LinkList *L,int n)
{
   LinkList p;
   int i;

   *L=(LinkList)malloc(sizeof(Node));
   L->next=NULL;//建立一个带头节点的单链表

   printf("请输入要输入的元素的个数\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
   p=(LinkList)malloc(sizeof(Node));//生成新的节点
   printf("请输入元素\n");
   scanf("%d",&p->data);
   p->next=L->next;
   L->next=p;//插入到表头
   }
}

int SearchLinkList(LinkList *L,int i, int e)
{
   int j;
   printf("请输入要查找的元素位置\n");
   scanf("%d",&i);
   LinkList p,q;
   p=*L;
   j=1;

   while(p->next&&j<i)
   {
   p=p->next;
   ++j;
   }
   if(!(p->next)||j>i)
   printf("元素不存在\n");
   q=p->next;
   p->next=q->next;
   e=q->data;
   printf("要查找的元素为%d\n",e);

   return OK;
}
