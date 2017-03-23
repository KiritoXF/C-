#include<iostream>
using namespace std;
//�˳�����ڵĲ����ǣ��������ʽ����������ʱ�����ظ���ӡ��ջΪ�գ����ܳ�ջ������ʾ
//���ҡ�����������������Ż�
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
			cout << "ջΪ�գ����ܳ�ջ" << endl;
			//cout << "���ʧ�ܣ�ȱ�ٶ�Ӧ��������" << endl;
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
			cout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;
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
		cout << "���ʧ�ܣ�ȱ�ٶ�Ӧ��������" << endl;
	}
	else if (s2.gettop() != -1)
	{
		cout << "���ʧ�ܣ�ȱ�ٶ�Ӧ��������" << endl;
	}
	else
	{
		cout << "��Գɹ�" << endl;
		cout << "���ʽΪ��" << code << endl;
	}
}
int main()
{
	cout << "������ԣ�" << endl << endl;
	char code[30];
	cout << "������һ��30�ַ����ڵ�ʽ�ӣ�" << endl;
	cin >> code;
	judgement(code);
	return 0;
}