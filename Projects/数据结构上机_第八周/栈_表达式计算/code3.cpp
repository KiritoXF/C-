#include<iostream>
using namespace std;

template <typename T>
class stack
{
private:
	int maxsize;
	int top;
	T *st;
public:
	stack()
	{
		top = -1;
	}
	stack(int size)
	{
		top = -1;
		maxsize = size;
		st = new T[maxsize];
	}
	~stack()
	{
		delete[]st;
	}
	void clear()
	{
		top = -1;
	}
	bool push(T item)
	{
		if (top == maxsize - 1)
		{
			T * newst = new T[maxsize * 2];
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
	T pop()
	{
		if (top == -1)
		{
			cout << "栈为空，不能出栈" << endl;
			return false;
		}
		else
		{
			T item;
			item = st[top--];
			return item;
		}
	}
	bool Top(T item)
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
	T getlast()
	{
		return st[top];
	}
};
void judgement(char *code)//判断括号配对成功与否
{
	stack<char> s1(10);
	stack<char> s2(10);
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
int get_level_in(char oper)
{
	int level = -1;
	switch (oper)
	{
	case'#':
		return 0;
		break;
	case'(':
		return 1;
		break;
	case'^':
		return 7;
		break;
	case'*':
	case'/':
	case'%':
		return 5;
		break;
	case'+':
	case'-':
		return 3;
		break;
	case')':
		return 8;
		break;
	default:
		cout << "错误的运算符" << endl;
	}
}
int get_level_out(char oper)
{
	switch (oper)
	{
	case '#':
		return 0;
		break;
	case '(':
		return 8;
		break;
	case '^':
		return 6;
		break;
	case '*':
	case '/':
	case '%':
		return 4;
		break;
	case '+':
	case '-':
		return 2;
		break;
	case ')':
		return 1;
		break;
	default:
		cout << "错误的运算符" << endl;
	}
}
char trade(char a, char b) //判断运算符优先级大小，其中 栈内a 跟 栈外b 要分开的
{
	int level_a = get_level_in(a);
	int level_b = get_level_out(b);
	if (level_a < level_b)	return '<';
	if (level_a > level_b)  return '>';
	else return '=';
}
double operate(double a, char ope, double b)//数值的计算
{
	char oper;
	double data1, data2;
	double value;

	data2 = b;
	data1 = a;
	oper = ope;

	switch (oper)
	{
	case '+':
		value = data1 + data2;
		break;
	case '-':
		value = data1 - data2;
		break;
	case '*':
		value = data1 * data2;
		break;
	case '/':
		value = data1 / data2;
		break;
	default:
		break;
	}
	return value;
}
double calculate(char *code) //主运算过程
{
	stack<char> s1(20);//运算符栈，栈底为#
	stack<double> s2(20);//操作数栈，空栈
	char s = '#';
	s1.push(s);
	for (int i = 0;code[i] != '\0';i++)
	{
		if (code[i] >= '0' && code[i] <= '9')
		{
			s2.push(code[i]-'0');
		}
		else
			switch (trade(s1.getlast(),code[i]))
			{
			case'<':
				s1.push(code[i]);
				break;
			case'=':
 				s1.pop();
				break;
			case'>':
				double temp = operate(s2.pop(), s1.pop(), s2.pop());
				s2.push(temp);
				i--;
				break;
			}
		//cout << s2.getlast() << "   ";
	}
	return s2.getlast();
}

int main()
{
	cout << "括号配对：" << endl << endl;
	//char code[30];
	cout << "请输入一个30字符以内的式子：" << endl;
	//cin >> code;
	char *code = "(2+3*4)#";
	judgement(code);
	cout << "结果为：" << calculate(code) << endl;
	return 0;
}