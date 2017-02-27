#include <stdio.h>                           //建立表的顺序流程
#include <string.h>                          //弊端，
#include <stdlib.h>               //包含malloc的头文件
struct node                          //定义结构体   
{
    int num;
    struct node *next;
};

int main()
{
int m;

printf("请输入选项\n");
scanf("%d",&m);
switch(m){
	case 1:
		struct node *creat();
		break;
	case 2:
		struct node *delete();
		break;
}
void print();
struct node *head;       //定义头指针
head=NULL;                 //建一个空表
head=creat(head);        //创建单链表
print(head);                   //打印单链表
}

struct node *creat(struct node *head)   //函数返回的是与节点相同类型的指针
{
struct node *p1,*p2;     //双循环
p1=p2=(struct node *)malloc(sizeof(struct node));//申请新节点
printf("输入新节点的值\n");//输入新节点的值
scanf("%d",&p1->num);
p1->next=NULL;//将新节点的指针置为空
while(p1->num>0)
{
if(head==NULL)
head=p1;//空表，接入表头
else
p2->next=p1;//非空表，接入表尾
p2=p1;
p1=(struct node *)malloc(sizeof(struct node));
scanf("%d",&p1->num);
}
return head;//返回链表的头指针
}

void print(struct node *head)
{
struct node *temp;
temp=head;
while(temp!=NULL)
{
printf("%d\n",temp->num);
temp=temp->next;//跟踪链表增长
}
}

struct node *delete(struct node *head,char n[10])
{
struct node *p0,*p1,*p2;//p1是前驱,p2是后驱
p0=(struct node *)malloc(sizeof(struct node));
strcpy(p0->num,n);
scanf("%d",&p1->num);
p1=head->next;
p2=head;

while((p2->next!=NULL)&&strcmp(p1->num,n)<0)
{
p2=p1;
p1=p1->next;
}
p0->next=p1;
p2->next=p0;

return head;
}
