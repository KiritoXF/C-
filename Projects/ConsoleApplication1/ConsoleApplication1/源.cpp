#include <iostream>
using namespace std;

int main()
{
	int arr[4] = { 0 };
	int i = 0, j = 0;
	double temp = 0;
	cout << "�������ĸ�����ĸ�����:" << endl;
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
	cout << "���ĸ����������մ�С�����˳�����:" << endl;
	for (i = 0;i < 4;i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << "********************201493066,�**************" << endl;
	return 0;
}