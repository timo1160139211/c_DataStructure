//邻接表的深度优先递归算法
//设置访问标志数组

void DFS(ALGraph &G,int i)
{
   ArcNode *p;

   visited[i]=TRUE;
   printf("%c",G->VNode[i].data);//打印顶点数据
   p=G->VNode[i].fistarc;

   while(p)
   {
   if(!visited[p->adjvex])
	   DFS(G,p->adjvex);//对未访问的定点递归调用
   p=p->nextarc;//指向下一个节点
   }
}
//邻接表的深度遍历操作
//全局变量的声明
Boolean visited[MAXSIZE];//访问标志数组
Status (* VisitFuc)(int v)//函数变量

void DFSTravel(ALGraph &G,Status (* Visit)(int v))
{
   VisitFuc=visit;//使用全局变量VisitFuc,使DFS不必设函数指针参数

   int i;

   for(i=0;i<G->vexnum;i++)
	   visited[i]=FALSE;//初始化使所有顶点都是未访问状态
   for(i=0;i<G->vexnum;i++)
	   if(!visited[i])
		   DFS(G,i);//对未访问过的顶点调用DFS，若是联通图，只调用一次
}
