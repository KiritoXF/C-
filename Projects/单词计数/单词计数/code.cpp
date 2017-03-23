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
	int temp = 0;//最后计算重复单词数
	int spacetemp = 0;
	string space[20] = { "" };
	int strcmp(char *str1, char *str2);
	while ((str[i] = getchar()) != '\n')
	{
		i++;
	}//计算字符串的长度
	str[i] = '\0';
	int num = 0, n1[100], n2[100];
	string stri1[100] = { "" }, stri2[100];
	n1[0] = -1;//辅助判定新的单词数
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' /*&& str[i + 1] != ' '*/)
		{
			num++;//单词数+1
			n1[num] = i;//这样新的断点处的值就大于0，在结尾处即可进行判定重复单词的数量
		}
	}
	num++;
	n1[num] = i;
	for (i = 0; i<num; i++)
	{
		for (int m = n1[i] + 1; m<n1[i + 1]; m++)//这是第i个单词，截取的一段就是以空格作区分
			stri1[i] += str[m];//把这个单词传递给stri1字符串
	}
	int m = 0;
	bool f = true;//初始设定不想等
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
		}//判断单词是否重复
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
	}//用来计算单词及其数量，与下方呼应
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
	}//用来输出单词及其数量，与上方呼应
	for (i = 0; i < 50;i++)
	{
		if (n2[i] > 1)
		{
			temp++;
		}
	}
	cout << "共有" << num - spacetemp << "个单词" << endl;
	cout << "共有" << temp  << "个重复的单词" << endl;
	return 0;
}