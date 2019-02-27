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
		T = new BiTreeNode; //开辟空间
		T->data = input_biTree;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}
void preOrder(BiTree T)//先序
{
	if (T)
	{
		cout << T->data << " ";
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(BiTree T)//中序
{
	if (T)
	{
		inOrder(T->lchild);
		cout << T->data << " ";
		inOrder(T->rchild);
	}
}

void postOrder(BiTree T)//后序
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
	cout<<"先序遍历结果:";
	preOrder(T);
	cout<<"\n\n";
	cout<<"中序遍历结果:";
	inOrder(T);
	cout<<"\n\n";
	cout<<"后序遍历结果:";
	postOrder(T);
	cout<<"\n";
}
int main()
{
	cout << "请输入你的二叉树：" << endl;
	createBiTree(T);
	showTraverseResult();
	system("pause");
	return 0;
}
