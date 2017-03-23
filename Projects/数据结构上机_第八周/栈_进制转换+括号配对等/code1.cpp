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
			cout << "栈为空，不能出栈" << endl;
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
int transform(int num,int cake)
{
	int temp = 1;//存商
	stack remain(20);//存转化后的二进制数
	while(temp != 0)
	{
		temp = num/cake;
		remain.push(num % cake);
		num = temp;
	}
	for (int i = 0;i < 20;i++)
	{
		cout << remain.pop();
		if (remain.gettop() == -1) break; //避免重复出现错误提示
	}
	return 0;
}
int main()
{
	cout << "栈的测试：（与下面无关）" << endl;
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
	cout << "进制转换：" << endl;
	int cake = 10;
	int num = 0;
	cout << "请输入要转换的原数:(int)" << endl;
	cin >> num;
	cout << "请输入要转换的进制(推荐您输入2~9之间的数字~)" << endl;
	cin >> cake;
	if (cake > 10)
	{
		cout << "代码君所学有限，对10以上的进制无法转化" << endl;
		cout << "请在听到“呜——”的一声后退出程序重新输入" << endl;
		cout << "\a";
	}
	if (cake == 1)
	{
		cout << "别闹- - ||" << endl;
		cout << "请在听到“呜——”的一声后退出程序重新输入" << endl;
		cout << "\a";
		return 0;
	}
	transform(num,cake);
	return 0;
	
}