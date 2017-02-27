/* 邻接矩阵表示的图结构*/
#include <stdio.h>
#include <stdlib.h>
 
typedef char VertexType;        //顶点类型应由用户定义
typedef int EdgeType;           //边上的权值类型应由用户定义
 
#define MAXVEX  100             //最大顶点数，应由用户定义
#define INFINITY    65535       //用65535来代表无穷大
 
//邻接矩阵结构
typedef struct
{
    VertexType vexs[MAXVEX];    //顶点表
    EdgeType   arc[MAXVEX][MAXVEX]; //邻接矩阵，可看作边
    int numVertexes, numEdges;      //图中当前的顶点数和边数
}Graph;
 
//定位
int locates(Graph *g, char ch)
{
    int i = 0;
    for(i = 0; i < g->numVertexes; i++)
    {
        if(g->vexs[i] == ch)
        {
            break;
        }
    }
    if(i >= g->numVertexes)
    {
        return -1;
    }
     
    return i;
}
 
//建立一个无向网图的邻接矩阵表示
void CreateGraph(Graph *g)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &(g->numVertexes), &(g->numEdges));
     
    printf("%d %d\n", g->numVertexes, g->numEdges);
 
    for(i = 0; i < g->numVertexes; i++)
    {
        printf("请输入顶点%d:\n", i);
        g->vexs[i] = getchar();
        while(g->vexs[i] == '\n')//结束标志符
        {
            g->vexs[i] = getchar();
        }
    }
     
    for(i = 0; i < g->numVertexes; i++)
    {
        printf("%c ", g->vexs[i]);
    }
    printf("\n");
 
 
    for(i = 0; i < g->numEdges; i++)
    {
        for(j = 0; j < g->numEdges; j++)
        {
            g->arc[i][j] = INFINITY; //邻接矩阵初始化
        }
    }
    for(k = 0; k < g->numEdges; k++)
    {
        char p, q;
        printf("输入边(vi,vj)上的下标i，下标j和权值:\n");
         
        p = getchar();
        while(p == '\n')
        {
            p = getchar();
        }
        q = getchar();
        while(q == '\n')
        {
            q = getchar();
        }
        scanf("%d", &w);    
         
        int m = -1;
        int n = -1;
        m = locates(g, p);
        n = locates(g, q);
        if(n == -1 || m == -1)
        {
            fprintf(stderr, "there is no this vertex.\n");
            return;
        }
        //getchar();
        g->arc[m][n] = w;
        g->arc[n][m] = g->arc[m][n];  //因为是无向图，矩阵对称
    }
}
 
//打印图
void printGraph(Graph g)
{
    int i, j;
    printf("构建的邻接矩阵如下所示.\n");
    for(i = 0; i < g.numVertexes; i++)
    {
        for(j = 0; j < g.numVertexes; j++)
        {
            printf("%5d  ", g.arc[i][j]);
        }
        printf("\n");
    }
}
 
//prime算法最小生成树
void MiniSpanTree_Prime(Graph g)
{
    int min, i, j, k;
    int adjvex[MAXVEX];         //保存相关顶点下标
    int lowcost[MAXVEX];        //保存相关顶点间边的权值
    lowcost[0] = 0;             //初始化第一个权值为0，即v0加入生成树
    adjvex[0] = 0;              //初始化第一个顶点下标为0

    for(i = 1; i < g.numVertexes; i++)
    {
        //循环除下标为0外的全部顶点
        lowcost[i] = g.arc[0][i];   //将v0顶点与之有边的权值存入数组
        adjvex[i] = 0;              //初始化都为v0下标
    }
    for(i = 1; i < g.numVertexes; i++)
    {
        min = INFINITY;             //初始化最小权值为无穷大
        j = 1;
        k = 0;
        while(j < g.numVertexes) //循环全部顶点
        {
            //如果权值不为0,且权值小于min
            if(lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];       //则让当前权值成为最小值
                k = j;                  //将当前最小值的下标存入k
            }
            j++;
        }
        printf("(%d,%d)", adjvex[k], k); //打印当前顶点边中权值最小边
        lowcost[k] = 0;                 //将当前顶点的权值设置为0，表示此顶点已经完成任务
 
        for(j = 1; j < g.numVertexes; j++)//循环所有顶点
        {
            if(lowcost[j] != 0 && g.arc[k][j] < lowcost[j])
            {
                //若下标为k的顶点各边权值小于此前这些顶点未被加入的生成树权值
                lowcost[j] = g.arc[k][j];
                adjvex[j] = k;              //将下标为k的顶点存入adjvex
            }
        }
    }
    printf("\n");
}
 
int main(int argc, char **argv)
{
    Graph g;
     
    //邻接矩阵创建图
    CreateGraph(&g);
    //打印网图
    printGraph(g);
    //求最小生成树
    MiniSpanTree_Prime(g);
 
    return 0;
}
