/*
  核心思想：递归调用
*/
#include "stdio.h"
#include "stdlib.h"

typedef struct BiTNode{
	char data;						//char  数据域
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;					//定义BiTree 为指针类型。 

//创建二叉树 
BiTree CreateBiTree(){
	char ch;
	BiTree T;//定义指针 T 
	scanf("%c",&ch);
	 /*约定输入字符'#'为结束符。如果接收到的ch字符为'#' ,则T为空树*/
	if(ch=='#') T=NULL;
	else{
		//如果分配失败了直接退出   
		if(!(T=(BiTree)malloc(sizeof(BiTNode)))) return(0);
		
		//如果 没有退出 则分配成功了：继续 
		T->data=ch; //T的数据域赋新值 ch
		T->lchild=CreateBiTree();//递归创建，将T->l
		T->rchild=CreateBiTree();;//依次(根左右)创建 子树
	}
	return T;//返回指针 T 
}

//先序遍历 
void preorder(BiTree root){
	if(root){
		printf("%c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

//中序遍历 
void inorder(BiTree root){
	if(root){
		inorder(root->lchild);
		printf("%c",root->data);
		inorder(root->rchild);
	}
}

//后序遍历 
void postorder(BiTree root){
	if(root){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c",root->data);
	}
}

//求树的深度 
int depth(BiTNode *t){
	int dep1,dep2;//定义两个变量，用来存储 左右子树的深度
	if(t==NULL) return(0);//空树 

	else {
		dep1=depth(t->lchild);//递归遍历左右子树
		dep2=depth(t->rchild);
		
		if(dep1>dep2) {//谁大谁表示深度，往上层反馈
			return(dep1+1);
		}else{
			return(dep2+1);
		}
	}
}




int main(){

	BiTNode *T;

	//创建二叉树 
	printf("请按照先序顺序输入您要建立的二叉树(空孩子用#表示）：\n");
	T=CreateBiTree();
	
	printf("\n先序遍历此二叉树 ");
	preorder(T);
				
	printf("\n中序遍历此二叉树 ");
	inorder(T);
				
	printf("\n后序遍历此二叉树 ");
	postorder(T);

	printf("\n该二叉树的深度为：%d\n\n",depth(T));

	return 1;
}
