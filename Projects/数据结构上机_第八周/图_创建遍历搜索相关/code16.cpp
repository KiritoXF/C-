#include <iostream>
using namespace std;

template <class T>
class minheap // 最小堆类定义    初始化，插入，删除堆顶元素
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
			siftdown(i);//反复调用筛选函数
	}
	void siftdown(int left)//筛选法函数，参数left表示开始处理的数组下标
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
	void siftup(int pos)//从pos向上开始调整
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
	void insert(const T & newnode)//向堆中插入新元素newnode
	{
		heaparray[currentsize] = newnode;
		siftup(currentsize);
		currentsize++;

	}
	T & removemin()//从堆顶删除最小值
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
class maxheap // 最大堆类定义    初始化，插入，删除堆顶元素
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
			siftdown(i);//反复调用筛选函数
	}
	void siftdown(int left)//筛选法函数，参数left表示开始处理的数组下标
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
	void siftup(int pos)//从pos向上开始调整
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
	void insert(const T & newnode)//向堆中插入新元素newnode
	{
		heaparray[currentsize] = newnode;
		siftup(currentsize);
		currentsize++;

	}
	T & removemax()//从堆顶删除最大值
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
	void display()//输出树中元素
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
template <typename T>//边类型
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

template <typename T>//图类型
class Graph
{
public:
	int vertexNum;//图的顶点数目
	int edgeNum;//图的边数目
	int *Mark;//标记某顶点是否被访问过
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
		//delete[]Indegree;//这是什么鬼！！！！
	}
	void DFS(int v);
	void DFSTraverse();
	void DFSNoReverse();
	void BFS(int v);
	void BFSTraverse();
	void visit(int v)//访问结点
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
		//如果 oneEdge 是边则返回TRUE，否则返回FALSE
		if (oneEdge.weight > 0 && oneEdge.weight < INFINITY && oneEdge.end >= 0)
			return true;
		else
			return false;
	}
	int StartVertex(Edge<T> oneEdge)//返回边的始点
	{
		return oneEdge.start;
	}
	int EndVertex(Edge<T> oneEdge)//返回边的终点
	{
		return oneEdge.end;
	}
	T weight(Edge<T> oneEdge)//返回边的权
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
			cout << "栈为空，不能出栈" << endl;
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
			cout << "栈为空，不能读取栈顶元素" << endl;
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
};//栈
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
			cout << "队列已满，溢出" << endl;
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
			cout << "队列为空" << endl;
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
			cout << "队列为空" << endl;
			return false;
		}
		item = arr[item];
		return true;
	}
	T retfront()
	{
		if (isesmpty())
		{
			cout << "队列为空" << endl;
			return 0;
		}
		else
			return arr[front];
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
};//队列
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
template <typename T>//深度优先递归
void Graph<T>::DFSTraverse()
{
	for (int i = 0;i < VerticesNum();i++)
		Mark[i] = 0;
	for (int i = 0;i < VerticesNum();i++)//检查图是否有为访问的顶点，
	{									 //如果有，则从该顶点开始深度优先搜索
		if (Mark[i] == 0)
			DFS(i);
	}
}
template <typename T>//深度优先非递归
void Graph<T>::DFSNoReverse()
{
	int i, v, u;
	stack<int> s(10);
	for (int i = 0;i < vertexNum;i++)//对所有顶点的标志位进行初始化
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
template <typename T>//广度优先递归
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
class AdjGraph :public Graph<T>//图的邻接矩阵表示
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
				matrix[i][j] = 100;//存权重
	}
	~AdjGraph()
	{
		for (int i = 0;i < vertexNum;i++)
			delete[]matrix[i];
		delete[]matrix;
	}
	Edge<T> FirstEdge(int onevertex)//返回与顶点相关联的第一条边
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
	Edge<T> NextEdge(Edge<T> oneEdge)//返回与oneEdge有相同起点的下一条边
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
	void setEdge(int start, int end, T weight)//为图新增一条边
	{
		if (matrix[start][end] == 100)
			edgeNum++;
		matrix[start][end] = weight;
	}
	void delEdge(int start, int end)//删除一条边
	{
		if (matrix[start][end] != 100)
			edgeNum--;
		matrix[start][end] = 100;
	}
	void Prim(int s)//应用prim算法从s顶点出发得到的最小生成树
	{
		
		int i, j;

		int n = vertexNum;
		Edge<T> *MST = new Edge<T>[n - 1];//存储最小生成树的边
		T *nearest = new T[n];//生成树中点到i点的最小边权值
		int *neighbor = new int[n];//生成树中与i点最近的点编号，-1表示i点已经在生成树集合中

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
	void kruskal()//克鲁斯卡尔算法计算最小生成树
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
	void dijkstra(int s)//迪杰特斯拉最短路径
	{
		int n = vertexNum;
		T * D = new T[n];
		int * Path = new int[n];//D为权值，Path为前驱
		int i, j;
		for (i = 0;i<n;i++)
		{
			Mark[i] = 0;
			D[i] = 100;
			Path[i] = -1;//标记此时不存在s到i的路径
		}
		Mark[s] = 1;
		D[s] = 0;
		Path[s] = s;
		for (i = 0;i<n;i++)//找到一条最短特殊路径
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
			}//已确定s到k的最短路径
			Mark[k] = 1;//利用k更新到其余未访问路径的最短路径
			for (Edge<T> e = FirstEdge(k);isEdge(e);e = NextEdge(e))
			{
				int endv = e.end;
				if (Mark[endv] == 0 && (D[k] + e.weight) < D[endv] )
				{
					D[endv] = D[k] + e.weight;//更新到endv的最短特殊路径
					Path[endv] = k;
				}
			}
		}
		for (i = 0;i<n;i++)
			cout << D[i] << ' ';
		cout << endl;
	}
	void floyd()//弗洛伊德最短路径
	{
		int i, j, v; //i,j是计数器，v 记录相应顶点
		int n = vertexNum;
		T ** adj = (T **)new T *[n];
		for (i = 0;i<n;i++)
			adj[i] = new T[n];
		int ** path = (int **)new int *[n];
		for (i = 0;i<n;i++)
			path[i] = new int[n];
		for (i = 0;i<n;i++) //初始化D数组，Path数组
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
					adj[i][j] = 10000;//用一个相对较大的数表示无限
					path[i][j] = -1;
				}
			}
		}
		for (v = 0;v<n;v++)//检查各条边，将边（v,u)的值作为Adj[v,u]，v作为Path[u]的值
		{
			for (Edge<T> e = FirstEdge(v);isEdge(e);e = NextEdge(e))
			{
				adj[v][e.end] = e.weight;
				path[v][e.end] = v;
			}
		}
		for (v = 0;v<n;v++)//如果两个顶点i,j间的最短路径经过顶点v,且有Adj[i][j] > (Adj[i][v] + Adj[v][j]),则更新Adj[i][j] , Path[i][j]
			for (i = 0;i<n;i++)
				for (j = 0;j<n;j++)
				{
					if (adj[i][j]>adj[i][v] + adj[v][j])
					{
						adj[i][j] = adj[i][v] + adj[v][j];
						path[i][j] = v;
					}
				}
		cout << endl << "邻接矩阵：" << endl;
		for (i = 0;i<n;i++)
			for (j = 0;j<n;j++)
				cout << adj[i][j] << ' ';
		cout << endl << "Path权值：" << endl;
		for (i = 0;i<n;i++)
			for (j = 0;j<n;j++)
				cout << path[i][j] << ' ';
		cout << endl;

	}
};
class UFSets//等价类
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
	
	cout << "深度优先遍历输出：" << endl << "递归：" << endl;
	picture.DFSTraverse();
	cout << endl << "非递归：" << endl;
	picture.DFSNoReverse();
	cout << endl;
	cout << "广度优先：" << endl;
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
	cout << "Prim最小生成树：" << endl;
	tu2.Prim(0);
	cout << endl << "Kruskal最小生成树：" << endl;
	tu2.kruskal();
	cout << endl;
	cout << "迪杰特斯拉最短路径：" << endl;
	tu2.dijkstra(0);
	cout << endl;
	AdjGraph <int> tu3(3);
	{tu3.setEdge(0, 1, 10);
	tu3.setEdge(0, 2, 5);
	tu3.setEdge(1, 0, 9);
	tu3.setEdge(1, 2, 6);
	tu3.setEdge(2, 0, 2);
	tu3.setEdge(2, 1, 13);}
	cout << "弗洛伊德最短路径" << endl;
	tu3.floyd();
	return 0;
}