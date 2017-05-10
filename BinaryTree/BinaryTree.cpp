// BinaryTree.cpp : 定义控制台应用程序的入口点。
//
#include"iostream"
#include"BinaryTree.h"
using namespace std;
void testBinaryTree()
{
	int array[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	size_t sz = sizeof(array) / sizeof(array[0]);
	BinaryTree<int> bt(array, sz, '#');

	bt.PrevOrder();   //1 2 3 4 5 6 7 8  
	bt.InOrder();     //2 3 1 5 6 7 4 8  
	bt.PostOrder();   //3 2 7 6 5 8 4 1  
	bt.LevelOrder();  //1 2 4 3 5 8 6 7   
	cout << bt.Size() << endl;    //8  
	cout << bt.Depth() << endl;   //5  

	BinaryTree<int> bt1(bt);
	bt1.PrevOrder();
	bt1.InOrder();
	bt1.PostOrder();
	bt1.LevelOrder();
	cout << bt1.Size() << endl;    //8  
	cout << bt1.Depth() << endl;   //5  

	BinaryTree<int> bt2;
	bt2 = bt;
	bt2.PrevOrder();
	bt2.InOrder();
	bt2.PostOrder();
	bt2.LevelOrder();
	cout << bt2.Size() << endl;     //8  
	cout << bt2.Depth() << endl;    //5  
	cout << bt2.LeafSize() << endl; //3    
	//该树的每一层共有多少个结点  
	cout << bt2.GetKLevel(1) << endl;;  //1  
	cout << bt2.GetKLevel(2) << endl;;  //2  
	cout << bt2.GetKLevel(3) << endl;;  //3  
	cout << bt2.GetKLevel(4) << endl;;  //1  
	cout << bt2.GetKLevel(5) << endl;;  //1  
}
int main()
{
	testBinaryTree();
	system("pause");
	return 0;
}