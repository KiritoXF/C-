/*
��������ĿĿ���ǹ��̵��������ز���
���������todoע�͵ĳ�Ա�����Ķ���,��Ӧ�����Ѿ�ע��
����main�е���ʾ�Ĳ��Բ�������ɸ�����Ա�����Ĳ���

ѭ�򽥽�,�����������,�������˼ά
*/

#include <iostream>
using namespace std;

class Node  //����������
{
public:
	int data;  //�������
	Node* next; //��ź�̽���ַ
	Node(int val, Node* ptr = 0)  //���캯��,��ʼ�����ݳ�Ա
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node* head; //��¼��ͷ����ַ

	List()
	{
		head = new Node(0, 0);//������б�ͷ���Ŀյĵ�������
	}
	void insertToHead(int x)//���ͷ��������ֵΪx�Ľ��
	{
		Node* newNode = new Node(x, 0);
		newNode->next = head->next;
		head->next = newNode;
	}

	/*~List()
	{
		//todo: 1-�ͷ���������н��
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
		// todo: 2-�����������ĸ�����������ֵ
		Node *m = head;
		while (m->next != NULL)
		{
			m = m->next;
			cout << m->data << "  ";
		}
	}
	void moveMinToEnd()
	{
		//todo:3-��������������ֵ��С���Ǹ�������Ƶ����������档
		//Ҫ�󣺲��ö��������µ������
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

	// ���벹��: ѭ������insertToHead������mylist���������
	for (int i = 0;i <10;i++)
	{
		mylist.insertToHead(i);
	}
	cout << "ѡ�����C D" << endl;
	/* ���濪ʼ���Ը�����Ա����,
	������ʵ��ÿ������Ŀ���ʱ��ע�͵�Ϊ�����������Ŀ�����ӵĴ���*/

	//����Ŀ��1: ������������----��������κδ���
	
	//����Ŀ��2:����print����
	cout << "cout�������ԣ�" << endl;
	mylist.print();
	cout << endl;
	//����Ŀ��3:���� moveMinToEnd����,ִ�� moveMinToEnd������print���������鿴
	mylist.moveMinToEnd();
	cout << "moveMinToEnd���ԣ�" << endl;
	mylist.print();
	cout << endl;
	//����Ŀ��4:����delItem����,ִ�� delItem������print���������鿴
	mylist.delItem(1);
	cout << "delItem�������ԣ�" << endl;
	mylist.print();

	cout <<  endl << "�����⣺" << endl;
	int a[8] = { 1,8,3,6,4,9,7,12 };
	cout << "ԭ���ݣ�" << endl;
	for (int i = 0;i < 8;i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	Move(a, 8);
}