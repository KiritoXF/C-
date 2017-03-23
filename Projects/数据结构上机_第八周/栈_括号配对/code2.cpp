#include<iostream>
using namespace std;
//此程序存在的不足是，当输入的式子右括过多时，会重复打印“栈为空，不能出栈”的提示
//并且……程序君并不打算优化
class stack
{
private:
	int maxsize;
	int top;
	char *st;
public:
	stack()
	{
		top = -1;
	}
	stack(int size)
	{
		top = -1;
		maxsize = size;
		st = new char[maxsize];
	}
	~stack()
	{
		delete[]st;
	}
	void clear()
	{
		top = -1;
	}
	bool push(char item)
	{
		if (top == maxsize - 1)
		{
			char * newst = new char[maxsize * 2];
			for (int i = 0;i <= top;i++)
			{
				newst[i] = st[i];
			}
			delete[]st;
			st = newst;
			maxsize *= 2;
		}
		st[++top] = item;
		return true;
	}
	char pop()
	{
		if (top == -1)
		{
			cout << "栈为空，不能出栈" << endl;
			//cout << "配对失败，缺少对应的左括号" << endl;
			return false;
		}
		else
		{
			char item;
			item = st[top--];
			return item;
		}
	}
	bool Top(char item)
	{
		if (top == -1)
		{
			cout << "栈为空，不能读取栈顶元素" << endl;
			return false;
		}
		else
		{
			item = st[top];
			return true;
		}
	}
	int gettop()
	{
		return top;
	}
};
void judgement(char *code)
{
	stack s1(10);
	stack s2(10);
	for (int i = 0;i < 30;i++)
	{
		if (code[i] == '(')
		{
			s1.push('(');
		}
		else if (code[i] == ')')
		{
			if (s1.gettop() == -1) s2.push(')');
			s1.pop();
		}
	}
	if (s1.gettop() != -1)
	{
		cout << "配对失败，缺少对应的右括号" << endl;
	}
	else if (s2.gettop() != -1)
	{
		cout << "配对失败，缺少对应的左括号" << endl;
	}
	else
	{
		cout << "配对成功" << endl;
		cout << "表达式为：" << code << endl;
	}
}
int main()
{
	cout << "括号配对：" << endl << endl;
	char code[30];
	cout << "请输入一个30字符以内的式子：" << endl;
	cin >> code;
	judgement(code);
	return 0;
}