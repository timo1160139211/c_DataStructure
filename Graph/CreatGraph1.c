#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100  //最大顶点数为100
typedef int VertexType;
//表节点
typedef struct ArcNode
{
   int adjvex;//该弧指向的顶点的位置
   struct ArcNode *nextarc;//指向下一条弧的指针
}ArcNode;
//头节点
typedef struct VNode
{
   VertexType data;//顶点信息
   ArcNode *firstarc;//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];
//记录图的顶点数和弧数
typedef struct
{
   AdjList vertices;
   int vexnum,arcnum;//图的当前顶点数和弧数
   int kind;//图的种类标志
}ALGraph;

//创建图
void CreateALGraph(ALGraph *G)
{
   int i,j,k;
   ArcNode *s;

   printf("intput data:顶点数，边数:\n");
   scanf("%d%d",&G->vexnum,&G->arcnum);
   printf("\nplease v data:");

   for(i=0;i<G->vexnum;i++)
   {
   scanf("%d",&G->vertices[i].data);//输入顶点数据
   G->vertices[i].firstarc=NULL;//边的相关指针
   }

   for(k=0;k<G->arcnum;k++)
   {
   printf("please input arc<i,j>\n");
   scanf("%d%d",&i,&j);

   s=(ArcNode *)malloc(sizeof(ArcNode));

   s->adjvex=j;
   s->nextarc=G->vertices[i].firstarc;
   G->vertices[i].firstarc=s;
   }
}

void CreateALGraph(ALGraph *G);

int main(void)
{
   ALGraph G;

   CreateALGraph(&G);
}
