#include<iostream>
using namespace std;
void bubble_Soft(int *temp, int length)
{
	int i, j;
	bool exchange;
	for(i=0;i<length-1;i++)
		for (j = 0;j < length - 1 - i;j++)
		{
			exchange = false; //�Ż�
			if (temp[j] > temp[j + 1])
			{
				int  swap_min = temp[j+1];
				temp[j + 1] = temp[j];
				temp[j] = swap_min;
				exchange = true;
			}
			if (exchange = false)
			{
				return;
			}
		}
}
int main()
{
	int temp[5];
	int length;
	cout << "���������������Ŀ��~." << endl;
	cin >> length;
	while (true)
	{
		//cin.get();
		if (length > 5) {
			cout << "------��ʦ�����������ֻ����5������------" << endl;
			cout << "PLZ����inputһ��" << endl;
			cin >> length;
			continue;
			//cin.get();
		}
		cout << "�����������������~" << endl;
		for (int i = 0;i < 5;i++)
		{
			cin >> temp[i];
		}
		cin.get();
		bubble_Soft(temp, length);
		cout << "------�����������Ҫ�Ľ����~------" << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << temp[i]<<"<��o ";
		}
		cin.get();
		return 0;

	}
}