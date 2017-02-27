#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
   int date;
   struct node *prev,*next;
}node;

struct node *creat_list();
void out_list();//函数声明

int main()
{
   node *s;
   s=creat_list();
   printf("创建成功！\n");
   out_list(s);
}

void out_list(node *head)
{
   node *p;

   p=head->next;

   if(p==NULL)
	   printf("链表为空!\n");
   else
	   while(p!=head){
	   printf("%d",p->date);
	   p=p->next;
	   }

   putchar('\n');
}

struct node *creat_list()
{
   struct node *p,*s;
   int n,i,date;

   p=(struct node *)malloc(sizeof(struct node));
   
   p->prev->prev=p->prev;
   p->prev->next=p->prev;
   p=p->prev;

   printf("请输入需要创建的链表的长度\n");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
   printf("请输入第%d个数\n",i+1);
   scanf("%d",&date);

   s=(struct node *)malloc(sizeof(struct node));

   s->date=date;
   s->prev=p->prev;
   p->prev->next=s;
   s->next=p;
   p->prev=s;
   p->prev=s;
   }

   return (p);
}
