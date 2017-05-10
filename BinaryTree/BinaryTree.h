#include"queue"
#include"assert.h"
using namespace std;
template<typename T>struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode*_left;
	BinaryTreeNode*_right;
	BinaryTreeNode(const T&data = T()) :_data(data), _left(NULL), _right(NULL)
	{}
};
template<typename T>class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
protected:
	Node*_root;
public:
	BinaryTree() :_root(NULL)
	{}
	BinaryTree(const T*array, size_t size, const T&invalid)
	{
		size_t index = 0;
		_root = _CreateTree(array, size,index,invalid);
	}
	BinaryTree(const BinaryTree<T>&bt)
	{
		_root = _Copy(bt._root);
	}
	BinaryTree<T>&operator=(const BinaryTree<T>&bt)
	{
		if (this != &bt)//防止自赋值
		{
			BinaryTree<T>tmp(bt);
			std::swap(_root, tmp._root);
		}
		return *this;
	}
	~BinaryTree()
	{
		_Destroy(_root);
	}
	void PrevOrder()
	{
		//前序遍历
		_PreOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		//中序遍历
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()
	{
		//后序遍历
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()
	{
		//层次遍历
		_LevelOrder(_root);
		cout << endl;
	}
	size_t Size()
	{
		//求树的总节点数
		size_t size = _Size(_root);
		return size;
	}
	size_t Depth()
	{
		//求树的深度
		size_t depth = _Depth(_root);
		return depth;
	}
	size_t LeafSize()
	{
		//求一个树叶子结点的总数
		size_t leaf = _LeafSize(_root);
		return leaf;
	}
	size_t GetKLevel(int level)
	{
		//level 层的所有节点的个数
		size_t count = _GetKLevel(_root, level);
		return count;
	}
protected:
	Node*_CreateTree(const T*array, size_t size, size_t&index, const T&invalid)
	{
		assert(array);
		Node*root = NULL;
		if (index < size&&array[index] != invalid)
		{
			root = new Node(array[index]);
			root->_left = _CreateTree(array, size, ++index, invalid);
			root->_right = _CreateTree(array, size, ++index, invalid);
		}
		return root;
	}
	Node*_Copy(Node*root)
	{
		Node*cur = root;
		Node*proot = NULL;
		if (cur)
		{
			proot = new Node(cur->_data);
			proot->_left = _Copy(cur->_left);
			proot->_right = _Copy(cur->_right);
		}
		return proot;
	}
	void _Destroy(Node*root)
	{
		Node*cur = root;
		if (cur)
		{
			_Destroy(cur->_left);
			_Destroy(cur->_right);
			delete cur;
			cur = NULL;
		}
	}
	protected:
		void _PreOrder(Node*root)
		{
			Node*cur = root;
			if (cur)
			{
				cout << cur->_data << " ";
				_PreOrder(root->_left);
				_PreOrder(root->_right);
			}
		}
		void _InOrder(Node*root)
		{
			Node*cur = root;
			if (cur)
			{
				_InOrder(cur->_left);
				cout << cur->_data << " ";
				_InOrder(cur->_right);
			}
		}
		void _PostOrder(Node*root)
		{
			Node*cur = root;
			if (cur)
			{
				_PostOrder(cur->_left);
				_PostOrder(cur->_right);
				cout << cur->_data << " ";
			}
		}
		void _LevelOrder(Node*root)
		{
			queue<Node*>q;/////队列！！！！！！！！！！！！
			Node*cur = root;
			q.push(cur);
			while (!q.empty())
			{
				Node*t = q.front();
				cout << t->_data << " ";
				if (t->_left != NULL)
				{
					q.push(t->_left);
				}
				if (t->_right != NULL)
				{
					q.push(t->_right);
				}
				q.pop();
			}
		}
		size_t _Size(Node*root)
		{
			if (root == NULL)
			{
				return 0;//空树
			}
			return 1 + _Size(root->_left) + _Size(root->_right);
		}
		size_t _Depth(Node*root)
		{
			Node*cur = root;
			if (root == NULL)
			{
				return 0;
			}
			return 1 + (_Depth(cur->_left) > _Depth(cur->_right) ? _Depth(cur->_left) : _Depth(cur->_right));
		}
		size_t _LeafSize(Node*root)
		{
			Node*cur = root;
			if (cur == NULL)
			{
				return 0;
			}
			else if ((cur->_left == NULL) && (cur->_right == NULL))
			{
				return 1;
			}
			else
			{
				return _LeafSize(cur->_left) + _LeafSize(cur->_right);
			}
		}
		size_t _GetKLevel(Node*root, int level)
		{
			size_t count = 0;
			if (root == NULL)
			{
				return 0;
			}
			if (level == 1)
			{
				count++;
			}
			else
			{
				count += _GetKLevel(root->_left, level - 1);
				count += _GetKLevel(root->_right, level - 1);
			}
			return count;
		}
};