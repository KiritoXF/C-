#include <iostream>
using namespace std;

template <class T>
class maxHeap
{
private:
	T* heapArr;
	int currentSize;//当前堆中元素数目
	int maxSize;//堆所能容纳的最大元素数目
public:
	maxHeap(T* arr, int num, int max)
	{
		heapArr = arr;
		maxSize = max;
		currentSize = num;
		buildHeap();
	}
	virtual ~maxHeap()
	{
		currentSize = 0;
		maxSize = 0;
		delete[] heapArr;
	}
	void buildHeap()
	{
		for (int i = currentSize / 2 - 1;i >= 0;i--)
		{
			siftdown(i);
		}
	}
	void siftdown(int left)//筛选法构造
	{
		int i = left;//父结点
		int j = 2 * i + 1;//左孩子
		T temp = heapArr[i];//父结点的位置（关键码）

		while (j < currentSize)
		{
			if ((j < currentSize - 1) && (heapArr[j] < heapArr[j + 1]))
				j++;
			if (temp < heapArr[j])
			{
				heapArr[i] = heapArr[j];
				i = j;
				j = 2 * j + 1;
			}
			else break;
		}
		heapArr[i] = temp;
	}
	void siftup(int position)//从插入的结点位置开始向上调整，直到满足堆的条件。
	{
		int temppos = position;
		T temp = heapArr[temppos];
		while ((temppos > 0) && heapArr[(temppos - 1) / 2] < temp)
		{
			heapArr[temppos] = heapArr[(temppos - 1) / 2];
			temppos = (temppos - 1) / 2;
		}
		heapArr[temppos] = temp;
	}
	void insert(const T& newnode)//插入新结点
	{
		heapArr[currentSize] = newnode;
		siftup(currentSize);
		currentSize++;
	}
	T &deleteMax()
	{
		T temp;
		if (currentSize == 0)
		{
			cout << "堆为空" << endl;
			exit(1);
		}
		else
		{
			temp = heapArr[0];
			heapArr[0] = heapArr[currentSize - 1];
			heapArr[currentSize - 1] = temp;
			currentSize--;
			if (currentSize > 0)
				siftdown(0);
			return heapArr[currentSize];
		}
	}
	void show()//输出数组
	{
		for (int i = 0;i < currentSize;i++)
		{
			cout << heapArr[i] << "  ";
		}
		cout << endl;
	}
};
int main()
{
	int arr[8] = { 20,15,12,8,19,35,96,37 };
	maxHeap<int> max(arr,8,10);
	max.buildHeap();
	max.show();
	max.insert(99);
	max.insert(13);
	max.buildHeap();
	max.show();
	max.deleteMax();
	max.show();
	exit(0);
	return 0;
}