#include<iostream>
using namespace std;

int Strcmp(char * s1, char * s2)
{
	int count = 0;
	while (s1[count] != '\0' && s2[count] != '\0')
	{
		if (s1[count] > s2[count])
			return 1;
		else if (s1[count] < s2[count])
			return -1;
		count++;
	}
	if (s1[count] == '\0' && s2[count] != '\0')
		return -1;
	else if (s1[count] != '\0' && s2[count] == '\0')
		return 1;
	return 0;
}
void main()
{
	char p[100];
	char t[100];
	cout << "�����ַ���1��" << endl;
	cin >> p;
	cout << "�����ַ���2��" << endl;
	cin >> t;
	int i = Strcmp(p, t);
	if (i == 1)
		cout << "�ַ���1��" << endl;
	if (i == -1)
		cout << "�ַ���2��" << endl;
	else
		cout << "�����ַ������" << endl;
}
