#include<iostream>
#include<string>
using namespace std;

/**************************ջ�ඨ��****************************/
class arraystack
{
private:
	int maxsize;
	int top;
	int * st;
public:
	arraystack(int size)//���캯��
	{
		maxsize = size;
		top = -1;
		st = new int[maxsize];
	}
	arraystack()//���캯��
	{
		top = -1;
	}
	~arraystack()//��������
	{
		delete[]st;
	}
	void clear()//���ջ������
	{
		top = -1;
	}
	void push(int item)//��ջ����
	{
		if (top == maxsize - 1)
		{
			cout << "ջ�����" << endl;
		}
		else
		{
			st[++top] = item;
		}
	}
	void pop()//����ջ��Ԫ��
	{
		st[top--] = NULL;
	}
	int seeTop() {//����ջ��Ԫ��
		return st[top];
	}
};
/***********************************************************/
arraystack stak(100);//����ջ�����
					 //��LR�ķ���������ڶ�ά�����У�����������ת�Ƽ��������ͣ�
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

	string str[100];//���ַ������鱣������ľ��ӣ�ÿ������Ԫ��Ϊһ���ʷ���Ԫ
	int i;//�ַ��������±꣬������ָ��
	string lookahead;//��ȡ��ǰ�ַ�������Ԫ��
	bool flag_word;//�ж��Ƿ��ǺϷ��Ĵʷ���Ԫ
	bool flag_token;//�ж��Ƿ��ƶ�����ָ��ȡ�µĴʷ���Ԫ���Ǻţ�
	string errorType;//�洢���������﷨��������
	LR(string st[]) {//���캯����ʼ������
		i = 0;
		flag_word = true;
		flag_token = true;
		errorType = "e";
		for (int k = 0; k < 100; k++) {//���ഫ������ľ���
			str[k] = st[k];
		}
	}
	//��ȡһ���ʷ���Ԫ�����ƶ�����ָ��
	string nextToken() {
		return str[i++];
	}
	//������
	void error() {
		//�ʷ����󣬱��﷨�����������ԣ�ֱ�ӱ����������
		if (flag_word == false) {
			cout <<
				"------------TokenError---------�ʷ�����-----------"
				<< endl <<
				"���﷨���������Ժ��ԣ�����������������ȷ�ʷ���Ԫ������"
				<< endl <<
				"-------------------------------------------------"
				<< endl;
			lookahead = nextToken();
		}
		//�﷨������
		else {
			//e1��ʾȱ�ٲ�����
			if (errorType == "e1") {
				stak.push(5);
				flag_token = false;//����ָ�벻�ƶ�
				cout << "error1�� ȱ�ٲ�����������" << endl;
			}
			//e2��ʾ�����Ŷ���
			if (errorType == "e2") {
				flag_token = true;//���������������
				cout << "error2�� ����Ե������ţ�����" << endl;
			}
			//e3��ʾȱ�������
			if (errorType == "e3") {
				stak.push(6);
				flag_token = false;
				cout << "error3�� ȱ�������������" << endl;
			}
			//e4��ʾȱ��������
			if (errorType == "e4") {
				stak.push(11);
				flag_token = false;
				cout << "error4�� ȱ�������ţ�����" << endl;
			}
			//e5��ʾ������ȱ�ٱ��ʽ����������
			if (errorType == "e5") {
				flag_token = true;
				cout << "error5�� ������ȱ�ٱ��ʽ������" << endl;
			}
		}
	}

	//��stringת��Ϊint,ʹ֮��Ϊ������Ķ�ά�±�
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
		flag_word = false;//����Ĵʷ���Ԫ
		return 0;
	}
	void analysis() {
		stak.push(0);//�Ƚ�״̬0����ջ��
		while (1) {
			if (flag_token) {//��Լ�����ִ�����������ָ�벻�ƶ�
				lookahead = nextToken();
			}
			flag_token = true;
			//ȡ��������Ԫ��
			string temp = table[stak.seeTop()][strTOint(lookahead)];
			if (flag_word == false) { error(); }//�ʷ�������
												//����״̬�����ʷ�����������ѭ����������
			if (temp[0] == 'a' || flag_word == false) {
				if (flag_word == true)
					cout << "����" << endl;
				break;
			}
			flag_word = true;
			//�ƽ�����--��״̬ѹ��ջ��
			if (temp[0] == 's') {//��48��Ϊ�˽�charתΪint
				if (temp[2] == '1') { //����s11���
					stak.push(11);
				}
				else {
					stak.push(temp[1] - 48);
				}
				cout << "�ƽ�" << stak.seeTop() << endl;
			}
			//��Լ����
			if (temp[0] == 'r') {
				flag_token = false;
				string nT;
				if (temp[1] == '1') {
					nT = "E";
					cout << "�� E-->E+T ��Լ" << endl;
					stak.pop();
					stak.pop();
					stak.pop();
				}
				if (temp[1] == '2') {
					nT = "E";
					cout << "�� E-->T ��Լ" << endl;
					stak.pop();
				}
				if (temp[1] == '3') {
					nT = "T";
					cout << "�� T-->T*F ��Լ" << endl;
					stak.pop();
					stak.pop();
					stak.pop();
				}
				if (temp[1] == '4') {
					nT = "T";
					cout << "�� T-->F ��Լ" << endl;
					stak.pop();
				}
				if (temp[1] == '5') {
					nT = "F";
					cout << "�� F-->(E) ��Լ" << endl;
					stak.pop();
					stak.pop();
					stak.pop();
				}
				if (temp[1] == '6') {
					nT = "F";
					cout << "�� F-->id ��Լ" << endl;
					stak.pop();
				}

				if (table[stak.seeTop()][strTOint(nT)][1] == '0') {
					stak.push(10);
					cout << "�ƽ�10" << endl;
				}
				else {
					stak.push(table[stak.seeTop()][strTOint(nT)][0] - 48);
				}
			}
			//����״̬
			if (temp[0] == 'e') {
				errorType = temp;
				error();
			}
		}
	}
};

void main() {

	//���ʽ���루�����ʷ���Ԫ�Կո����������#�Խ�����
	bool flag_input = true;//�ж��Ƿ��������
	int i = 0;//�ַ��������±�
	string str[100];//���ַ������鱣������ı��ʽ��ÿ������Ԫ��Ϊһ���ʷ���Ԫ
	cout << "��������ʽ��  �������ʷ���Ԫ�Կո����������#�Խ�����" << endl;
	while (flag_input) {
		cin >> str[i];
		if (str[i] == "#")
			flag_input = false;
		i++;
	}

	LR lr1(str);//���������
	lr1.analysis();//���÷�����������ʼLR
}