#include <iostream>
using namespace std;

int main()
{
	int arr[4] = { 0 };
	int i = 0, j = 0;
	double temp = 0;
	cout << "请输入四个随机的浮点数:" << endl;
	for (i = 0;i < 4;i++)
	{
		cin >> arr[i];
	}
	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 3;j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "这四个浮点数按照从小到大的顺序输出:" << endl;
	for (i = 0;i < 4;i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << "********************201493066,杨航**************" << endl;
	return 0;
}