#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef char ElemType;
typedef struct
{
   ElemType elem[MaxSize];
   int length;
}SqList;
void Insert(SqList &A,int i, ElemType x)
{
   int i = 0, j;
   while(i < A.length && A.elem[i] < x)
	   i++;
   for(j = A.length - 1; j >= i; j--)
	   A.elem[j+1] = A.elem[j];
   A.elem[i] = x;
   A.length++;
}
int main()
{
   SqList *p;
   int i;
   
   p = (SqList*)malloc(sizeof(SqList));
   for(i = 0; i < p->length; i++)
	   scanf("%c",p->elem[i]);
   Insert(p,8);
   for(i = 0; i < p->length; i++)
   printf("%c", p->elem[i]);
   
   return 0;
}
