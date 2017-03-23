#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

int strlen(char *s)
{
	int count = 0;	while (s[count] != '\0')
		count++;
	return count;
}
int * Next(char * P)
{
	int m = strlen(P);
	assert(m > 0);
	int *N = new int[m];
	assert(N != 0);
	N[0] = 0;
	for (int i = 1;i < m;i++)
	{
		int k = N[i - 1];
		while (k > 0 && P[i] != P[k])
			k = N[k - 1];
		if (P[i] == P[k])
			N[i] = k + 1;
		else
			N[i] = 0;
	}
	return N;
}
int KMP(char* T, char* P, int *N, int startIndex)
{
	int lastIndex = strlen(T) - strlen(P);
	if ((lastIndex - startIndex) < 0)
		return -1;
	int i;
	int j = 0;
	for (i = startIndex; i < strlen(T);i++)
	{
		while (P[j] != T[i] && j > 0)
			j = N[j - 1];
		if (P[j] == T[i])
			j++;
		if (j == strlen(P))
			return (i - j + 1);
	}
	return -1;
}
int main()
{
	char* s1("abcddlucbadlutabc");
	char* s2("dlut");
	int *next = Next(s1);
	cout << KMP(s1, s2, next, 1) + 1 << endl << endl;
	int i = 0;
	char* c("abcaabbcabcaabdab");
	int m = strlen(c);
	int *test = Next(c);
	for (i = 0;i < m;i++)
	{
		cout << test[i];
	}
	cout << endl;
	return 0;
}
