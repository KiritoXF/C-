#include <iostream>
#include <string>
using namespace std;

template <typename T>
class queue
{
private:
	int maxsize;
	int front;
	int rear;
	T *arr;
public:
	queue(int size = 10)
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
	bool enqueue(T item)
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
	bool dequeue(T item)
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
	T getfront()
	{
		if (front == rear)
		{
			cout << "队列为空" << endl;
			return false;
		}
		return arr[front];
	}
	void pop()
	{
		front++;
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
template <class T>
class stack
{
private:
	int top;
	int maxsize;
	T * sta;
public:
	stack(int size = 10)
	{
		maxsize = size;
		sta = new T[maxsize];
		top = -1;
	}
	~stack()
	{
		delete[]sta;
	}
	void push(T t)
	{
		sta[++top] = t;
	}
	bool empty()
	{
		return top == -1;
	}
	bool full()
	{
		return top == maxsize - 1;
	}
	T Top()
	{
		if (empty())
		{
			cout << "栈为空";
			return 0;
		}
		else
			return sta[top];
	}
	void pop()
	{
		top--;
	}
};
template <typename T>
class BinaryTreeNode
{
public:
	T data;//存储的数据，测试是建议为int
	BinaryTreeNode<T> *leftchild;
	BinaryTreeNode<T> *rightchild;
	BinaryTreeNode()
	{
		leftchild = rightchild = NULL;
	}
	BinaryTreeNode(T dat)
	{
		data = dat;
		leftchild = NULL;
		rightchild = NULL;
	}
	BinaryTreeNode(T dat, BinaryTreeNode *left, BinaryTreeNode *right)
	{
		data = dat;
		leftchild = left;
		rightchild = right;
	}
};
template <typename T>
class BinaryTree
{
public:
	BinaryTreeNode<T> *root;
	BinaryTree(BinaryTreeNode<T> *t = NULL)
	{
		root = t;
	}
	bool isempty()
	{
		if (root == NULL)
			return true;
		else
			return false;
	}
	void makeTree(const T dat, BinaryTree<T> left, BinaryTree<T> right)
	{
		root = new BinaryTreeNode<T>(dat, left.root, right.root);
		left.root = right.root = 0;
	}
	void visit(BinaryTreeNode<T> *t)
	{
		cout << t->data << "  ";
	}
	void levelorder()//广度优先遍历二叉树（即逐层遍历二叉树）
	{
		queue<BinaryTreeNode<T> *> nodequeue;
		BinaryTreeNode<T> * pointer = root;
		if (pointer)
			nodequeue.enqueue(pointer);
		while (!nodequeue.isesmpty())
		{
			pointer = nodequeue.getfront();
			visit(pointer);
			nodequeue.pop();
			if (pointer->leftchild)
				nodequeue.enqueue(pointer->leftchild);
			if (pointer->rightchild)
				nodequeue.enqueue(pointer->rightchild);
		}
	}
	void preOrder(BinaryTreeNode<T> * root)//前序递归
	{
		if (root != NULL)
		{
			visit(root);
			preOrder(root->leftchild);
			preOrder(root->rightchild);
		}
	}
	void inOrder(BinaryTreeNode<T> * root)//中序递归
	{
		if (root != NULL)
		{
			inOrder(root->leftchild);
			visit(root);
			inOrder(root->rightchild);
		}
	}
	void postOrder(BinaryTreeNode<T> * root)//后序递归
	{
		if (root != NULL)
		{
			postOrder(root->leftchild);
			postOrder(root->rightchild);
			visit(root);
		}
	}
		void preorderwithoutrecusion(BinaryTreeNode<T> * r)//非递归前序遍历二叉树
		{
			stack<BinaryTreeNode<T> *>nodestack;
			BinaryTreeNode<T> * pointer = r;
			while (!nodestack.empty() || pointer)
			{
				if (pointer)
				{
					visit(pointer);
					if (pointer->rightchild != NULL)
						nodestack.push(pointer->rightchild);
					pointer = pointer->leftchild;
				}
				else
				{
					pointer = nodestack.Top();
					nodestack.pop();
				}
			}
		}
		void inorderwithoutrecusion(BinaryTreeNode<T> * r)//非递归中序遍历二叉树
		{
			stack<BinaryTreeNode<T> *>nodestack;
			BinaryTreeNode<T> * pointer = r;
			while (!nodestack.empty() || pointer)
			{
				if (pointer)
				{
					nodestack.push(pointer);
					pointer = pointer->leftchild;

				}
				else
				{
					pointer = nodestack.Top();
					visit(pointer);
					pointer = pointer->rightchild;
					nodestack.pop();
				}
			}
		}
		void postorderwithoutrecusion(BinaryTreeNode<T> *r)//非递归后序遍历
		{
			stack<BinaryTreeNode<T> *> nodestack;
			BinaryTreeNode<T> *pointer = r;
			BinaryTreeNode<T> *pre = r;
			while (pointer)
			{
				for (;pointer->leftchild != NULL;pointer = pointer->leftchild)
					nodestack.push(pointer);
				while (pointer != NULL && (pointer->rightchild == NULL || pointer->rightchild == pre))
				{
					visit(pointer);
					pre = pointer;
					if (nodestack.empty())
						return;
					pointer = nodestack.Top();
					nodestack.pop();
				}
				nodestack.push(pointer);
				pointer = pointer->rightchild;
			}
		}
		void calculatedu(BinaryTreeNode<T> *t)//统计二叉树中度为1、2的结点的个数
		{
			BinaryTreeNode<T> *pointer = t;
			int num0 = 0, num1 = 0, num2 = 0;
			stack<BinaryTreeNode<T> *> nodestack;

			while (pointer != NULL || !nodestack.empty())
			{
				if (pointer)
				{
					if (pointer->leftchild == NULL && pointer->rightchild == NULL)
						num0++;
					if (pointer->leftchild == NULL && pointer->rightchild != NULL)
						num1++;
					if (pointer->leftchild != NULL && pointer->rightchild == NULL)
						num1++;
					if (pointer->leftchild != NULL && pointer->rightchild != NULL)
						num2++;
					if (pointer->rightchild != NULL)
					{
						nodestack.push(pointer->rightchild);
					}

					pointer = pointer->leftchild;
				}
				else
				{
					pointer = nodestack.Top();
					nodestack.pop();
				}
			}
			cout << "度为0的结点的个数" << num0 << endl;
			cout << "度为1的结点的个数" << num1 << endl;
			cout << "度为2的结点的个数" << num2 << endl;
		}
		int height(BinaryTreeNode<T> *t)//求二叉树的高度
		{
			if (!t)
				return 0;
			int h_left = height(t->leftchild);
			int h_right = height(t->rightchild);
			if (h_left > h_right)
				return ++h_left;
			else
				return ++h_right;
		}
		void changeLeftRight(BinaryTreeNode<T> *p)//交换每个结点的左孩子结点和右孩子结点（注：这个函数可能存在问题）
		{
			//BinaryTreeNode<T> *p = root;
			if (p)
			{
				BinaryTreeNode<T> *temp;
				if (p->leftchild == 0 && p->rightchild != 0)
				{
					p->leftchild = p->rightchild;
					p->rightchild = 0;
				}
				if (p->leftchild != 0 && p->rightchild == 0)
				{
					p->rightchild = p->leftchild;
					p->leftchild = 0;
				}
				if (p->leftchild != 0 && p->rightchild != 0)
				{
					temp = p->leftchild;
					p->leftchild = p->rightchild;
					p->rightchild = temp;
				}
			}
			else
			{
				return;
			}
			changeLeftRight(p->leftchild);
			changeLeftRight(p->rightchild);
		}
		void deleteLeaves(BinaryTreeNode<T> *r)//删除所有叶节点
		{
			queue<BinaryTreeNode<T> *> nodeque;
			BinaryTreeNode<T> *pointer = root;
			BinaryTreeNode<T> *temp;
			BinaryTreeNode<T> *parent = pointer;
			int tag = 0;

			if (parent)
				nodeque.enqueue(parent);

			while (!nodeque.isesmpty())
			{
				parent = nodeque.getfront();
				if (parent->leftchild != NULL)
				{
					pointer = parent->leftchild;
					tag = 1;
				}
				else if (parent->rightchild != NULL)
				{
					pointer = parent->rightchild;
					tag = 2;
				}
			//m:
				if (pointer->leftchild == NULL && pointer->rightchild == NULL)
				{
					if (parent->leftchild == pointer)
						parent->leftchild = NULL;
					else if (parent->rightchild == pointer)
						parent->rightchild = NULL;
					
				}
				/*if (tag == 2) 
				{
					pointer = parent->leftchild;
					goto m;
				}
				else if (tag == 1)
				{
					pointer = parent->rightchild;
					goto m;
				}
				*/
			
				/*if ((pointer->leftchild != NULL && pointer->rightchild == NULL) || (pointer->leftchild == NULL && pointer->rightchild != NULL))
				{
					goto m;
					//continue;
				}
				if ((pointer->leftchild->leftchild == NULL) && (pointer->leftchild->rightchild == NULL))
				{
					temp = pointer->leftchild;
					delete temp;
					//pointer->leftchild = NULL;
				}
				
				if ((pointer->rightchild->leftchild == NULL) && (pointer->rightchild->rightchild == NULL))
				{
					temp = pointer->rightchild;
					delete temp;
					//pointer->rightchild = NULL;

				}*/
			//m:
				nodeque.pop();
				if (parent->leftchild)
					nodeque.enqueue(parent->leftchild);
				if (parent->rightchild)
					nodeque.enqueue(parent->rightchild);
			}
		}
		void prefectTree(BinaryTreeNode<T> *r)//判断是否为完全二叉树
		{
			queue<BinaryTreeNode<T> *> nodeque;
			BinaryTreeNode<T> *pointer = root;
			int tag = 0;
			if (pointer)
				nodeque.enqueue(pointer);

			while (!nodeque.isesmpty())
			{
				pointer = nodeque.getfront();
				if (pointer->leftchild == NULL || pointer->rightchild == NULL)
				{
					tag = 1;
					break;
				}
				nodeque.pop();

				if (pointer->leftchild)
					nodeque.enqueue(pointer->leftchild);
				if (pointer->rightchild)
					nodeque.enqueue(pointer->rightchild);
			}
			if (tag)
				cout << "非完全二叉树" << endl;
			else
				cout << "是完全二叉树" << endl;
		}
		int calculatewidth(BinaryTreeNode<T> * t) //计算二叉树宽度
		{
			int static n[10];//向量存放各层结点数
			int static i = 1;
			int static max = 0;//最大宽度
			if (t)
			{
				if (i == 1) //若是访问根结点
				{
					n[i]++; //第1层加1
					i++; //到第2层
					if (t->leftchild)//若有左孩子则该层加1
						n[i]++;
					if (t->rightchild)//若有右孩子则该层加1
						n[i]++;
				}
				else
				{      //访问子树结点
					i++; //下一层结点数
					if (t->leftchild)
						n[i]++;
					if (t->rightchild)
						n[i]++;
				}
				if (max < n[i])
					max = n[i];//取出最大值
				calculatewidth(t->leftchild);//遍历左子树
				if (!t->leftchild)
					i--; //往上退一层
				calculatewidth(t->rightchild);//遍历右子树
			}
			return  max;
		}
		/*
		bool is_complete(BinaryTreeNode<T> *root)
		{
			queue<BinaryTree<T> *> q;
			BinaryTreeNode<T> *ptr;
			// 进行广度优先遍历（层次遍历），并把NULL节点也放入队列
			q.push(root);
			while ((ptr = q.pop()) != NULL)
			{
				q.enqueue(ptr->leftchild);
				q.enqueue(ptr->rightchild);
			}

			// 判断是否还有未被访问到的节点
			while (!q.isesmpty())
			{
				ptr = q.pop();

				// 有未访问到的的非NULL节点，则树存在空洞，为非完全二叉树
				if (NULL != ptr)
				{
					return false;
				}
			}

			return true;
		}
		*/
	};

typedef struct BiNode 
{
	char data;//节点数据  
	struct BiNode * lchild;//左孩子  
	struct BiNode * rchild;//右孩子  
}BiNode, *BiTree;
/*
bool judgement(char *arr)//判断是否只剩下一个元素
{
	int temp = 0;
	while (arr != NULL)
	{
		temp++;
	}
	if (temp == 1)
		return true;
	if (temp > 1)
		return false;
	else
	{
		cout << "程序出现意外错误，请检查judgement(int *arr)函数" << endl;
		return false;
	}
}*/
void makeBypre_in(BiTree &t,string arr_pre,string arr_in)//前中序列构造二叉树
{
	if (arr_pre.length() == 0)
	{
		t = NULL;
		return;
	}

		char root = arr_pre[0];
		int index = arr_in.find(root);
		string lchild_in = arr_in.substr(0, index);
		string rchild_in = arr_in.substr(index + 1);
		int lchild_length = lchild_in.length();
		int rchild_length = rchild_in.length();
		string lchild_pre = arr_pre.substr(1, lchild_length);
		string rchild_pre = arr_pre.substr(1 + lchild_length);

		t = (BiTree)malloc(sizeof(BiNode));
		if (t != NULL)
		{
			t->data = root;
			makeBypre_in(t->lchild, lchild_pre, lchild_in);
			makeBypre_in(t->rchild, rchild_pre, rchild_in);
		}	
}
/*
void makeByin_post(BiTree &t,string arr_in,string arr_post)
{
	if (arr_in.length() == 0)
	{
		t = NULL;
		return;
	}
	char root = arr_post[arr_post.length() - 1];
	int index = arr_in.find(root);
	string lchild_in = arr_in.substr(0, index);
	string rchild_in = arr_in.substr(index + 1);
	int lchild_length = lchild_in.length();
	int rchild_length = rchild_in.length();
	string lchild_post = arr_post.substr(1, lchild_length);
	string rchild_post = arr_post.substr(1 + lchild_length);

	t = (BiTree)malloc(sizeof(BiNode));
	if (t != NULL)
	{
		t->data = root;
		makeByin_post(t->lchild, lchild_post, lchild_in);
		makeByin_post(t->rchild, rchild_post, rchild_in);
	}
}*/
void makeByin_post(BiTree &t, string arr_in, string arr_post)//中后序列构造二叉树
{
	int i = 0;
	int n = 0;
	int len;
	int len_in = arr_in.length();
	int len_post = arr_post.length();
	char *in_left = new char[len_in], *in_right = new char[len_in], *post_left = new char[len_post], *post_right = new char[len_post];
	char ch;

	if (arr_in.length() == 0)
	{
		t = NULL;
		return;
	}
	t = (BiTree)malloc(sizeof(BiNode));
	/*if (t != NULL)
	{
		exit(1);
	}
	*/
	len = arr_post.length();
	ch = arr_post[len - 1];
	t->data = ch;
	memset(in_left, 0, sizeof(in_left));
	memset(post_left, 0, sizeof(post_left));
	memset(in_right, 0, sizeof(in_right));
	memset(post_right, 0, sizeof(post_right));
	while (arr_in[n] != ch)
	{
		in_left[n] = arr_in[n];
		post_left[n] = arr_post[n];
		n++;
	}
	while (arr_post[n + 1] != '\0')
	{
		in_right[i] = arr_in[n + 1];
		post_right[i] = arr_post[n];
		i++;
		n++;
	}

	makeByin_post(t->lchild,in_left, post_left);
	makeByin_post(t->rchild,in_right, post_right);
}
void preOrder(BiTree &t)//前序递归
{
	if (t != NULL)
	{
		cout << t->data;
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}
void inOrder(BiTree &t)//中序递归
{
	if (t != NULL)
	{
		inOrder(t->lchild);
		cout << t->data;
		inOrder(t->rchild);
	}
}
void postOrder(BiTree &t)//后序递归
{
	if (t != NULL)
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		cout << t->data;
	}
}

int main()
{
	BinaryTreeNode<int> a(1), b(2), c(3);
	BinaryTreeNode<int> d(4, &a, &b), e(5, NULL, &c);
	BinaryTreeNode<int> f(6, NULL, &d), g(7, NULL, &e);
	BinaryTreeNode<int> h(8, &f, &g);
	
	BinaryTree<int> tree1(&h);
	tree1.levelorder();
	tree1.preOrder(&h);
	cout << endl;
	tree1.preorderwithoutrecusion(&h);
	cout << endl;
	tree1.inOrder(&h);
	cout << endl;
	tree1.inorderwithoutrecusion(&h);
	cout << endl;
	tree1.postOrder(&h);
	cout << endl;
	tree1.postorderwithoutrecusion(&h);
	
	cout << endl << "先序、中序序列构造二叉树:" << endl;
	//char arr_pre[11] = { 'E','B','A','D','C','F','H','G','I','K','J' };
	//char arr_in[11] = { 'A','B','C','D','E','F','G','H','I','J','K' };
	BiTree t;
	string arr_pre = "EBADCFHGIKJ";
	string arr_in = "ABCDEFGHIJK";
	makeBypre_in(t, arr_pre, arr_in);
	preOrder(t);
	cout << endl;
	inOrder(t);
	cout << endl;
	
	cout << endl << "中序、后序序列构造二叉树:" << endl;
	BiTree tree;
	string arr_in_2 = "BEDAC";
	string arr_post = "EDBCA";
	makeByin_post(tree, arr_in_2, arr_post);
	inOrder(tree);
	cout << endl;
	postOrder(tree);
	cout << endl << endl;
	tree1.calculatedu(&h);
	cout << "统计二叉树的高度：" << tree1.height(&h) << endl << endl;
	cout << "原树：" << endl;
	tree1.inOrder(&h);
	cout << endl << "交换每个结点的左孩子结点和右孩子结点：" << endl;
	//tree1.changeLeftRight(&h);
	tree1.inOrder(&h);
	cout << endl << "删除所有叶节点：" << endl;
	tree1.deleteLeaves(&h);
	tree1.inOrder(&h);
	cout << endl << endl << "判断是否是完全二叉树：" << endl;
	tree1.prefectTree(&h);
	cout << endl << "计算二叉树最大宽度：" << endl;
	cout << tree1.calculatewidth(&h) - 1;
	
	return 0;
}