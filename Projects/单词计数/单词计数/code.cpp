#include <iostream>  
#include <string>  
#include <stdio.h>  
using namespace std;

int strcmp(char *str1, char *str2)
{
	if (str1 < str2)
		return -1;
	if (str2 == str1)
		return 0;
	if (str1 > str2)
		return 1;
}
int main()
{
	char str[1000];
	int i = 0;
	int temp = 0;//�������ظ�������
	int spacetemp = 0;
	string space[20] = { "" };
	int strcmp(char *str1, char *str2);
	while ((str[i] = getchar()) != '\n')
	{
		i++;
	}//�����ַ����ĳ���
	str[i] = '\0';
	int num = 0, n1[100], n2[100];
	string stri1[100] = { "" }, stri2[100];
	n1[0] = -1;//�����ж��µĵ�����
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' /*&& str[i + 1] != ' '*/)
		{
			num++;//������+1
			n1[num] = i;//�����µĶϵ㴦��ֵ�ʹ���0���ڽ�β�����ɽ����ж��ظ����ʵ�����
		}
	}
	num++;
	n1[num] = i;
	for (i = 0; i<num; i++)
	{
		for (int m = n1[i] + 1; m<n1[i + 1]; m++)//���ǵ�i�����ʣ���ȡ��һ�ξ����Կո�������
			stri1[i] += str[m];//��������ʴ��ݸ�stri1�ַ���
	}
	int m = 0;
	bool f = true;//��ʼ�趨�����
	for (i = 0; i<num; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if (stri2[j] == stri1[i])
			{
				f = false;
				break;
			}
			else
			{
				f = true;
			}
		}//�жϵ����Ƿ��ظ�
		if (f)
		{
			stri2[m++] = stri1[i];
		}
	}
	for (i = 0; i<m; i++)
	{
		int l = 0;
		for (int n = 0; n<num; n++)
			if (stri2[i] == stri1[n])
				l++;
		n2[i] = l;
	}//�������㵥�ʼ������������·���Ӧ
	int sum = 0;
	for (i = 0; i<m; i++)
	{
		/*for (int j = 0;j<strlen(stri2[i]);i++)
		{
			if (0xff & int(stri2[i]) > 0x20) { flag = 0;break; };
		}*/
		//if (strcmp(stri2[i],space[i]))
		if (stri2[i] != "")
		cout << stri2[i] << ' ' << n2[i] << endl;
		if (stri2[i] == "" || stri2[i] == " " || stri2[i] == "   ")
			spacetemp++;
		sum += n2[i];
	}//����������ʼ������������Ϸ���Ӧ
	for (i = 0; i < 50;i++)
	{
		if (n2[i] > 1)
		{
			temp++;
		}
	}
	cout << "����" << num - spacetemp << "������" << endl;
	cout << "����" << temp  << "���ظ��ĵ���" << endl;
	return 0;
}