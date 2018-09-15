#include<iostream>
using namespace std;
void bubble_Soft(int *temp, int length)
{
	int i, j;
	bool exchange;
	for(i=0;i<length-1;i++)
		for (j = 0;j < length - 1 - i;j++)
		{
			exchange = false; //优化
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
	cout << "请输入你的数据数目喵~." << endl;
	cin >> length;
	while (true)
	{
		//cin.get();
		if (length > 5) {
			cout << "------老师嗦了最多数据只能有5个喵！------" << endl;
			cout << "PLZ重新input一下" << endl;
			cin >> length;
			continue;
			//cin.get();
		}
		cout << "请输入你的数据们喵~" << endl;
		for (int i = 0;i < 5;i++)
		{
			cin >> temp[i];
		}
		cin.get();
		bubble_Soft(temp, length);
		cout << "------下面就是你需要的结果喵~------" << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << temp[i]<<"<。o ";
		}
		cin.get();
		return 0;

	}
}