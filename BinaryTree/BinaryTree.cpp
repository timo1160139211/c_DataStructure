/*
  ����˼�룺�ݹ����
*/
#include "stdio.h"
#include "stdlib.h"

typedef struct BiTNode{
	char data;						//char  ������
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;					//����BiTree Ϊָ�����͡� 

//���������� 
BiTree CreateBiTree(){
	char ch;
	BiTree T;//����ָ�� T 
	scanf("%c",&ch);
	 /*Լ�������ַ�'#'Ϊ��������������յ���ch�ַ�Ϊ'#' ,��TΪ����*/
	if(ch=='#') T=NULL;
	else{
		//�������ʧ����ֱ���˳�   
		if(!(T=(BiTree)malloc(sizeof(BiTNode)))) return(0);
		
		//��� û���˳� �����ɹ��ˣ����� 
		T->data=ch; //T����������ֵ ch
		T->lchild=CreateBiTree();//�ݹ鴴������T->l
		T->rchild=CreateBiTree();;//����(������)���� ����
	}
	return T;//����ָ�� T 
}

//������� 
void preorder(BiTree root){
	if(root){
		printf("%c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

//������� 
void inorder(BiTree root){
	if(root){
		inorder(root->lchild);
		printf("%c",root->data);
		inorder(root->rchild);
	}
}

//������� 
void postorder(BiTree root){
	if(root){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c",root->data);
	}
}

//��������� 
int depth(BiTNode *t){
	int dep1,dep2;//�������������������洢 �������������
	if(t==NULL) return(0);//���� 

	else {
		dep1=depth(t->lchild);//�ݹ������������
		dep2=depth(t->rchild);
		
		if(dep1>dep2) {//˭��˭��ʾ��ȣ����ϲ㷴��
			return(dep1+1);
		}else{
			return(dep2+1);
		}
	}
}




int main(){

	BiTNode *T;

	//���������� 
	printf("�밴������˳��������Ҫ�����Ķ�����(�պ�����#��ʾ����\n");
	T=CreateBiTree();
	
	printf("\n��������˶����� ");
	preorder(T);
				
	printf("\n��������˶����� ");
	inorder(T);
				
	printf("\n��������˶����� ");
	postorder(T);

	printf("\n�ö����������Ϊ��%d\n\n",depth(T));

	return 1;
}
