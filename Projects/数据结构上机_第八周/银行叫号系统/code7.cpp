#include <iostream>
#include <Windows.h>
using namespace std;

template <typename T>
class queue
{
private:
	int maxsize;
	int front;
	int rear;
	int *arr;
public:
	queue(int size)
	{
		maxsize = size + 1;
		arr = new int[maxsize];
		front = rear = 0;
	}
	~queue()
	{
		delete[]arr;
	}
	void clear()
	{
		front = rear;
	}
	bool enqueue(int item)
	{
		if ((rear + 1) % maxsize == front)
		{
			cout << "�������������" << endl;
			return false;
		}
		arr[rear] = item;
		rear = (rear + 1) % maxsize;
		return true;
	}
	bool dequeue(int item)
	{
		if (front == rear)
		{
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = arr[front];
		front = (front + 1) % maxsize;
		return true;
	}
	bool getfront(int item)
	{
		if (front == rear)
		{
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = arr[item];
		return true;
	}
	bool isesmpty()
	{
		if (front == rear)
		{
			cout << "����Ϊ�գ�" << endl;
			return 1;
		}
		else
			return 0;
	}
	bool isfull()
	{
		if ((rear + 1) % maxsize == front)
		{
			cout << "����������" << endl;
			return 1;
		}
		else
			return 0;
	}
	void showque()
	{
		int i = 0;
		if (!isesmpty())
		{
			cout << "��ӡ���У�" << endl;
			for (i = front;i != rear;i++)
			{
				cout << arr[i];
				if ((i + 1) % maxsize == 0)
				{
					i = -1;
				}
			}
			cout << endl;
		}
	}
};

class User
{
public:
	int id;
	int isWait;//�ȴ�ʱ��
	int ArriveTime;//����ʱ��
	int ServeTime; //����ʱ��
	char* type; //�û�����

	User()
	{
		type = NULL;
	}
	User(int i, int iw, int at, int st, char* type)
	{
		this->id = i;
		this->isWait = iw;
		this->ArriveTime = at;
		this->ServeTime = st;
		this->type = type;
	}
	void getServed()
	{
		cout << this->type << this->id << "�ѱ��������,�뿪����" << endl;
	}
};
class NormalUser : public User
{
public:
	NormalUser():User(){};
	NormalUser(int i, int iw, int at, int st) :User(i, iw, at, st, "��ͨ�û�") {};
	void getServed()
	{
		cout << this->type << this->id << "�ѱ��������,�뿪����" << endl;
	}
};
class OfficialUser : public User
{
public:
	OfficialUser():User(){};
	OfficialUser(int i, int iw, int at, int st) :User(i, iw, at, st, "�����û�") {};
	void getServed()
	{
		cout << this->type << this->id << "�ѱ��������,�뿪����" << endl;
	}
};
class VIPUser : public User
{
public:
	VIPUser():User() {};
	VIPUser(int i, int iw, int at, int st) :User(i, iw, at, st, "VIP�û�") {};
	void getServed()
	{
		cout << this->type << this->id << "�ѱ��������,�뿪����" << endl;
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////
class BankWindow
{
public:
	bool isBusy;
	int id;
	User client;
	char* type;
	BankWindow()
	{
		type = NULL;
	}
	BankWindow(bool i, int id, User c, char* t)
	{
		this->isBusy = i;
		this->id = id;
		this->client = c;
		this->type = t;
	}
	void HandleUser()
	{
		cout << this->type << this->id << "����Ϊ" << this->client.type << this->client.id << "����" << endl;
	}
};
class NormalBankWindow : public BankWindow
{
public:
	NormalBankWindow() :BankWindow() {};
	NormalBankWindow(bool i, int id, User c, char* t) : BankWindow(i,id,c,"��ͨ����") {};
};
class OfficialBankWindow : public BankWindow
{
public:
	OfficialBankWindow() : BankWindow() {};
	OfficialBankWindow(bool i, int id, User c, char* t) : BankWindow(i, id, c, "���ô���") {};
};
class VIPBankWindow : public BankWindow
{
public:
	VIPBankWindow() : BankWindow() {};
	VIPBankWindow(bool i, int id, User c, char* t) : BankWindow(i, id, c, "VIP����") {};
};
////////////////////////////////////////////////////////////////////////////////////////////////
class Simulater
{
public:
	queue<NormalUser> NormalUserQueue;
	queue<VIPUser>VIPUserQueue;
	queue<OfficialUser>OfficialUserQueue;
	

};