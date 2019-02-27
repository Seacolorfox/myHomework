#include<iostream>  
#include<windows.h>
using namespace std;

typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	char data;
}BiTreeNode, *BiTree;
BiTree T;
void createBiTree(BiTree &T)
{
	char input_biTree;
	cin >> input_biTree;
	if (input_biTree=='#')
		T = NULL;
	else
	{
		T = new BiTreeNode; //���ٿռ�
		T->data = input_biTree;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}
void preOrder(BiTree T)//����
{
	if (T)
	{
		cout << T->data << " ";
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(BiTree T)//����
{
	if (T)
	{
		inOrder(T->lchild);
		cout << T->data << " ";
		inOrder(T->rchild);
	}
}

void postOrder(BiTree T)//����
{
	if (T)
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		cout << T->data << " ";

	}
}

void showTraverseResult()
{
	cout << "------------------------------------------" << endl;
	cout<<"����������:";
	preOrder(T);
	cout<<"\n\n";
	cout<<"����������:";
	inOrder(T);
	cout<<"\n\n";
	cout<<"����������:";
	postOrder(T);
	cout<<"\n";
}
int main()
{
	cout << "��������Ķ�������" << endl;
	createBiTree(T);
	showTraverseResult();
	system("pause");
	return 0;
}
