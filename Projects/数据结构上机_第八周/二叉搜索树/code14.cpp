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
			cout << "�������������" << endl;
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
			cout << "����Ϊ��" << endl;
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
			cout << "����Ϊ��" << endl;
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
			cout << "ջΪ��";
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
	T data;//�洢�����ݣ������ǽ���Ϊint��char
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
	T getValue()
	{
		return data;
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
	void levelorder()//������ȱ���������������������������
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
	void preOrder(BinaryTreeNode<T> * root)//ǰ��ݹ�
	{
		if (root != NULL)
		{
			visit(root);
			preOrder(root->leftchild);
			preOrder(root->rightchild);
		}
	}
	void inOrder(BinaryTreeNode<T> * root)//����ݹ�
	{
		if (root != NULL)
		{
			inOrder(root->leftchild);
			visit(root);
			inOrder(root->rightchild);
		}
	}
	void postOrder(BinaryTreeNode<T> * root)//����ݹ�
	{
		if (root != NULL)
		{
			postOrder(root->leftchild);
			postOrder(root->rightchild);
			visit(root);
		}
	}
	BinaryTreeNode<T> * search(BinaryTreeNode<T> * r, T key)//�����������Ĳ���
	{
		BinaryTreeNode<T> * current = r;
		while ((NULL != r) && key != current->getValue() )
		{
			current = (key < current->getValue() ? search(current->leftchild, key) : search(current->rightchild, key));
		}
		return current;
	}
	BinaryTreeNode<T> * searchFather(BinaryTreeNode<T> * r, T key)//����Ҫɾ���ĸ����
	{
		BinaryTreeNode<T> * current = r;
		BinaryTreeNode<T> * father = NULL;
		if (key == r->data)
		{
			father = NULL;
			return father;
		}
		else
		{
			while (r != NULL && key != current->data)
			{
				father = current;
				current = (key < current->data ? current->leftchild : current->rightchild);
			}
			return father;
		}
	}
	void insert(const T& value)//�����������Ĳ���
	{
		BinaryTreeNode<T> *p = root, *pre = NULL;
		while (p != 0)
		{
			pre = p;
			if (p->getValue() < value)
				p = p->rightchild;
			else
				p = p->leftchild;
		}
		if (root == NULL)
			root = new BinaryTreeNode<T>(value);
		else if (pre->getValue() < value)
			pre->rightchild = new BinaryTreeNode<T>(value);
		else
			pre->leftchild = new BinaryTreeNode<T>(value);
	}
	void delete_Merging(BinaryTreeNode<T> *& node, BinaryTreeNode<T> *& nodefather)//�ϲ�ɾ��
	{
		BinaryTreeNode<T> *tmp = node;
		if (node != NULL)
		{
			//����ɾ�����û�����������������������ĸ��ڵ������汻ɾ�����
			if (!node->rightchild)
				node = node->leftchild;
			//����ɾ�����û�����������������������ĸ��ڵ������汻ɾ�����
			else if (node->leftchild == NULL)
				node = node->rightchild;
			else {
				tmp = node->leftchild;
				while (tmp->rightchild != NULL)
					tmp = tmp->rightchild;
				tmp->rightchild = node->rightchild;
				tmp = node;
				node = node->leftchild;
			}
			delete tmp;
		}
			/*
		BinaryTreeNode<T> *tmp = node;
		if (node->rightchild == NULL)//��ɾ���Ľ��û��������
		{
			if (nodefather)
			{
				if (nodefather->leftchild == node)
				{
					nodefather->leftchild = node->leftchild;
				}
				else
				{
					nodefather->rightchild = node->leftchild;
				}
			}
			else
				root = node->leftchild;
			delete node;
		}
		else if (node->leftchild == NULL)//��ɾ������������Ϊ��
		{
			if (nodefather)
			{
				if (nodefather->leftchild == node)
				{
					nodefather->leftchild = node->rightchild;
				}
				else
				{
					nodefather->leftchild = node->leftchild;
				}
			}
			else
				root = node->rightchild;
			delete node;
		}
		else
		{
			tmp = node->leftchild;
			while (tmp->rightchild != NULL)
				tmp = tmp->rightchild;
			tmp->rightchild = node->rightchild;
			if (nodefather->leftchild == node)
			{
				nodefather->leftchild = node->leftchild;
			}
			else
			{
				nodefather->rightchild = node->leftchild;
			}
			delete node;
		}
		cout << endl;
		*/
	}
	void delete_coping(BinaryTreeNode<T> *& node, BinaryTreeNode<T> *& nodefather)//����ɾ��
	{
		BinaryTreeNode<T> *previous, *tmp = node;
		if (node->rightchild == NULL)//��ɾ���Ľ��û��������
		{
			if (nodefather)
			{
				if (nodefather->leftchild == node)
				{
					nodefather->leftchild = node->leftchild;
				}
				else
				{
					nodefather->rightchild = node->leftchild;
				}
			}
			else
				root = node->leftchild;
			delete node;
		}
		else if (node->leftchild == NULL)//��ɾ������������Ϊ��
		{
			if (nodefather)
			{
				if (nodefather->leftchild == node)
				{
					nodefather->leftchild = node->rightchild;
				}
				else
				{
					nodefather->leftchild = node->leftchild;
				}
			}
			else
				root = node->rightchild;
			delete node;
		}
		else
		{
			tmp = node->leftchild;
			previous = node;
			while (tmp->rightchild != NULL)
			{
				previous = tmp;
				tmp = tmp->rightchild;
			}
			node->data = tmp->data;
			if (previous == node)
				previous->leftchild = tmp->leftchild;
			else
				previous->rightchild = tmp->leftchild;
			delete tmp;
		}
		cout << endl;
	}
};

int main()
{
	BinaryTree<int> tree;
	BinaryTreeNode<int> * treenode1, *treenode2;
	tree.insert(223);
	tree.insert(985);
	tree.insert(2015);
	tree.insert(11);
	tree.insert(29);
	tree.insert(2);
	tree.insert(16);
	tree.insert(18);
	tree.levelorder();
	cout << endl;
	treenode1 = tree.search(tree.root, 16);
	treenode2 = tree.searchFather(tree.root, 16);
	tree.delete_coping(treenode1, treenode2);
	cout << "����ɾ��16��Ϊ��";
	tree.levelorder();
	treenode1 = tree.search(tree.root, 29);
	treenode2 = tree.searchFather(tree.root, 29);
	tree.delete_Merging(treenode1, treenode2);
	cout << "�ϲ�ɾ��29��Ϊ��";
	tree.levelorder();
	
	
	return 0;
}