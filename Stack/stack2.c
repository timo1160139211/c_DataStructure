#include <stdio.h>
#include <stdlib.h>
# define OK 1
# define OVERFLOW 0
# define ERROR 0
# define STACK_INIT_SIZE 100
# define STACKINCRENENT 10

typedef int Status;

typedef int ElemType;

 

typedef struct

{

	ElemType *base;

	ElemType *top;

	int stacksize;

}SqStack;

 

Status InitStack(SqStack s)//构造一个空栈  algorithm1

{

	    s.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));

	        if(!s.base)  exit(OVERFLOW);

		    s.top=s.base;

		        s.stacksize=STACK_INIT_SIZE;

			    return OK;

}

 

Status GetTop(SqStack s,ElemType e)//若栈不为空用e返回s的栈顶元素 algorithm2

{

	    if(s.top==s.base) return ERROR;

	        e=*(s.top-1);

		    return OK;

}

 

Status Push(SqStack s,ElemType e)//插入e为新的栈顶元素 algorithm3

{

	    if(s.top-s.base>=s.stacksize)

		        {

				      s.base=(ElemType *)realloc(s.base,(s.stacksize+STACKINCRENENT)*sizeof(ElemType));

				            if(!s.base) exit(OVERFLOW);

					          s.top=s.base+s.stacksize;

						        s.stacksize+=STACKINCRENENT;

							    }

	        *s.top++=e;

		    return OK;

}

 

Status Pop(SqStack s,ElemType e)//若栈不空，删除栈顶，用e返回栈顶元素algorithm4

{

	  if(s.top==s.base) return ERROR;

	    e=*--s.top;

	      return OK;

}

 

void Print(SqStack s)//遍历

{

	    while(s.top!=s.base)

		        printf("%d    ",*--s.top);

}

int main()

{

	    int b;

	        SqStack a;

		    InitStack(a);

		        Push(a,1);

			    Print(a);

			        printf("\n------------------\n");

				    Push(a,2);Push(a,3);

				        Push(a,4);Push(a,5);

					    Push(a,6);Push(a,7);

					        Push(a,8);Push(a,9);

						    Print(a);

						        printf("\n------------------\n");

							    GetTop(a,b);

							        printf("Top is %d\n",b);

								    printf("------------------\n");

								        if(Pop(a,b))

										    printf("%d",b);

									    return 0;

}
