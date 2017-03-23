#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;
class procal
{
public:string exp;int i;
	   stack<string> val, label;
	   int tv;
	   stack<int> tempval;
	   void getis()
	   {
		   i = 0;tv = 0;
		   label.push("0");val.push("null");
		   cout << "请输入表达式：" << endl;
		   cin >> exp;exp.push_back('$');
	   }
	   void lex()
	   {
		   string s;
		   while (!label.empty() && !val.empty())
		   {
			   if (exp[i] == '+' || exp[i] == '*' || exp[i] == '(' || exp[i] == ')' || exp[i] == '$' || exp[i] == '-')
			   {
				   s.push_back(exp[i]);
				   match(s, s);s.clear();continue;
			   }
			   if (exp[i] >= '0'&&exp[i] <= '9')
			   {
				   s.push_back(exp[i]);i++;
				   while (exp[i] >= '0'&&exp[i] <= '9')
				   {
					   s.push_back(exp[i]);i++;
				   }i--;
				   match(s, "id");s.clear();continue;
			   }
			   else
			   {
				   cout << "输入错误！请重新输入" << endl;
				   exit(0);
			   }
		   }
	   }
	   int trans(string s)
	   {
		   int sum = 0, i = 0, j;
		   if (s[0] == '-')
		   {
			   i++;
		   }
		   while (i<s.size())
		   {
			   j = s[i] - '0';
			   sum = sum * 10 + j;i++;
		   }
		   if (s[0] == '-')
		   {
			   return (-sum);
		   }
		   else {
			   return sum;
		   }
	   }
	   string trans1(int a)
	   {
		   int a1 = abs(a);
		   char temp;string s;
		   while (a1)
		   {
			   temp = a1 % 10 + '0';
			   s.push_back(temp);a1 = a1 / 10;
		   }
		   if (a>0) {
			   return reverse(s);
		   }
		   else {
			   s.push_back('-');
			   return reverse(s);
		   }
	   }
	   string reverse(string s)
	   {
		   string s1;
		   while (s.size()>0)
		   {
			   s1.push_back(s[s.size() - 1]);s.erase(s.size() - 1);
		   }
		   return s1;
	   }
	   void match(string user, string pro)
	   {
		   string stop = label.top();string s1;
		   string val1, val2;int v1 = -1, v2 = -1;
		   if ((stop == "0" || stop == "4" || stop == "6" || stop == "7" || stop == "8" || stop == "14" || stop == "15") && pro == "id")
		   {
			   label.push("id");val.push(user);tempval.push(-1);label.push("5");val.push("null");tempval.push(-1);i++;return;
		   }
		   if ((stop == "0" || stop == "4" || stop == "6" || stop == "7" || stop == "8" || stop == "15") && pro == "(")
		   {
			   label.push("(");label.push("4");val.push("null");tempval.push(-1);val.push("null");tempval.push(-1);i++;return;
		   }
		   if (stop == "1"&&pro == "+")
		   {
			   label.push("+");label.push("7");val.push("null");tempval.push(-1);val.push("null");tempval.push(-1);i++;return;
		   }
		   if (stop == "9"&&pro == "+")
		   {
			   label.push("+");label.push("14");val.push("null");tempval.push(-1);val.push("null");tempval.push(-1);i++;return;
		   }
		   if ((stop == "2" || stop == "16") && pro == "*")
		   {
			   label.push("*");label.push("8");val.push("null");tempval.push(-1);val.push("null");tempval.push(-1);i++;return;
		   }
		   if (stop == "11"&&pro == "*")
		   {
			   label.push("*");label.push("15");val.push("null");tempval.push(-1);val.push("null");tempval.push(-1);i++;return;
		   }
		   if (stop == "9"&&pro == ")")
		   {
			   label.push(")");label.push("13");val.push("null");tempval.push(-1);val.push("null");tempval.push(-1);i++;return;
		   }
		   if ((stop == "0" || stop == "4" || stop == "15") && pro == "-")
		   {
			   label.push("-");label.push("6");val.push("null");tempval.push(-1);val.push("null");tempval.push(-1);i++;return;
		   }
		   if (stop == "2" && (pro == "+" || pro == ")" || pro == "$"))
		   {
			   label.pop();label.pop();s1 = label.top();label.push("E");gototable(s1, "E");
			   //cout<<"按E->T归约"<<endl;
			   return;
		   }
		   if (stop == "3" && (pro == "+" || pro == "*" || pro == ")" || pro == "$"))
		   {
			   label.pop();label.pop();s1 = label.top();label.push("T");gototable(s1, "T");
			   //cout<<"按T->F归约"<<endl;
			   return;
		   }
		   if (stop == "5" && (pro == "+" || pro == "*" || pro == ")" || pro == "$"))
		   {
			   label.pop();label.pop();s1 = label.top();label.push("F");gototable(s1, "F");
			   //cout<<"按F->id归约"<<endl;
			   return;
		   }
		   if ((stop == "16" || stop == "11") && (pro == "+" || pro == ")" || pro == "$"))
		   {
			   int a, b;bool flag = false;
			   for (int i = 0;i<6;i++)
			   {
				   label.pop();val.pop();tempval.pop();
				   if (val.top() != "null"&&!flag)
				   {
					   a = trans(val.top());flag = true;val1 = val.top();v1 = tempval.top();
				   }
				   if (val.top() != "null"&&flag)
				   {
					   b = trans(val.top());val2 = val.top();v2 = tempval.top();
				   }
			   }string s2 = trans1(a + b);
			   tv++;
			   print(v1, val1, v2, val2, '+');
			   s1 = label.top();label.push("E");val.push(s2);tempval.push(tv);gototable(s1, "E");val.push("null");tempval.push(-1);
			   //cout<<"按E->E+T归约"<<endl;
			   return;
		   }
		   if (stop == "12" && (pro == "+" || pro == "*" || pro == ")" || pro == "$"))
		   {
			   int a, b;bool flag = false;
			   for (int i = 0;i<6;i++)
			   {
				   label.pop();val.pop();tempval.pop();
				   if (val.top() != "null"&&!flag)
				   {
					   a = trans(val.top());flag = true;val1 = val.top();v1 = tempval.top();
				   }
				   if (val.top() != "null"&&flag)
				   {
					   b = trans(val.top());val2 = val.top();v2 = tempval.top();
				   }
			   }string s2 = trans1(a*b);tv++;print(v1, val1, v2, val2, '*');
			   s1 = label.top();label.push("T");val.push(s2);tempval.push(tv);gototable(s1, "T");val.push("null");tempval.push(-1);
			   //cout<<"按T->T*F归约"<<endl;
			   return;
		   }
		   if (stop == "13" && (pro == "+" || pro == "*" || pro == ")" || pro == "$"))
		   {
			   string a;
			   for (int i = 0;i<6;i++)
			   {
				   string b = val.top();label.pop();val.pop();tempval.pop();
				   if (b != "null")
				   {
					   a = b;
				   }
			   }
			   s1 = label.top();label.push("F");val.push(a);gototable(s1, "F");val.push("null");tempval.push(tv);tempval.push(-1);
			   //cout<<"按F->(E)归约"<<endl;
			   return;
		   }
		   if (stop == "10" && (pro == "+" || pro == "$" || pro == ")"))
		   {
			   int a;
			   for (int i = 0;i<4;i++)
			   {
				   label.pop();val.pop();tempval.pop();
				   if (val.top() != "null")
				   {
					   a = trans(val.top());v1 = tempval.top();
				   }
			   }string s2 = trans1(a);tv++;s2.insert(0, 1, '-');
			   if (v1<0) {
				   cout << 't' << tv << '=' << ' ' << s2 << endl;
			   }
			   else {
				   cout << 't' << tv << '=' << ' ' << '-' << 't' << v1 << endl;
			   }
			   s1 = label.top();label.push("E");val.push(s2);tempval.push(tv);gototable(s1, "E");val.push("null");tempval.push(-1);
			   //cout<<"按E->-E进行规约"<<endl;
			   return;
		   }
		   if (stop == "1"&&pro == "$")
		   {
			   val.pop();tempval.pop();
			   if (val.top() != "0") {
				   cout << 't' << tempval.top() << '=' << val.top() << endl;
			   }
			   else {
				   int a = 0;
				   cout << 't' << tempval.top() << '=' << a << endl;
			   }
			   exit(0);
		   }
		   else
		   {
			   //cout<<stop<<' '<<pro<<endl;
			   cout << "输入错误，请重新输入！" << endl;
			   exit(0);
		   }
	   }
	   void gototable(string s1, string s2)
	   {
		   if (s1 == "0"&&s2 == "E")
		   {
			   label.push("1");
		   }
		   if ((s1 == "0" || s1 == "4" || s1 == "6") && s2 == "T")
		   {
			   label.push("2");
		   }
		   if ((s1 == "0" || s1 == "4" || s1 == "6" || s1 == "7" || s1 == "14") && s2 == "F")
		   {
			   label.push("3");
		   }
		   if (s1 == "4"&&s2 == "E")
		   {
			   label.push("9");
		   }
		   if (s1 == "6"&&s2 == "E")
		   {
			   label.push("10");
		   }
		   if (s1 == "7"&&s2 == "T")
		   {
			   label.push("11");
		   }
		   if ((s1 == "15" || s1 == "8") && s2 == "F")
		   {
			   label.push("12");
		   }
		   if (s1 == "14"&&s2 == "T")
		   {
			   label.push("16");
		   }
	   }
	   void print(int a, string aa, int b, string bb, char op)
	   {
		   if (a>0 && b>0)
		   {
			   cout << 't' << tv << '=' << 't' << b << ' ' << op << ' ' << 't' << a << endl;
		   }
		   else if (a>0 && b<0)
		   {
			   cout << 't' << tv << '=' << bb << ' ' << op << ' ' << 't' << a << endl;
		   }
		   else if (a<0 && b>0)
		   {
			   cout << 't' << tv << '=' << 't' << b << ' ' << op << ' ' << aa << endl;
		   }
		   else
		   {
			   cout << 't' << tv << '=' << bb << ' ' << op << ' ' << aa << endl;
		   }
	   }
};
void main()
{
	procal p;
	p.getis();
	p.lex();
}