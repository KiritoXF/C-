#include <iostream>
using namespace std;

template <class T>
class minheap // ��С���ඨ��    ��ʼ�������룬ɾ���Ѷ�Ԫ��
{
private:
	T * heaparray;
	int currentsize;
	int maxsize;
public:
	minheap(int n)
	{
		if (n <= 0)
			return;
		currentsize = 0;
		maxsize = n;
		heaparray = new T[maxsize];
		buildheap();
	}
	~minheap()
	{
		delete[] heaparray;
	}
	void buildheap()
	{
		for (int i = currentsize / 2 - 1;i >= 0;i--)
			siftdown(i);//��������ɸѡ����
	}
	void siftdown(int left)//ɸѡ������������left��ʾ��ʼ����������±�
	{
		int i = left;
		int j = 2 * i + 1;
		T temp = heaparray[i];
		while (j<currentsize)
		{
			if ((j<currentsize - 1) && (heaparray[j]>heaparray[j + 1]))
				j++;
			if (temp>heaparray[j])
			{
				heaparray[i] = heaparray[j];
				i = j;
				j = 2 * j + 1;
			}
			else break;
		}
		heaparray[i] = temp;
	}
	void siftup(int pos)//��pos���Ͽ�ʼ����
	{
		int temppos = pos;
		T temp = heaparray[temppos];
		while ((temppos>0) && (heaparray[(temppos - 1) / 2]>temp))
		{
			heaparray[temppos] = heaparray[(temppos - 1) / 2];
			temppos = (temppos - 1) / 2;
		}
		heaparray[temppos] = temp;
	}
	void insert(const T & newnode)//����в�����Ԫ��newnode
	{
		heaparray[currentsize] = newnode;
		siftup(currentsize);
		currentsize++;

	}
	T & removemin()//�ӶѶ�ɾ����Сֵ
	{
		T temp;
		if (currentsize == 0)
		{
			cout << "can't delete";
			exit(1);
		}
		else
		{
			temp = heaparray[0];
			heaparray[0] = heaparray[currentsize - 1];
			heaparray[currentsize - 1] = temp;
			currentsize--;
			if (currentsize>0)
				siftdown(0);
			return heaparray[currentsize];
		}
	}
	bool isempty()
	{
		if (currentsize == 0)
			return true;
		else
			return false;
	}
};
template <class T>
class maxheap // �����ඨ��    ��ʼ�������룬ɾ���Ѷ�Ԫ��
{
private:
	T * heaparray;
	int currentsize;
	int maxsize;
public:
	maxheap(int n)
	{
		if (n <= 0)
			return;
		currentsize = 0;
		maxsize = n;
		heaparray = new T[maxsize];
		buildheap();
	}
	~maxheap()
	{
		delete[] heaparray;
	}
	void buildheap()
	{
		for (int i = currentsize / 2 - 1;i >= 0;i--)
			siftdown(i);//��������ɸѡ����
	}
	void siftdown(int left)//ɸѡ������������left��ʾ��ʼ����������±�
	{
		int i = left;
		int j = 2 * i + 1;
		T temp = heaparray[i];
		while (j<currentsize)
		{
			if ((j<currentsize - 1) && (heaparray[j]<heaparray[j + 1]))
				j++;
			if (temp<heaparray[j])
			{
				heaparray[i] = heaparray[j];
				i = j;
				//heaparray[i]=temp;
				j = 2 * j + 1;
			}
			else break;
		}
		heaparray[i] = temp;
	}
	void siftup(int pos)//��pos���Ͽ�ʼ����
	{
		int temppos = pos;
		T temp = heaparray[temppos];
		while ((temppos>0) && (heaparray[(temppos - 1) / 2]<temp))
		{
			heaparray[temppos] = heaparray[(temppos - 1) / 2];
			temppos = (temppos - 1) / 2;
		}
		heaparray[temppos] = temp;
	}
	void insert(const T & newnode)//����в�����Ԫ��newnode
	{
		heaparray[currentsize] = newnode;
		siftup(currentsize);
		currentsize++;

	}
	T & removemax()//�ӶѶ�ɾ�����ֵ
	{
		T temp;
		if (currentsize == 0)
		{
			cout << "can't delete";
			exit(1);
		}
		else
		{
			temp = heaparray[0];
			heaparray[0] = heaparray[currentsize - 1];
			heaparray[currentsize - 1] = temp;
			currentsize--;
			if (currentsize>0)
				siftdown(0);
			return heaparray[currentsize];
		}
	}
	void display()//�������Ԫ��
	{
		for (int i = 0;i<currentsize;i++)
			cout << heaparray[i] << " ";
		cout << endl;
	}
	bool isempty()
	{
		if (currentsize == 0)
			return true;
		else
			return false;
	}
};
template <typename T>//������
class Edge
{
public:
	int start;
	int end;
	T weight;
	Edge()
	{
		start = 0;
		end = 0;
	}
	Edge(int st, int en, int w)
	{
		start = st;
		end = en;
		weight = w;
	}
	bool operator > (Edge oneEdge)
	{
		return weight > oneEdge.weight;
	}
	bool operator < (Edge oneEdge)
	{
		return weight < oneEdge.weight;
	}
};

