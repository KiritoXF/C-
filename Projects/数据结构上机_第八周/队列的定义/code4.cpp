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
int main()
{
	queue q1(5);
	for (int i = 1;i <= 5;i++)
	{
		 q1.enqueue(i);
	}
	q1.showque();


	return 0;
}