#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#typedef int elemtype
typedef struct lianzhan
{
   elemtype data;
   struct lianzhan *next;
};

void pushstack();
void initstack();
void pushstack();
void display();

int main()
{
  int a;
  lianzhan s;

  initstack(&s);
  pushstack(&s,1);
  pushstack(&s,2);
  pushstack(&s,3);
  pushstack(&s,4);
  pushstack(&s,5);

  display(&s);

  return 0;
}
void initstack(struct lianzhan *ltop)
{
   ltop=NULL;
}

void pushstack(lianzhan *ltop,elemtype x)
{
   struct lianzhan *p;
   p=(struct lianzhan *)malloc(sizeof(struct lianzhan));
   p->data=x;
   p->next=ltop;
   ltop=p;
}

void popstack(struct lianzhan *ltop,elemtype *t)
{
   struct lianzhan *p;
   if(ltop==NULL)
	   printf("产生下溢\n");
   else
   {
   p=ltop;
   *t=p->data;
   ltop=p->next;
   free(p);
   }
}

void display(struct lianzhan *ltop)
{
   struct lianzhan *t;
   t=ltop;
   while(t!=NULL)
   {
   printf("%d",t->data);
   t=t->next;
   }
   printf("\n");
}
