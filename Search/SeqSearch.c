#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -1
#define LIST_INIT_SIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;

typedef struct
{
   ElemType *elem;
   int length;
   int listsize;
}SqList;

int InitSqList(SqList *L);
void CreatSqList(SqList *L,int j);
void PrintSqList(SqList *L,int i);
int InsertSqList(SqList *L,int i,int e);
int DeleteSqList(SqList *L,int i,int e);

int main()
{
   SqList L;
   int i,j,e;

   InitSqList(&L);
   CreatSqList(&L,j);
   printf("打印链表\n");
   PrintSqList(&L,i);
   printf("插入元素\n");
   InsertSqList(&L,i,e);
   printf("插入后的链表\n");
   PrintSqList(&L,i);
   printf("删除元素\n");
   DeleteSqList(&L,i,e);
   printf("删除后的链表\n");
   PrintSqList(&L,i);
}

int InitSqList(SqList *L)
{
   L->elem=(ElemType*)malloc(100*sizeof(ElemType));//分配内存
   if(L->elem==NULL)
	   exit (OVERFLOW);//内存分配失败，指针指向空，返回NULL
   L->length=0;//表长度初始化为0
   L->listsize=LIST_INIT_SIZE;
   return OK;
}
void CreatSqList(SqList *L,int j)
{
   L->length=5;

   for(j=0;j<L->length;j++)
   {
   printf("请输入5个元素");
   scanf("%d",&L->elem[j]);
   }
}
void PrintSqList(SqList *L,int i)
{
   for(i=0;i<L->length;i++)
	   printf("%d\n",L->elem[i]);
}
int InsertSqList(SqList *L,int i,int e)
{
   int *p,*q;

   printf("请输入要插入的元素位置\n");
   scanf("%d",&i);

   if(i<1||i>L->length+1)
   printf("输入的位置不正确\n");

   q=&(L->elem[i-1]);//插入位置
   for(p=&(L->elem[L->length-1]);p>=q;--p)
	   *(p+1)=*p;//插入位置及之后的元素后移
   printf("请输入要插入的元素\n");
   scanf("%d",&e);
   *q=e;
   ++L->length;//表长加1
   return OK;

}
int DeleteSqList(SqList *L,int i,int e)
{
   int *p,*q;

   printf("请输入要删除元素的位置\n");
   scanf("%d",&i);

   if(i<1||i>L->length)
	   return ERROR;

   p=&(L->elem[i-1]);
   e=*p;//被删除元素的值赋给e
   q=&(L->elem[L->length-1]);
   for(++p;p<=q;++p)
	   *(p-1)=*p;//位置前移
   --L->length;//表长减1

   return OK;
}
