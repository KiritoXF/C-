/*#include <iostream>
using namespace std;

template <class T>
class  LinkedQueue;
template <class T>
class Node {
	friend LinkedQueue<T>;
private:
	T data;
	Node <T>  * link;
};
template <class T>
class  LinkedQueue {
public:
	LinkedQueue() { front = rear = 0; }
	～Queue();
	bool IsEmpty() { return ((front) ? false : true); }
	bool IsFull();
	T First();
	T Last();
	LinkedQueue<T>&  Add(const T& x);
	LinkedQueue<T>&  Del(T& x);
private:
	Node<T>  *front;
	Node<T>  *rear;
};
template < class T >
LinkedQueue& LinkedQueue< T> ::Add(const T & x) {
	Node<T> *p = new Node<T>;
	p->data = x;
	p->link = 0;
	if (front)     // 队列不为空
		rear->link = p;
	else           //  队列为空
		front = p;
	rear = p;
	return *this;
}
template < class T >
LinkedQueue&   LinkedQueue< T> ::Del()
{
	if (IsEmpty())
	{
		cout << “out of bounds”; return *this;
	}
	x = front->data;
	Node < T > * p = front;
	front = front->link;
	delete p;
	return *this;
}
*/
#include <iostream>

using namespace std;
//此程序输入10以内的自然数正常运行
//输入0直接结束
//输入11出现故障，大于11的数字程序无限循环
class Queue
{
private:
	int Front;
	int Rear;
	int *ptr;
public:
	Queue(int i = 100);
	bool Isempty();
	bool Isfull();
	bool Enqueue(int num);
	bool Dequeue();
	int Getqueue();
	bool Output();
};
Queue::Queue(int i)
{
	Front = Rear = 0;
	ptr = new int[i];
}
bool Queue::Isempty()
{
	if (Front == Rear)
		return true;
	else
		return false;
}
bool Queue::Isfull()
{
	if ((Rear + 1) % 100 == Front)
		return true;
	else
		return false;
}
bool Queue::Enqueue(int num)
{
	if (Isfull())
	{
		cout << "队列已满，无法进入" << endl;
		return false;
	}
	else
	{
		Rear ++;
		ptr[Rear] = num;
		return true;
	}
}
bool Queue::Dequeue()
{
	if (Isempty())
	{
		cout << "队列已空，无法提取" << endl;
		return false;
	}
	else
	{
		Front = (Front + 1) % 100;
		return true;
	}
}
int Queue::Getqueue()
{
	if (Isempty())
	{
		cout << "队列已空，无法提取" << endl;
		return false;
	}
	else
	{
		return ptr[(Front + 1) % 100];
		return true;
	}

}
bool Queue::Output()
{
	int temp = Front + 2;
	while (temp != Rear + 1)
	{
		cout << ptr[temp] << " ";
		temp = (temp + 1) % 100;
	}
	cout << endl;
	return true;
}

int main()
{
	Queue q;
	int num = 3;
	q.Enqueue(0);
	q.Enqueue(1);
	q.Enqueue(1);
	cout << "阶数：" << endl;
	int inum;
	cin >> inum;
	for (int i = 0; i < inum; i++)
	{
		q.Output();
		q.Enqueue(0);
		for (int k = 0; k < num; k++)
		{
			int frontnum = q.Getqueue();
			q.Dequeue();
			q.Enqueue(q.Getqueue() + frontnum);
		}
		num ++;
	}
	return 0;
}
