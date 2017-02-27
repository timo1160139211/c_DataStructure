#include <stdio.h>
#include <stdlib.h>
#define null NULL
#define SIZE 100
typedef int dateType;
typedef struct cstack
{
   dateType date[SIZE];//数组实现
   struct cstack *top;//栈顶指针
}cstack;

void initStack();//初始化栈
void destroyStack();//销毁栈
int isEmpty();//是否为空栈
int pushStack();//入栈
void popStack();//出栈
void displaypop();//遍历栈

int main()
{
//声明指针栈变量
   struct cstack *A ;
   int i;
   printf("hello world !\n\n\n");   
//初始化栈A
   initStack(&A);
//入栈
   for(i=0;i<=10;i++)
   pushStack(&A,&i);
//打印全部元素的出栈顺序，只是打印，并没有真正出栈
   displayop(&A);
//出栈操作
   popStack(&A,&i);
   putchar('\n');
//打印全部元素的出栈顺序，只是打印，并没有真正出栈
   displayop(&A);
   printf("\n\n任意键结束程序\n\n");
   getchar();
   return 0;
}
//初始化
void initStack(struct cstack *A)
{
   A=(cstack * )malloc(sizeof(cstack));
   if(!A)
	   printf("内存不足!\n");
   else{
   printf("初始化成功!\n");
   (*A).top=-1;
   }
}
//销毁
void destroyStack(struct cstack *A)
{
   if(A==NULL)
   {
   printf("栈不存在，销毁失败！\n");
   return -1;
   }
   else
   {
   free(A);
   A=NULL;
   }
}
//是否为空
int isEmpty(struct cstack *A)
{
   if((*A).top==-1)
	   return 0;
   	else
		return -1;
}

//入栈
int pushStack(struct cstack *A,dateType e)
{
   if((*A).top==SIZE-1)
   {
   printf("栈已经满了!\n");
   return -1;
   }
   else
   {
   (*A).top++;
   (*A).top=e;
   return 0;
   }
}

//出栈
void popStack(struct cstack *A,dateType *e)
{
   if((*A).top==-1)
   {
   printf("栈是空的，出栈失败！\n");
   return -1;
   }
   else
	   *e=(*A).top;
   (*A).top--;
   return 0;
}

//遍历出栈
void displaypop(struct cstack *A)
{
   if((*A).top==-1)
   {
   printf("栈是空的\n");
   return -1;
   }
   else
   {
   int i;

   for(i=(*A).top;i>=0;i--)
   {
   printf("%d",(*A).date[i]);
   if(i==0)
	   break;
   else printf("->");
   }
   }
}
