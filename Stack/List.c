#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define EERROR -1
#define TURE 2
#define FALSE 0

typedef struct L
{
   DateType date[MAXSIZE];
   int length;
}SqList;

int ListInsert(Sqlist *L,int i,DateType e)
{
   int k;

   if(l->Length==MAXSIZE)
	   return EEROR;
   if(i<1||i>L->length+1)
	   return ERROE;
   if(i<=L->length)
   {
   for(k=L->length-1;k>=i-1;k--)
	   L->date[k+1]=L->date[k];
   }
   L->date[i-1]=e;
   L->length++;
   return OK;
}
