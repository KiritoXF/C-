/*
本测试题目目标是巩固单链表的相关操作
请大家完成有todo注释的成员函数的定义,相应功能已经注释
根据main中的提示的测试步骤来完成各个成员函数的测试

循序渐进,提升编程信心,完善设计思维
*/

#include <iostream>
using namespace std;

class Node  //定义结点类型
{
public:
	int data;  //存放数据
	Node* next; //存放后继结点地址
	Node(int val, Node* ptr = 0)  //构造函数,初始化数据成员
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node* head; //记录表头结点地址

	List()
	{
		head = new Node(0, 0);//构造带有表头结点的空的单向链表
	}
	void insertToHead(int x)//向表头插入数据值为x的结点
	{
		Node* newNode = new Node(x, 0);
		newNode->next = head->next;
		head->next = newNode;
	}

	/*~List()
	{
		//todo: 1-释放链表的所有结点
		Node *temp;
		temp = head->next;
		while (temp)
		{
			delete temp;
			temp = temp->next;
		}
	}*/
	void print()
	{
		// todo: 2-依次输出链表的各个结点的数据值
		Node *m = head;
		while (m->next != NULL)
		{
			m = m->next;
			cout << m->data << "  ";
		}
	}
	void moveMinToEnd()
	{
		//todo:3-将链表中数据域值最小的那个链结点移到链表的最后面。
		//要求：不得额外申请新的链结点
		/*Node *m = head;
		int temp = head->data;
		while(m->next != NULL)
		{
			if (m->data < temp)
			{
				temp = m->data;
				break;
			}
			m = m->next;
		}
		while (m->next != NULL)
		{
			if (m->next->data == temp)
			{
				m->next = m->next->next->next;
				delete m->next;
			}
		}*/
		Node *Minfront1 = head;
		Node *Min1 = head->next;
		Node *Minfront2 = head;
		Node *Min2 = head->next;
		Node *ps = head;
		while (ps->next != 0)
		{
			ps = ps->next;
		}
		while (Min1 != 0)
		{
			if (Min1->data < Min2->data)
			{
				Min2 = Min1;
				Minfront2 = Minfront1;
			}
			Min1 = Min1->next;
			Minfront1 = Minfront1->next;
		}
		
		if (Min2)
		{
		
			Minfront2->next = Min2->next;
			Min2->next = ps->next;
			ps->next = Min2;
			
		}
	}
	void delItem(int val)
	{
		Node *Front = head;
		Node *temp = head->next;
		while (temp)
		{

			if (temp->data == val)
			{
				Front->next = temp->next;
				break;
			}
			Front = Front->next;
			temp = temp->next;
		}
	}
};
void Move(int a[], int n)
{
	int i = 0, j = n;
	int temp = 0;
	while(i!=(j+1))
	{
		if (a[i] % 2 == 0 && a[j] % 2 != 0)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
			j--;
		}
		if (a[i] % 2 != 0)
		{
			i++;
		}
		if (a[j] % 2 == 0)
		{
			j--;
		}
		
	}
	for (int i = 0;i < 8;i++)
	{
		cout << a[i] << "  ";
	}
}	
void main()
{
	List mylist;

	// 必须补充: 循环调用insertToHead方法向mylist中添加数据
	for (int i = 0;i <10;i++)
	{
		mylist.insertToHead(i);
	}
	cout << "选择题答案C D" << endl;
	/* 下面开始测试各个成员函数,
	可以在实现每个测试目标的时候注释掉为完成其他测试目标而添加的代码*/

	//测试目标1: 测试析构函数----不需添加任何代码
	
	//测试目标2:测试print方法
	cout << "cout方法测试：" << endl;
	mylist.print();
	cout << endl;
	//测试目标3:测试 moveMinToEnd方法,执行 moveMinToEnd后利用print输出结果来查看
	mylist.moveMinToEnd();
	cout << "moveMinToEnd测试：" << endl;
	mylist.print();
	cout << endl;
	//测试目标4:测试delItem方法,执行 delItem后利用print输出结果来查看
	mylist.delItem(1);
	cout << "delItem方法测试：" << endl;
	mylist.print();

	cout <<  endl << "第三题：" << endl;
	int a[8] = { 1,8,3,6,4,9,7,12 };
	cout << "原数据：" << endl;
	for (int i = 0;i < 8;i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	Move(a, 8);
}