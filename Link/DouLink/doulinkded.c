# include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node//定义双向链表的基本结构
{
   int x;
   struct node *prev,*next;
}node;

struct node *creat_list();
void out_list();

int main()
{
   node *l;
   l=creat_list();
   printf("创建成功\n");
   out_list(l);//注意形参指针的初始值必须定义！
}

void out_list(node *head)
{
   node *p;

   p=head->next;

   if(p==NULL)
   printf("链表为空！\n");

   else
	   while(p!=head){//注意此处条件发生了改变，否则会陷入死循环
		   printf("%d",p->x);
		   p=p->next;
	   }
   putchar('\n');
}

struct node *creat_list()
{
   struct node *p,*h,*l;
   int n,i,x;

   h=(struct node *)malloc(sizeof(struct node));//分配空间
   
   p->prev=p;
   p->next=p;//创建空链表
   p=h;

   printf("请输入需要创建的链表的长度\n");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
   printf("请输入第%d个数\n",i+1);
   scanf("%d",&x);

  l=(struct node *)malloc(sizeof(struct node));

   l->x=x;
   p->next=l;
   l->prev=p;
   l->next=h;
   h->prev=l;
   p=l;
   }

   return (h);
}