template <typename T>//ͼ����
class Graph
{
public:
	int vertexNum;//ͼ�Ķ�����Ŀ
	int edgeNum;//ͼ�ı���Ŀ
	int *Mark;//���ĳ�����Ƿ񱻷��ʹ�
	Graph(int verticesNum)
	{
		vertexNum = verticesNum;
		edgeNum = 0;
		Mark = new int[vertexNum];
		for (int i = 0;i < vertexNum;i++)
		{
			Mark[i] = 0;
		}
	}
	~Graph()
	{
		delete[]Mark;
		//delete[]Indegree;//����ʲô��������
	}
	void DFS(int v);
	void DFSTraverse();
	void DFSNoReverse();
	void BFS(int v);
	void BFSTraverse();
	void visit(int v)//���ʽ��
	{
		cout << v << ' ';
	}
	int VerticesNum()
	{
		return vertexNum;
	}
	int EdgesNum()
	{
		return edgeNum;
	}
	bool isEdge(Edge<T> oneEdge)
	{
		//��� oneEdge �Ǳ��򷵻�TRUE�����򷵻�FALSE
		if (oneEdge.weight > 0 && oneEdge.weight < INFINITY && oneEdge.end >= 0)
			return true;
		else
			return false;
	}
	int StartVertex(Edge<T> oneEdge)//���رߵ�ʼ��
	{
		return oneEdge.start;
	}
	int EndVertex(Edge<T> oneEdge)//���رߵ��յ�
	{
		return oneEdge.end;
	}
	T weight(Edge<T> oneEdge)//���رߵ�Ȩ
	{
		return oneEdge.weight;
	}
	virtual Edge<T> FirstEdge(int oneVertex) = 0;
	virtual Edge<T> NextEdge(Edge<T> oneEdge) = 0;
	virtual void setEdge(int start, int end, int weight) = 0;
	virtual void delEdge(int start, int end) = 0;
};

