#include<iostream>
#include<Windows.h>
using namespace std;
int const MAXSIZE = 100;
typedef struct
{
	int data[MAXSIZE];
	int length;
}Seqlist;
void creatList(Seqlist &L)
{
	int creatNum = 0;
	cout << "����������Ҫ������Ԫ�ظ���" << endl;
	cin >> creatNum;
	for (int i = 0;i < creatNum;i++)
	{
		cin >> L.data[i];
		L.length++;
	}
}
void displayList(Seqlist L)
{
	cout << "���Ա��е�Ԫ��Ϊ:";
	for (int i = 0; i <L.length; i++)
	{
		cout << L.data[i] << endl;
	}
}
int main()
{
	Seqlist L;
	L.length = 0;
	creatList(L);
	displayList(L);
	//system("pause");
	return 0;
}