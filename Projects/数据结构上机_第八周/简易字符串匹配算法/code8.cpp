#include <iostream>
#include <string>
using namespace std;

int matching(const string & T, const string & P)
{
	int p = 0;
	int t = 0;
	int plen = P.length();
	int tlen = T.length();
	if (tlen < plen)
	{
		return -1;
	}
	else
	{
		while (p < plen && t < tlen)
		{
			if (T[t] == P[p])
			{
				p++;
				t++;
			}
			else
			{
				t = t - p + 1;
				p = 0;
			}
		}
		if (p == plen)
		{
			return (t - plen + 1);
		}
		else
			return -1;
	}
}
int main()
{
	string t = "EDA_AmdwelcometoOurEDA_Android";
	string p = "OurEDA_Android";
	int k = matching(t, p);
	if (k == -1)
		cout << "×Ö·û´®²»Æ¥Åä" << endl;
	else
		cout << "µÚ" << k << "Î»ÖÃ¿ªÊ¼Æ¥Åä" << endl;
	return 0;
}