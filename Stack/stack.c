#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW 2
#define OK 1
typedef int SElemType;
typedef int Status;
typedef struct 
{
SElemType *base;
SElemType *top;
int stacksize;
}SqStack;
Status InitStack(SqStack S)/*定义一个空栈*/
{
S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
if(!S.base) exit(OVERFLOW);
S.top=S.base;/*顶等于底*/
S.stacksize=STACK_INIT_SIZE;
return OK;
}
Status ChuShihua(SqStack S)
{
int n;
printf("请输入数据以-1结束\n");
while(scanf("%d",&n),n!=-1)
*S.top++=n;
return OK;
}
Status Push(SqStack S)
{
int e;
printf("请输入要压入的元素：");
scanf("%d",&e);
if(S.top-S.base>=S.stacksize)/*栈已满*/
{
S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
if(!S.base)
exit(OVERFLOW);
S.top=S.base+S.stacksize;
S.stacksize+=STACKINCREMENT;
}
*S.top++=e;
return OK;
}
Status Pop(SqStack S)
{
printf("出栈元素为：");
if(S.top!=S.base)
printf("%d\n",*--S.top);/*删除栈顶元素*/
return 0;
}
void tishi()
{
printf("所有操作如下：\n");
printf("（1）采用顺序存储实现栈的初始化操作。\n");
printf("（2）采用顺序存储实现栈的入栈操作。\n");
printf("（3）采用顺序存储实现栈的出栈操作。\n");
printf("（-1）退出\n");
printf("请选择：");
}
int main()
{
int m;
SqStack s;
InitStack(s);
do{
tishi();
scanf("%d",&m);
switch(m)
{
case 1:
	ChuShihua(s);								             break;
													            case 2:
													                Push(s);
															           break;
																          case 3:
																              Pop(s);
																	                 break;
																			        }
						    }while(m!=-1);
		       return OK;
}
