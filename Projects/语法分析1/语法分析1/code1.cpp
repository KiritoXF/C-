#include <iostream>
using namespace std;
char st[20];   //存储输入句子
int i = 0;      //数组下标
void E();
void R();//E'
void T();
void H();//T'
void F();
//***********************************
//检错部分
int comp(char s1, string s2);
int error_check(int n);
string firfol[5] = { "(i",")+e","(i","+*)e","(i" };
string synch[5] = { ")","","+)","","+*)" };
char s[5] = { 'E','R','T','H','F' };
int error_check(int n) {
	if (comp(st[i], synch[n]) == 1) {
		cout << "弹出非终结符" << s[n] << "，用户少输入了一个id" << endl;
		return 0;
	}
	else while (comp(st[i], firfol[n]) == 0 && comp(st[i], synch[n]) == 0 && st[i] != '#') {
		cout << "输入串跳过记号" << st[i] << "，用户多输入了一个" << st[i] << endl;
		i++;
	}
	return 1;
}
int comp(char s1, string s2) {
	for (int j = 0;j<s2.length();j++) {
		if (s1 == s2[j])
			return 1;
	}
	return 0;
}
//*****************************
void main() {
	cout << "使用的文法为：\nE->TE'\nE'->+TE'|e\nT->FT'\nT'->*FT'|e\nF->(E)|id\n";
	cout << "-------------------" << endl;
	cout << "输入待检测串(以 # 结束):" << endl;
	cin >> st;
	cout << "-------------------" << endl;
	cout << endl;
	E();
	if (st[i] != '#') {
		cout << "输入串跳过记号 " << st[i] << ",用户多输入了一个" << st[i] << endl;
		i++;
		E();
	}system("pause");
}


void E() {
	if (error_check(0) == 0 || st[i] == '#');
	else {
		cout << "E->TE'" << endl;
		T();
		R();
	}
}


void R() {
	if (error_check(1) == 0);
	else {
		if (st[i] == '+') {
			cout << "E'->+TE'" << endl;
			i++;
			T();
			R();
		}
		else
			cout << "T'->e" << endl;
	}
}
void T() {
	if (error_check(2) == 0);
	else {
		cout << "T->FT'" << endl;
		F();
		H();
	}
}
void H() {
	if (error_check(3) == 0);
	else {
		if (st[i] == '*') {
			cout << "T'->*FT'" << endl;
			i++;
			F();
			H();
		}
		else
			cout << "T'->e" << endl;
	}
}


void F() {
	if (error_check(4) == 0);
	else {
		if (st[i] == 'i') {
			i++;
			if (st[i] == 'd')
			{
				cout << "F->id" << endl;
				i++;
			}
		}
		else
			if (st[i] == '(') {
				cout << "F->(E)" << endl;
				i++;
				E();
				if (st[i] == ')') {
					i++;
				}
				else if (st[i] != ')')
					cout << "括号不匹配" << endl;
			}
	}
}