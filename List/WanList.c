//线性表的完整代码实现
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define LIST_INIT_SIZE 100
#define LIST-INCREAMENT 10
typedef struct
{
   int *elem;
   int length;
   int listsize;
}SqList;
//******函数声明******
SqList InitSList();
//******主函数******
void main()
{

}
//******基本操作******
//******创建顺序表******
SqList InitSList()
{
   SqList L;
   L.elem=(int *)malloc(LIST_INTT_SIZE * sizeof(int));
   if(!L.elem) exit(0);//内存分配失败
   L.length=0;//空表长度为0
   L.listsize=LIST_INIT_SIZE;//初始存储容量
   return 1;
}
//******插入元素******
void InsertSList(SqList &L,int i,int e)
{
   int *newbase;
   int *p,*q;

   if((i<1)||(i>L.length+1)) return -1;//i值不合法
   if(L.leng>=L.listsize)
   {
   newbase=(int *)realloc(L.elem,(L.listsize+LIST-INCREAMENT)*sizeof(int));
   if(!newbase) exit(-1);//追加内存失败
   L.elem=newbase;
   L.listsize+=LIST-INCREAMENT;
   }
   
   q=&(L.elem[i-1]);
   for(p=&(L.elem[L.length-1]);p>=q;--p)
   *(p+1)=*p;
   *q=e;
   ++L.length;

   return 1;
}
//******删除元素******
void DeleSList(SqList &L,int i),int e
{
   int *P,*q;

   if((i<1)||(i>L.length))   return -1;
   p=&(L.elem[i-1]);
   e=*p;
   q=L.elem+L.length-1;
   for(++p;p<=q;++p)
	   *(p-1)=*p;
   --L.length;

   return 1;
}
//******查找元素元素******
void FindSList(SqList &L,int i,int)
{
   
}
//***计算链表长度***
