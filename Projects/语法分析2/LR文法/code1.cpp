#include<iostream>
#include<string>
using namespace std;

/**************************栈类定义****************************/
class arraystack
{
private:
	int maxsize;
	int top;
	int * st;
public:
	arraystack(int size)//构造函数
	{
		maxsize = size;
		top = -1;
		st = new int[maxsize];
	}
	arraystack()//构造函数
	{
		top = -1;
	}
	~arraystack()//析构函数
	{
		delete[]st;
	}
	void clear()//清空栈的内容
	{
		top = -1;
	}
	void push(int item)//入栈操作
	{
		if (top == maxsize - 1)
		{
			cout << "栈满溢出" << endl;
		}
		else
		{
			st[++top] = item;
		}
	}
	void pop()//弹出栈中元素
	{
		st[top--] = NULL;
	}
	int seeTop() {//返回栈顶元素
		return st[top];
	}
};
/***********************************************************/
arraystack stak(100);//定义栈类对象
					 //将LR文法分析表存于二维数组中（包含动作、转移及错误类型）
string table[12][9] = {
	{ "s5", "e1", "e1", "s4", "e2", "e1",
	"1", "2", "3" },
	{ "e3", "s6", "e1", "e3", "e2", "acc",
	" ", " ", " " },
	{ "e3", "r2", "s7", "e3", "r2", "r2",
	" ", " ", " " },
	{ "e3", "r4", "r4", "e3", "r4", "r4",
	" ", " ", " " },
	{ "s5", "e1", "e1", "s4", "e5", "e1",
	"8", "2", "3" },
	{ "e3", "r6", "r6", "e3", "r6", "r6",
	" ", " ", " " },
	{ "s5", "e1", "e1", "s4", "e2", "e1",
	" ", "9", "3" },
	{ "s5", "e1", "e1", "s4", "e2", "e1",
	" ", " ", "10" },
	{ "e3", "s6", "e1", "e3", "s11", "e4",
	" ", " ", " " },
	{ "e3", "r1", "s7", "e3", "r1", "r1",
	" ", " ", " " },
	{ "e3", "r3", "r3", "e3", "r3", "r3",
	" ", " ", " " },
	{ "e3", "r5", "r5", "e3", "r5", "r5",
	" ", " ", " " }
};

class LR {

public:

	string str[100];//以字符串数组保存输入的句子，每个数组元素为一个词法单元
	int i;//字符串数组下标，即输入指针
	string lookahead;//读取当前字符串数组元素
	bool flag_word;//判断是否是合法的词法单元
	bool flag_token;//判断是否移动输入指针取新的词法单元（记号）
	string errorType;//存储分析表中语法错误类型
	LR(string st[]) {//构造函数初始化变量
		i = 0;
		flag_word = true;
		flag_token = true;
		errorType = "e";
		for (int k = 0; k < 100; k++) {//向类传递输入的句子
			str[k] = st[k];
		}
	}
	//读取一个词法单元，并移动输入指针
	string nextToken() {
		return str[i++];
	}
	//错误处理
	void error() {
		//词法错误，本语法分析器不忽略，直接报错结束程序
		if (flag_word == false) {
			cout <<
				"------------TokenError---------词法错误-----------"
				<< endl <<
				"本语法分析器难以忽略，请重启程序输入正确词法单元！！！"
				<< endl <<
				"-------------------------------------------------"
				<< endl;
			lookahead = nextToken();
		}
		//语法错误处理
		else {
			//e1表示缺少操作数
			if (errorType == "e1") {
				stak.push(5);
				flag_token = false;//输入指针不移动
				cout << "error1： 缺少操作数！！！" << endl;
			}
			//e2表示右括号多余
			if (errorType == "e2") {
				flag_token = true;//跳过冗余的右括号
				cout << "error2： 不配对的右括号！！！" << endl;
			}
			//e3表示缺少运算符
			if (errorType == "e3") {
				stak.push(6);
				flag_token = false;
				cout << "error3： 缺少运算符！！！" << endl;
			}
			//e4表示缺少右括号
			if (errorType == "e4") {
				stak.push(11);
				flag_token = false;
				cout << "error4： 缺少右括号！！！" << endl;
			}
			//e5表示括号中缺少表达式，即：（）
			if (errorType == "e5") {
				flag_token = true;
				cout << "error5： 括号中缺少表达式！！！" << endl;
			}
		}
	}

	//将string转换为int,使之成为分析表的二维下标
	int strTOint(string s) {
		if (s == "id") return 0;
		if (s == "+") return 1;
		if (s == "*") return 2;
		if (s == "(") return 3;
		if (s == ")") return 4;
		if (s == "#") return 5;
		if (s == "E") return 6;
		if (s == "T") return 7;
		if (s == "F") return 8;
		flag_word = false;//错误的词法单元
		return 0;
	}
	void analysis() {
		stak.push(0);//先将状态0放入栈中
		while (1) {
			if (flag_token) {//规约及部分错误处理则输入指针不移动
				lookahead = nextToken();
			}
			flag_token = true;
			//取分析表中元素
			string temp = table[stak.seeTop()][strTOint(lookahead)];
			if (flag_word == false) { error(); }//词法错误处理
												//接受状态或发生词法错误则跳出循环结束程序
			if (temp[0] == 'a' || flag_word == false) {
				if (flag_word == true)
					cout << "接受" << endl;
				break;
			}
			flag_word = true;
			//移进操作--将状态压进栈中
			if (temp[0] == 's') {//减48是为了将char转为int
				if (temp[2] == '1') { //处理s11情况
					stak.push(11);
				}
				else {
					stak.push(temp[1] - 48);
				}
				cout << "移进" << stak.seeTop() << endl;
			}
			//规约操作
			if (temp[0] == 'r') {
				flag_token = false;
				string nT;
				if (temp[1] == '1') {
					nT = "E";
					cout << "按 E-->E+T 归约" << endl;
					stak.pop();
					stak.pop();
					stak.pop();
				}
				if (temp[1] == '2') {
					nT = "E";
					cout << "按 E-->T 归约" << endl;
					stak.pop();
				}
				if (temp[1] == '3') {
					nT = "T";
					cout << "按 T-->T*F 归约" << endl;
					stak.pop();
					stak.pop();
					stak.pop();
				}
				if (temp[1] == '4') {
					nT = "T";
					cout << "按 T-->F 归约" << endl;
					stak.pop();
				}
				if (temp[1] == '5') {
					nT = "F";
					cout << "按 F-->(E) 归约" << endl;
					stak.pop();
					stak.pop();
					stak.pop();
				}
				if (temp[1] == '6') {
					nT = "F";
					cout << "按 F-->id 归约" << endl;
					stak.pop();
				}

				if (table[stak.seeTop()][strTOint(nT)][1] == '0') {
					stak.push(10);
					cout << "移进10" << endl;
				}
				else {
					stak.push(table[stak.seeTop()][strTOint(nT)][0] - 48);
				}
			}
			//错误状态
			if (temp[0] == 'e') {
				errorType = temp;
				error();
			}
		}
	}
};

void main() {

	//表达式输入（各个词法单元以空格隔开，输入#以结束）
	bool flag_input = true;//判断是否输入结束
	int i = 0;//字符串数组下标
	string str[100];//以字符串数组保存输入的表达式，每个数组元素为一个词法单元
	cout << "请输入表达式：  （各个词法单元以空格隔开，输入#以结束）" << endl;
	while (flag_input) {
		cin >> str[i];
		if (str[i] == "#")
			flag_input = false;
		i++;
	}

	LR lr1(str);//创建类对象
	lr1.analysis();//调用分析函数，开始LR
}