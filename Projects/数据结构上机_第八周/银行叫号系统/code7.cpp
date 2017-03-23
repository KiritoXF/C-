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
			cout << "队列已满，溢出" << endl;
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
			cout << "队列为空" << endl;
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
			cout << "队列为空" << endl;
			return false;
		}
		item = arr[item];
		return true;
	}
	bool isesmpty()
	{
		if (front == rear)
		{
			cout << "队列为空！" << endl;
			return 1;
		}
		else
			return 0;
	}
	bool isfull()
	{
		if ((rear + 1) % maxsize == front)
		{
			cout << "队列已满！" << endl;
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
			cout << "打印队列：" << endl;
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
	int isWait;//等待时间
	int ArriveTime;//到达时间
	int ServeTime; //服务时间
	char* type; //用户类型

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
		cout << this->type << this->id << "已被服务完毕,离开银行" << endl;
	}
};
class NormalUser : public User
{
public:
	NormalUser():User(){};
	NormalUser(int i, int iw, int at, int st) :User(i, iw, at, st, "普通用户") {};
	void getServed()
	{
		cout << this->type << this->id << "已被服务完毕,离开银行" << endl;
	}
};
class OfficialUser : public User
{
public:
	OfficialUser():User(){};
	OfficialUser(int i, int iw, int at, int st) :User(i, iw, at, st, "公用用户") {};
	void getServed()
	{
		cout << this->type << this->id << "已被服务完毕,离开银行" << endl;
	}
};
class VIPUser : public User
{
public:
	VIPUser():User() {};
	VIPUser(int i, int iw, int at, int st) :User(i, iw, at, st, "VIP用户") {};
	void getServed()
	{
		cout << this->type << this->id << "已被服务完毕,离开银行" << endl;
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
		cout << this->type << this->id << "正在为" << this->client.type << this->client.id << "服务" << endl;
	}
};
class NormalBankWindow : public BankWindow
{
public:
	NormalBankWindow() :BankWindow() {};
	NormalBankWindow(bool i, int id, User c, char* t) : BankWindow(i,id,c,"普通窗口") {};
};
class OfficialBankWindow : public BankWindow
{
public:
	OfficialBankWindow() : BankWindow() {};
	OfficialBankWindow(bool i, int id, User c, char* t) : BankWindow(i, id, c, "公用窗口") {};
};
class VIPBankWindow : public BankWindow
{
public:
	VIPBankWindow() : BankWindow() {};
	VIPBankWindow(bool i, int id, User c, char* t) : BankWindow(i, id, c, "VIP窗口") {};
};
////////////////////////////////////////////////////////////////////////////////////////////////
class Simulater
{
public:
	queue<NormalUser> NormalUserQueue;
	queue<VIPUser>VIPUserQueue;
	queue<OfficialUser>OfficialUserQueue;
	

};