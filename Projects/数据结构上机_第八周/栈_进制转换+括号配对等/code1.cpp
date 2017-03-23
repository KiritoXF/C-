#include<iostream>
using namespace std;

class stack
{
private:
	int maxsize;
	int top;
	int *st;
public:
	stack()
	{
		top = -1;
	}
	stack(int size)
	{
		top = -1;
		maxsize = size;
		st = new int[maxsize];
	}
	~stack()
	{
		delete[]st;
	}
	void clear()
	{
		top = -1;
	}
	bool push(int item)
	{
		if (top == maxsize - 1)
		{
			int * newst = new int[maxsize * 2];
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
	int pop()
	{
		if (top == -1)
		{
			cout << "ջΪ�գ����ܳ�ջ" << endl;
			return false;
		}
		else
		{
			int item;
			item = st[top--];
			return item;
		}
	}
	bool Top(int item)
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
int transform(int num,int cake)
{
	int temp = 1;//����
	stack remain(20);//��ת����Ķ�������
	while(temp != 0)
	{
		temp = num/cake;
		remain.push(num % cake);
		num = temp;
	}
	for (int i = 0;i < 20;i++)
	{
		cout << remain.pop();
		if (remain.gettop() == -1) break; //�����ظ����ִ�����ʾ
	}
	return 0;
}
int main()
{
	cout << "ջ�Ĳ��ԣ����������޹أ�" << endl;
	stack s1(10);
	for (int i = 1;i < 10;i++)
	{
		s1.push(i * 2);
	}
	for (int i = 1;i < 10;i++)
	{
		cout << s1.pop() << "  ";
	}
	cout << endl << endl;
	cout << "����ת����" << endl;
	int cake = 10;
	int num = 0;
	cout << "������Ҫת����ԭ��:(int)" << endl;
	cin >> num;
	cout << "������Ҫת���Ľ���(�Ƽ�������2~9֮�������~)" << endl;
	cin >> cake;
	if (cake > 10)
	{
		cout << "�������ѧ���ޣ���10���ϵĽ����޷�ת��" << endl;
		cout << "�����������ء�������һ�����˳�������������" << endl;
		cout << "\a";
	}
	if (cake == 1)
	{
		cout << "����- - ||" << endl;
		cout << "�����������ء�������һ�����˳�������������" << endl;
		cout << "\a";
		return 0;
	}
	transform(num,cake);
	return 0;
	
}