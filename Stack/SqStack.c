#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
typedef struct
{
   int *base;
   int *top;
   int stacksize;  
}SqStack;


int main()
{

}

int InitStack(SqStack *S)
{
   S->base=(int *)malloc(STACK_INIT_SIZE * sizeof(int));
   if(!S->base)
	   exit (OVERFLOW);//内存分配失败
   S->top=S->base;//空栈的标志
   S->stacksize=STACK_INIT_SIZE;

   return OK;
}

int GetStack(SqStack *S,int &e)
{
   
}
