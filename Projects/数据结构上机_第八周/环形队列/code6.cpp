#include <iostream>
using namespace std;

class queue
{
private:
	int maxsize;
	int front;
	int rear;
	int *arr;
	bool tag;
public:
	queue(int size)
	{
		maxsize = size;
		arr = new int[maxsize];
		front = rear = -1;
		tag = 0;
	}
	~queue()
	{
		delete[]arr;
	}
	void clear()
	{
		front = rear;
	}
	void enqueue(int item)
	{
		rear = (rear + 1) % maxsize;
		if (((rear + 1) % maxsize == front) && tag == 1)
		{
			cout << "�������������" << endl;
			rear = maxsize - 1;
		}
		else
		{
			if (front = -1)
				front = 0;
			arr[rear] = item;
			tag = 1;
		}
	}
	void dequeue(int item)
	{
		if (tag == 0 && front == rear)
		{
			cout << "����Ϊ��" << endl;
			//return false;
		}
		else
		{
			item = arr[front];
			front = (front + 1) % maxsize;
			if (front == rear)
				tag = 0;
		}
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
		int temp = front;
		if (tag)//������Ԫ��
		{
			if (front == rear)//����
			{
				while (temp != rear)
				{
					cout << arr[temp];
					temp = (temp + 1) % maxsize;
				}
				cout << arr[rear] << endl;
			}
			while (temp != rear)//�Ӳ�����������Ԫ��
			{
				cout << arr[temp];
				temp = (temp + 1) % maxsize;
			}
			cout << arr[temp];
			cout << endl;
		}
	}
};
int main()
{
	int n;
	queue q(10);
	cin >> n;
	for (int i = 0;i<n;i++)
		q.enqueue(i);
	q.showque();
	int tmp = 0;
	q.dequeue(tmp);
	q.showque();
	return 0;
}