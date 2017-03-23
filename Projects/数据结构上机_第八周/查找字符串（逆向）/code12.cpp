#include<iostream>
using namespace std;

int find(string s, string c)
{
	int count = 0,len = 0,x = 0, m;
	while (s[count] != '\0')
		count++;
	while (c[len] != '\0')
		len++;
	while (count >= 0 && s[count] != c[0])
		count--;
	if (count<0)
		return -1;
	else
	{
		m = count + 1;
		x = 1;
		for (int k = 1;k<len;k++, m++)
		{
			if (c[k] == s[m])
				x++;
		}
		if (x == len)
			return count + 1;
		else
			return -1;
	}
}
void main()
{
	char *p = "substrstrstrstrasstrdlut";
	char *t = "str";
	int n = find(p, t);
	if (n == -1)
		cout << "没出现" << endl;
	else
		cout << "最后一次出现的位置为：" << n << endl;
}