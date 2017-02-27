#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100            //线性表初始分配的空间
#define LISTINCREMENT 10             //线性表存储空间的分配增量
#define ElemType int

typedef struct
{
	    ElemType *elem;            //存储空间基址
	        int length;                //当前长度
		    int listsize;            //当前分配的存储容量（以sizeof(ElemType)为单位）               
}SqList;

void initList_Sq(SqList &L);            //构造一个空的线性表L
int listInsert_Sq(SqList &L, int i, ElemType e);            //插入元素
int listDelete_Sq(SqList &L, int i, ElemType &e);        //将第i个元素删除，并用e返回


int main()
{
	    SqList L;
	        int i;
		    initList_Sq(L);
		        for(i=1; i<6; ++i)
				    {
					            listInsert_Sq(L, i, i);
						        }
			   
			    for(i=0; i<L.length; ++i)
				        {
						        printf("%d ", L.elem[i]);   
							    }
			        printf("\n");

				    listInsert_Sq(L, 4, 6);
				        printf("After insert:\n");
					    for(i=0; i<L.length; ++i)
						        {
								        printf("%d ", L.elem[i]);   
									    }
					        printf("\n");
						   
						   
						    ElemType e;
						       
						        listDelete_Sq(L, 2, e);
							    printf("delete the num %d", e);
							        printf("\n");
								    for(i=0; i<L.length; ++i)
									        {
											        printf("%d ", L.elem[i]);   
												    }
								        printf("\n");
									    return 0;   
}

void initList_Sq(SqList &L)           
{//构造一个空的线性表L
	    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	        if(!L.elem)            //存储分配失败
			    {
				            exit(-1);
					        }
		    L.length = 0;            //空表长度为0
		        L.listsize = LIST_INIT_SIZE;             //初始存储容量
}

int listInsert_Sq(SqList &L, int i, ElemType e)
{//在第i个元素之前插入一个元素
	//i的合法值为 1 <= i && i <= L.length +1
	//    if(i < 1 || i > L.length + 1)
	//         {
	//                  return -1;
	//                       }
	//                           if(L.length >= L.listsize)
	//                               {//如果当前存储空间已满，增加分配
	//                                       ElemType *newbase = (ElemType *)realloc(L.elem,
	//                                                                        (L.listsize + LISTINCREMENT) * sizeof(ElemType));
	//                                                                                if(!newbase)
	//                                                                                        {
	//                                                                                                    exit(-1);
	//                                                                                                            }
	//                                                                                                                    L.elem = newbase;
	//                                                                                                                            L.listsize += LISTINCREMENT;
	//                                                                                                                                }
	//                                                                                                                                   
	//                                                                                                                                       ElemType *p, *q;
	//                                                                                                                                          
	//                                                                                                                                              q = &(L.elem[i-1]);            //q为要插入元素的位置
	//                                                                                                                                                  for(p=&(L.elem[L.length-1]); p>=q; --p)            //q之后的所有元素依次向后移动一位
	//                                                                                                                                                      {
	//                                                                                                                                                              *(p+1) = *p;   
	//                                                                                                                                                                  }
	//                                                                                                                                                                      *q = e;            //插入元素
	//                                                                                                                                                                          ++L.length;            //表长增加1
	//                                                                                                                                                                              return 0;
	//                                                                                                                                                                              }
	//
	//                                                                                                                                                                              int listDelete_Sq(SqList &L, int i, ElemType &e)
	//                                                                                                                                                                              {//将第i个元素删除，并用e返回
	//                                                                                                                                                                              //i的合法值为 1 <= i && i <= L.length
	//                                                                                                                                                                                  if(i < 1 || i > L.length)
	//                                                                                                                                                                                      {
	//                                                                                                                                                                                              return -1;
	//                                                                                                                                                                                                  }
	//                                                                                                                                                                                                     
	//                                                                                                                                                                                                         int *p, *q;
	//                                                                                                                                                                                                            
	//                                                                                                                                                                                                                p = &(L.elem[i-1]);            //p为要删除的元素的位置
	//                                                                                                                                                                                                                    e = *p;
	//                                                                                                                                                                                                                        q = L.elem + L.length - 1;    //表尾元素的地址
	//                                                                                                                                                                                                                            for(++p; p<=q; ++p)
	//                                                                                                                                                                                                                                {
	//                                                                                                                                                                                                                                        *(p-1) = *p;
	//                                                                                                                                                                                                                                            }
	//                                                                                                                                                                                                                                                --L.length;
	//                                                                                                                                                                                                                                                    return 0;
	//                                                                                                                                                                                                                                                    }
	//
	//
