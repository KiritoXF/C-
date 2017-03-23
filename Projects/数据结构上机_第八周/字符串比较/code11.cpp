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
	cout << "ÊäÈë×Ö·û´®1£º" << endl;
	cin >> p;
	cout << "ÊäÈë×Ö·û´®2£º" << endl;
	cin >> t;
	int i = Strcmp(p, t);
	if (i == 1)
		cout << "×Ö·û´®1´ó" << endl;
	if (i == -1)
		cout << "×Ö·û´®2´ó" << endl;
	else
		cout << "Á½¸ö×Ö·û´®ÏàµÈ" << endl;
}
