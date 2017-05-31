/*
  二叉树的基本操作包括：创建，遍历，转化，复制，删除等。
  核心思想：递归调用
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef char ELemType;//等价 数据类型 为了使代码风格优雅

//存储结构（孩子兄弟表示法）
struct typedef BiTreeNode 
{
   ELemType data;//char  数据域
   BiTreeNode *lchild; //指向左孩子的指针
   BiTreeNode *rchild; //指向右孩子的指针
}BiTreeNode,*BiTree; //定义结构体的同时，定义了两个新数据类型 <<=


void CreateBiTree(BiTree *T);//建立
void DestroyBiTree(BiTree *T);//销毁
void PreOrderTravel(BiTree *T);//先序遍历
void InOrderTravel(BiTree *T)//中序遍历
void PostOrderTravel(BiTree *T);//后序遍历


int main(void)
{
   BiTree *T;
   T=NULL;
   
   CreateBiTree(T);//创建

   printf("\n\n先序遍历输出\n");//先序遍历
   PreOrderTravel(T);
   
   printf("\n\n中序遍历输出\n");//中序遍历
   InOrderTravel(T);

   printf("\n\n后序遍历输出\n");//后序遍历
   PostOrderTravel(T);

   printf("\n\n树的深度\n");//树的深度
   DepthOfBiTree(T);

   printf("\n\n销毁树\n");
   DestroyBiTree(T);
}


/*创建树（利用先序序列建立）*/
void CreateBiTree(BiTree *T)
{
   TElemType ch;
   scanf("%c",&ch);
   
   /*约定输入字符'#'为结束符。如果接收到的ch字符为'#' ,则T为空树*/
   if(ch=='#') *T=NULL;
   else{
      *T=(BiTree *)malloc(sizeof(BiTree));
      if(*T){  //如果分配成功了         
         T->data=ch; //T的数据域赋新值 ch
         CreateBiTree(&(*T)->lchild);//递归创建，将T->l
         CreateBiTree(&(*T)->rchild);//依次(根左右)创建 子树
          } 
      else{
         exit(OVERFLOW);//分配失败。退出并返回 内存溢出 错误。
      }//else
   }//else
}
   
   
/*销毁二叉树（递归）遍历销毁*/
void DestroyBiTree(BiTree *T)
{
    if(*T==NULL) return;//如果传入的T是空树，则直接返回。
    else
    {
        DestroyBiTree(T->lchild);//遍历销毁
        DestroyBiTree(T->rchild);
        free(*T);//释放指针，放在最后是为了 先释放树枝上的数据，以保证正确性。
    }
}


/*创建树（利用广义表建立）
  输出（利用广义表输出）
  输出：先序遍历
*/
void PreOrderTravel(BiTree *T)
{
    if(*T)
    {
        printf("%c",T->data);//输出根节点的值
        PreOrderTravel(T->lchild);//遍历左子树
        PreOrderTravel(T->rchild);//遍历右子树
    }
}


/*输出：中序遍历*/
void InOrderTravel(BiTree *T)
{
    if(*T)
    {
        InOrderTravel(T->lchild);//遍历左子树
        printf("%c",T->data);//输出根节点的值
        InOrderTravel(T->rchild);//遍历右子树
    }
}


/*输出：后序遍历*/
void PostOrderTravel(BiTree *T)
{
    if(*T)
    {
        PostOrderTravel(T->lchild);//遍历左子树
        PostOrderTravel(T->rchild);//遍历右子树
        printf("%c",T->data);//输出根节点的值
    }
}


/*递归求树的深度*/
int DepthOfBiTree(const BiTree *T)  
{  
    int ldepth;  //定义两个变量，用来存储 左右子树的深度
    int rdepth;  
      
    if(*T==NULL) return 0;//空树  
    else{
        ldepth = DepthOfBiTree(T->lchild);//递归遍历左右子树
        rdepth = DepthOfBiTree(T->rchild);  
    }
    
    return (ldepth>rdepth)?(ldepth+1):(rdepth+1);//谁大谁表示深度，往上层反馈
}  
