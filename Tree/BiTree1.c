//二叉树的基本操作包括：创建，遍历，转化，复制，删除等。
//核心思想：递归调用
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef char ELemType;
//存储结构（孩子兄弟表示法）
struct typedef BiTreeNode 
{
   ELemType data;
   BiTreeNode *lchild;
   BiTreeNode *rchild;
}BiTreeNode,*BiTree;

void CreateBiTree(BiTree *T);
void DestroyBiTree(BiTree *T);
void PreOrderTravel(BiTree *T);
void InOrderTravel(BiTree *T)
void PostOrderTravel(BiTree *T);

int main(void)
{
   BiTree *T;
   T=NULL;
   
   CreateBiTree(T);//创建

   printf("先序遍历输出\n");//先序遍历
   PreOrderTravel(T);
   
   printf("中序遍历输出\n");//中序遍历
   InOrderTravel(T);

   printf("后序遍历输出\n");//后序遍历
   PostOrderTravel(T);

   printf("树的深度\n");//树的深度
   DepthOfBiTree(T);

   printf("销毁树\n");
   DestroyBiTree(T);
}



//创建树（利用先序序列建立）
void CreateBiTree(BiTree *T)
{
   TElemType ch;
   scanf("%c",&ch);
   if(ch=='#')
   *T=NULL;
   else
   {
   *T=(BiTree *)malloc(sizeof(BiTree));
   if(!*T)
   exit(OVERFLOW);//分配失败
   T->data=ch;
   CreateBiTree(&(*T)->lchild);//递归调用
   CreateBiTree(&(*T)->rchild);//递归调用
   }
}
//销毁二叉树（递归）遍历销毁
void DestroyBiTree(BiTree *T)
{
   if(*T==NULL)
   return;
   else
   {
   DestroyBiTree(T->lchild);//遍历销毁
   DestroyBiTree(T->rchild);
   free(*T);
   }
}
//创建树（利用广义表建立）
//输出（利用广义表输出）
//输出：先序遍历
void PreOrderTravel(BiTree *T)
{
   if(*T)
   {
   printf("%c",T->data);//输出根节点的值
   PreOrderTravel(T->lchild);//遍历左子树
   PreOrderTravel(T->rchild);//遍历右子树
   }
}
//输出：中序遍历
void InOrderTravel(BiTree *T)
{
   if(*T)
   {
   InOrderTravel(T->lchild);//遍历左子树
   printf("%c",T->data);//输出根节点的值
   InOrderTravel(T->rchild);//遍历右子树
   }
}
//输出：后序遍历
void PostOrderTravel(BiTree *T)
{
   if(*T)
   {
   PostOrderTravel(T->lchild);//遍历左子树
   PostOrderTravel(T->rchild);//遍历右子树
   printf("%c",T->data);//输出根节点的值
   }
}
//递归求数的深度
int DepthOfBiTree(const BiTree *T)  
{  
    int ldepth;  
    int rdepth;  
      
    if(*T==NULL)//空树   
        return 0;  
    ldepth = DepthOfBiTree(T->lchild);
    rdepth = DepthOfBiTree(T->rchild);  
      
    return (ldepth>rdepth)?(ldepth+1):(rdepth+1);//谁大谁表示深度
}  
//递归求树的叶子节点个数