template <typename T>
class stack
{
private:
	int maxsize;
	int top;
	T *st;
public:
	stack()
	{
		top = -1;
	}
	stack(int size)
	{
		top = -1;
		maxsize = size;
		st = new T[maxsize];
	}
	~stack()
	{
		delete[]st;
	}
	void clear()
	{
		top = -1;
	}
	bool push(T item)
	{
		if (top == maxsize - 1)
		{
			T * newst = new T[maxsize * 2];
			for (int i = 0;i <= top;i++)
			{
				newst[i] = st[i];
			}
			delete[]st;
			st = newst;
			maxsize *= 2;
		}
		st[++top] = item;
		return true;
	}
	T pop()
	{
		if (top == -1)
		{
			cout << "ջΪ�գ����ܳ�ջ" << endl;
			return false;
		}
		else
		{
			T item;
			item = st[top--];
			return item;
		}
	}
	T Top()
	{
		if (top == -1)
		{
			cout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;
			//return false;
			exit(0);
		}
		else
		{
			return st[top];
		}
	}
	bool isEmpty()
	{
		if (top == -1)
			return 0;
		else
			return 1;
	}
	int gettop()
	{
		return top;
	}
	T getlast()
	{
		return st[top];
	}
};//ջ
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
		maxsize = size;
		arr = new T[maxsize];
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
	void push(T item)
	{
		arr[rear++] = item;
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
	void pop()
	{
		front++;
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
	T retfront()
	{
		if (isesmpty())
		{
			cout << "����Ϊ��" << endl;
			return 0;
		}
		else
			return arr[front];
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
};//����
template <typename T>
void Graph<T> ::DFS(int v)
{
	visit(v);
	Mark[v] = 1;
	for (Edge<T> e = FirstEdge(v);isEdge(e);e = NextEdge(e))
	{
		if (Mark[EndVertex(e)] == 0)
			DFS(EndVertex(e));
	}
}
template <typename T>//������ȵݹ�
void Graph<T>::DFSTraverse()
{
	for (int i = 0;i < VerticesNum();i++)
		Mark[i] = 0;
	for (int i = 0;i < VerticesNum();i++)//���ͼ�Ƿ���Ϊ���ʵĶ��㣬
	{									 //����У���Ӹö��㿪ʼ�����������
		if (Mark[i] == 0)
			DFS(i);
	}
}
template <typename T>//������ȷǵݹ�
void Graph<T>::DFSNoReverse()
{
	int i, v, u;
	stack<int> s(10);
	for (int i = 0;i < vertexNum;i++)//�����ж���ı�־λ���г�ʼ��
		Mark[i] = 0;
	for (i = 0;i < vertexNum;i++)
	{
		if (Mark[i] == 0)
		{
			s.push(i);
			visit(i);
			Mark[i] = 1;
			while (s.isEmpty())
			{
				v = s.getlast();
				v = s.pop();
				for (Edge<T> e = FirstEdge(v);isEdge(e);e = NextEdge(e))
				{
					u = EndVertex(e);
					if (Mark[u] == 0)
					{
						s.push(u);
						visit(u);
						Mark[u] = 1;
						break;
					}
				}
			}
		}
	}
}
template <typename T>//������ȵݹ�
void Graph<T>::BFSTraverse()
{
	int v = 0;
	for (v = 0;v < VerticesNum();v++)
		Mark[v] = 0;
	for (v = 0;v < VerticesNum();v++)
	{
		if (Mark[v] == 0)
			BFS(v);
	}
}
template <typename T>
void Graph<T>::BFS(int v)
{
	queue<int> Q(10);
	Mark[v] = 1;
	visit(v);
	Q.push(v);
	while (!Q.isesmpty())
	{
		v = Q.retfront();
		Q.pop();
		for (Edge<T>e = FirstEdge(v);isEdge(e);e = NextEdge(e))
		{
			int u = Mark[EndVertex(e)];
			int m = EndVertex(e);
			if (u == 0)
			{
				visit(m);
				Mark[m] = 1;
				Q.push(m);
			}
		}
	}
}


template <typename T>
class AdjGraph :public Graph<T>//ͼ���ڽӾ����ʾ
{
private:
	int ** matrix;
public:
	AdjGraph(int ver) :Graph(ver)
	{
		int i, j;
		matrix = (int **)new int *[ver];
		for (i = 0;i < ver;i++)
			matrix[i] = new int[ver];
		for (i = 0;i < ver;i++)
			for (j = 0;j < ver;j++)
				matrix[i][j] = 100;//��Ȩ��
	}
	~AdjGraph()
	{
		for (int i = 0;i < vertexNum;i++)
			delete[]matrix[i];
		delete[]matrix;
	}
	Edge<T> FirstEdge(int onevertex)//�����붥��������ĵ�һ����
	{
		Edge<T> tmpEdge;
		tmpEdge.start = onevertex;
		for (int i = 0;i < vertexNum;i++)
		{
			if (matrix[onevertex][i] != 100)
			{
				tmpEdge.end = i;
				tmpEdge.weight = matrix[onevertex][i];
				break;
			}
		}
		return tmpEdge;
	}
	Edge<T> NextEdge(Edge<T> oneEdge)//������oneEdge����ͬ������һ����
	{
		Edge<T> tmpEdge;
		tmpEdge.start = oneEdge.start;
		for (int i = oneEdge.end + 1;i < vertexNum;i++)
		{
			if (matrix[oneEdge.start][i] != 100)
			{
				tmpEdge.end = i;
				tmpEdge.weight = matrix[oneEdge.start][i];
				break;
			}
		}
		return tmpEdge;
	}
	void setEdge(int start, int end, T weight)//Ϊͼ����һ����
	{
		if (matrix[start][end] == 100)
			edgeNum++;
		matrix[start][end] = weight;
	}
	void delEdge(int start, int end)//ɾ��һ����
	{
		if (matrix[start][end] != 100)
			edgeNum--;
		matrix[start][end] = 100;
	}
	void Prim(int s)//Ӧ��prim�㷨��s��������õ�����С������
	{
		
		int i, j;

		int n = vertexNum;
		Edge<T> *MST = new Edge<T>[n - 1];//�洢��С�������ı�
		T *nearest = new T[n];//�������е㵽i�����С��Ȩֵ
		int *neighbor = new int[n];//����������i������ĵ��ţ�-1��ʾi���Ѿ���������������

		for (i = 0;i < n;i++)
		{
			neighbor[i] = s;
			nearest[i] = 9999;
		}
		for (Edge<T> e = FirstEdge(s);isEdge(e);e = NextEdge(e))
		{
			nearest[e.end] = e.weight;
		}

		neighbor[s] = -1;
		for (i = 0;i < n;i++)
		{
			T min = 9999;
			int v = -1;
			for (j = 0;j < n;j++)
			{
				if (nearest[j]<min&&neighbor[j]>-1)
				{
					min = nearest[j];
					v = j;
				}
			}
			if (v >= 0)
			{
				neighbor[v] = -1;
				Edge<T> tempEdge(neighbor[v], v, nearest[v]);
				MST[i] = tempEdge;
				for (Edge<T> e = FirstEdge(v);isEdge(e);e = NextEdge(e))
				{
					int u = e.end;
					if (neighbor[u] != -1 && nearest[u] > e.weight)
					{
						neighbor[u] = v;
						nearest[u] = e.weight;
					}
				}
			}
		}
		delete[]neighbor;
		delete[]nearest;
		for (i = 0;i < n - 1;i++)
			cout << MST[i].start + 1 << "->" << MST[i].end << ' ' << endl;
		cout << endl;
	}
	void kruskal()//��³˹�����㷨������С������
	{
		int n = vertexNum;
		UFSets set(n);
		Edge<T> * MS = new Edge<T>[n - 1];
		minheap<Edge<T>> H(edgeNum);
		Edge<T> edge;
		for (int i = 0;i<vertexNum;i++)
		{
			for (edge = FirstEdge(i);isEdge(edge);edge = NextEdge(edge))
			{
				if (StartVertex(edge)<EndVertex(edge))
					H.insert(edge);
			}
		}
		int edgenu = 0;
		while (edgenu<n - 1)
		{
			if (!H.isempty())
			{
				edge = H.removemin();
				int v = edge.start;
				int u = edge.end;
				if (set.find(v) != set.find(u))
				{
					set.Union(v, u);
					MS[edgenu++] = edge;
				}
			}
		}
		for (int m = 0;m < edgenu;m++)
			cout << MS[m].start << "->" << MS[m].end << "  " << MS[m].weight << ' ' << endl;
		cout << endl;
	}
	void dijkstra(int s)//�Ͻ���˹�����·��
	{
		int n = vertexNum;
		T * D = new T[n];
		int * Path = new int[n];//DΪȨֵ��PathΪǰ��
		int i, j;
		for (i = 0;i<n;i++)
		{
			Mark[i] = 0;
			D[i] = 100;
			Path[i] = -1;//��Ǵ�ʱ������s��i��·��
		}
		Mark[s] = 1;
		D[s] = 0;
		Path[s] = s;
		for (i = 0;i<n;i++)//�ҵ�һ���������·��
		{
			T min = 100;
			int k = 0;
			for (j = 1;j<n;j++)
			{
				if (Mark[j] == 0 && D[j] < min)
				{
					min = D[j];
					k = j;
				}
			}//��ȷ��s��k�����·��
			Mark[k] = 1;//����k���µ�����δ����·�������·��
			for (Edge<T> e = FirstEdge(k);isEdge(e);e = NextEdge(e))
			{
				int endv = e.end;
				if (Mark[endv] == 0 && (D[k] + e.weight) < D[endv] )
				{
					D[endv] = D[k] + e.weight;//���µ�endv���������·��
					Path[endv] = k;
				}
			}
		}
		for (i = 0;i<n;i++)
			cout << D[i] << ' ';
		cout << endl;
	}
	void floyd()//�����������·��
	{
		int i, j, v; //i,j�Ǽ�������v ��¼��Ӧ����
		int n = vertexNum;
		T ** adj = (T **)new T *[n];
		for (i = 0;i<n;i++)
			adj[i] = new T[n];
		int ** path = (int **)new int *[n];
		for (i = 0;i<n;i++)
			path[i] = new int[n];
		for (i = 0;i<n;i++) //��ʼ��D���飬Path����
		{
			for (j = 0;j<n;j++)
			{
				if (i == j)
				{
					adj[i][j] = 0;
					path[i][j] = i;
				}
				else
				{
					adj[i][j] = 10000;//��һ����Խϴ������ʾ����
					path[i][j] = -1;
				}
			}
		}
		for (v = 0;v<n;v++)//�������ߣ����ߣ�v,u)��ֵ��ΪAdj[v,u]��v��ΪPath[u]��ֵ
		{
			for (Edge<T> e = FirstEdge(v);isEdge(e);e = NextEdge(e))
			{
				adj[v][e.end] = e.weight;
				path[v][e.end] = v;
			}
		}
		for (v = 0;v<n;v++)//�����������i,j������·����������v,����Adj[i][j] > (Adj[i][v] + Adj[v][j]),�����Adj[i][j] , Path[i][j]
			for (i = 0;i<n;i++)
				for (j = 0;j<n;j++)
				{
					if (adj[i][j]>adj[i][v] + adj[v][j])
					{
						adj[i][j] = adj[i][v] + adj[v][j];
						path[i][j] = v;
					}
				}
		cout << endl << "�ڽӾ���" << endl;
		for (i = 0;i<n;i++)
			for (j = 0;j<n;j++)
				cout << adj[i][j] << ' ';
		cout << endl << "PathȨֵ��" << endl;
		for (i = 0;i<n;i++)
			for (j = 0;j<n;j++)
				cout << path[i][j] << ' ';
		cout << endl;

	}
};
class UFSets//�ȼ���
{
private:
	int n;
	int *root;
	int *next;
	int *length;
public:
	UFSets(int size)
	{
		n = size;
		root = new int[n];
		next = new int[n];
		length = new int[n];
		for (int i = 0;i < n;i++)
		{
			root[i] = next[i] = i;
			length[i] = 1;
		}
	}
	int find(int v)
	{
		return root[v];
	}
	void swap(int & i, int & j)
	{
		int temp;
		temp = i;
		i = j;
		j = temp;
	}
	void Union(int v, int u)
	{
		int rt, j;
		if (root[u] == root[v])
			return;
		else if (length[root[v]] < length[root[u]])
		{
			rt = root[v];
			length[root[u]] += length[rt];

			root[rt] = root[u];
			for (j = next[rt];j != rt;j = next[j])
			{
				root[j] = root[u];
			}
			swap(next[rt], next[root[u]]);
		}
		else
		{
			rt = root[u];
			length[root[v]] += length[rt];
			root[rt] = root[v];
			for (j = next[rt];j != rt;j = next[j])
				root[j] = root[v];
			swap(next[rt], next[root[v]]);
		}
	}
};
int main()
{
	AdjGraph <int> picture(8);
	{picture.setEdge(0, 1, 1);
	picture.setEdge(0, 2, 1);
	picture.setEdge(1, 0, 1);
	picture.setEdge(1, 3, 1);
	picture.setEdge(1, 4, 1);
	picture.setEdge(2, 0, 1);
	picture.setEdge(2, 5, 1);
	picture.setEdge(2, 6, 1);
	picture.setEdge(3, 1, 1);
	picture.setEdge(3, 7, 1);
	picture.setEdge(4, 1, 1);
	picture.setEdge(4, 7, 1);
	picture.setEdge(5, 2, 1);
	picture.setEdge(5, 6, 1);
	picture.setEdge(6, 2, 1);
	picture.setEdge(6, 5, 1);
	picture.setEdge(7, 3, 1);
	picture.setEdge(7, 4, 1);}
	
	cout << "������ȱ��������" << endl << "�ݹ飺" << endl;
	picture.DFSTraverse();
	cout << endl << "�ǵݹ飺" << endl;
	picture.DFSNoReverse();
	cout << endl;
	cout << "������ȣ�" << endl;
	picture.BFSTraverse();
	cout << endl;

	AdjGraph <int> tu2(6);
	{
	tu2.setEdge(0, 1, 6);
	tu2.setEdge(0, 2, 1);
	tu2.setEdge(0, 3, 5);
	tu2.setEdge(1, 0, 6);
	tu2.setEdge(1, 2, 5);
	tu2.setEdge(1, 4, 3);
	tu2.setEdge(2, 0, 1);
	tu2.setEdge(2, 1, 5);
	tu2.setEdge(2, 3, 5);
	tu2.setEdge(2, 4, 6);
	tu2.setEdge(2, 5, 4);
	tu2.setEdge(3, 0, 5);
	tu2.setEdge(3, 2, 5);
	tu2.setEdge(3, 5, 2);
	tu2.setEdge(4, 1, 3);
	tu2.setEdge(4, 2, 6);
	tu2.setEdge(4, 5, 6);
	tu2.setEdge(5, 2, 4);
	tu2.setEdge(5, 3, 2);
	tu2.setEdge(5, 4, 6);}
	cout << "Prim��С��������" << endl;
	tu2.Prim(0);
	cout << endl << "Kruskal��С��������" << endl;
	tu2.kruskal();
	cout << endl;
	cout << "�Ͻ���˹�����·����" << endl;
	tu2.dijkstra(0);
	cout << endl;
	AdjGraph <int> tu3(3);
	{tu3.setEdge(0, 1, 10);
	tu3.setEdge(0, 2, 5);
	tu3.setEdge(1, 0, 9);
	tu3.setEdge(1, 2, 6);
	tu3.setEdge(2, 0, 2);
	tu3.setEdge(2, 1, 13);}
	cout << "�����������·��" << endl;
	tu3.floyd();
	return 0;
}