#include <stdio.h>
#include <stdlib.h>
#define null NULL
#define SIZE 100
typedef int dateType;
typedef struct
{
   dateType date[SIZE];//数组实现
   int top;
}cstack,*cstackP;

void initStack();
void destroyStack();
int isEmpty();
int pushStack();
void popStack();
void displaypop();

int main()
{
//声明指针栈变量
   cstackP A ;
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
void initStack(cstackP *A)
{
   if(((*A)=(cstackP)malloc(sizeof(cstack)))==NULL)
	   printf("内存不足!\n");
   else{
   printf("初始化成功!\n");
   (*A)->top=-1;
   }
}
//销毁
void destroyStack(cstackP *A)
{
   if(*A==NULL)
   {
   printf("栈不存在，销毁失败！\n");
   return;
   }
   else
   {
   free(*A);
   *A=NULL;
   }
}
//是否为空
int isEmpty(cstackP *A)
{
   if(A->top==-1)
	   return 1;
   	else
		return 0;
}

//入栈
int pushStack(cstackP *A,dateType e)
{
   if(A->top==SIZE-1)
   {
   printf("栈已经满了!\n");
   return -1;
   }
   else
   {
   A->top++;
   A->date[A->top]=e;
   return 0;
   }
}

//出栈
void popStack(cstackP *A,dateType *e)
{
   if(A->top==-1)
   {
   printf("栈是空的，出栈失败！\n");
   return -1;
   }
   else
	   *e=A->date[A->top];
   A->top--;
   rturn 0;//为什么返回值是0
}

//遍历出栈
void displaypop(cstackP *A)
{
   if(A->top==-1)
   {
   printf("栈是空的\n");
   return -1;
   }
   else
   {
   int i;

   for(i=A->top;i>=0;i--)
   {
   printf("%d",A->date[i]);
   if(i==0)
	   break;
   else printf("->");
   }
   }
}
