#include <iostream>
using namespace std;

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
			//cout << "队列为空！" << endl;
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
			//cout << "打印队列：" << endl;
			for (i = front;i != rear;i++)
			{
				cout << arr[i];
				if ((i + 1) % maxsize == 0)
				{
					i = -1;
				}
			}
			//cout << endl;
		}
	}
};
int main()
{
	queue q[10] = { 10,10,10,10,10,10,10,10,10,10 };
	int n = 0;//表示一共要输入的数量
	int temp = 0;//用来保存输入的数
	int i = 0;
	cout << "请输入n以确定数量" << endl;
	cin >> n;
	cout << "请输入" << n << "个10以内的数" << endl;
	for (i = 0;i < n;i++)
	{
		cin >> temp;
		q[temp].enqueue(temp);
	}
	/*for (i = 0;i < 10;i++)
	{
		cout << "队列" << i << "为" << "  ";
		q[i].showque();
		cout << endl;
	}*/
	cout << endl;
	for (i = 0;i < 10;i++)
	{
		if (!q[i].isesmpty())
		{
			q[i].showque();
		}
	}
	return 0;
}