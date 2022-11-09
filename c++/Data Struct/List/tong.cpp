#include <iostream>
using namespace std;
template <typename T>
struct Dnode
{
	T Data;
	Dnode<T> *Llink;
	Dnode<T> *Rlink;
};
template <typename T>
class DuLinklist
{
private:
	Dnode<T> *head;
	Dnode<T> *tail;

public:
	DuLinklist(); //无参构造函数
	DuLinklist(T data[], int L);
	~DuLinklist(); //析构函数
	void pre_printf();
	void aft_printf();
	int get_i(int item);		  //查找第i个元素的值
	void Locate_item(T item);	  //查找值为item的元素所在的位置序号
	void Insert(int i, T item);	  //插入值为item的元素到第i个位置
	void Delete_i(int i, T item); //删除第i个元素
};
/*
无参构造函数
创建一个带头结点的空循环双链表
*/
template <typename T>
DuLinklist<T>::DuLinklist()
{
	head = new Dnode<T>; //为头节点分配储存空间
	tail = new Dnode<T>;
	if (head == NULL) // '=='
	{
		cout << "存储分配错误" << endl;
		exit(1);
	}
	head->Rlink = tail; //双循环链表结构特点
	tail->Llink = head;
}
/*
带参数的构造函数
*/
template <typename T>
DuLinklist<T>::DuLinklist(T data[], int L)
{
	head = new Dnode<T>;
	tail = new Dnode<T>;
	for (int i = 0; i < L; i++)
	{
		if (i == 0)
		{
			tail->Data = data[i];
			tail->Llink = head;
			tail->Rlink = head;
			head->Rlink = tail;
			head->Llink = tail;
			continue;
		}
		Dnode<T> *newnode = new Dnode<T>;
		newnode->Data = data[i];
		newnode->Llink = tail;
		tail->Rlink = newnode;
		tail = newnode;
	}
	head->Llink = tail;
	tail->Rlink = head;
}
/*
析构函数——释放
*/
template <typename T>
DuLinklist<T>::~DuLinklist()
{
	delete head;	
	delete tail;
	cout << "该存储空间已释放" << endl;
}
/*
打印链表顺序输出
*/
template <typename T>

void DuLinklist<T>::pre_printf()
{
	Dnode<T> *output = head->Rlink;
	cout << "该链表的正序输出元素：" << endl;
	while (output != head)
	{
		cout << output->Data << " ";
		output = output->Rlink;
	}
	cout << endl;
}
/*
打印链表逆序输出
*/
template <typename T>
void DuLinklist<T>::aft_printf()
{
	Dnode<T> *output = tail;
	cout << "该链表逆序输出的元素：" << endl;
	while (output != head)
	{
		cout << output->Data << " ";
		output = output->Llink;
	}
	cout << endl;
}
/*
查找值为item的元素所在的地址
*/
template <typename T>
void DuLinklist<T>::Locate_item(T item)
{
	Dnode<T> *p = new Dnode<T>;
	p = head->Rlink;
	while (p != tail && p->Data != item)
	{
		p = p->Rlink;
	}
	cout << "该元素的所在的地址：" << p << endl;
}

/*
查找值为item的元素所在的位置序号
*/
template <typename T>
int DuLinklist<T>::get_i(int item)
{
	Dnode<T> *p = new Dnode<T>;
	p = head->Rlink;
	int j = 1;
	while (p != tail && p->Data != item)
	{
		p = p->Rlink;
		j++;
	}
	cout << "该元素的所在的位置序号：" << j << endl;
	return j;
}
/*
插入元素数值为item到位置序号为i的位置
*/
template <typename T>
void DuLinklist<T>::Insert(int i, T item)
{	
	Dnode<T> *p = new Dnode<T>;
	p = head->Rlink;
	int j = 1;
	while (p != tail && j != i)
	{ //让p指向第i个位置的节点
		p = p->Rlink;
		j++;
	}
	Dnode<T> *newnode = new Dnode<T>;
	newnode->Data = item;
	newnode->Llink = p->Llink;
	p->Llink->Rlink = newnode;
	newnode->Rlink = p;
	p->Llink = newnode;
	cout << "该节点已经插入" << endl;
}
/*
删除位置序号为i的元素
*/
template <typename T>
void DuLinklist<T>::Delete_i(int i, T item)
{
	Dnode<T> *p = new Dnode<T>;
	p = head->Rlink;
	int j = 1;
	while (p != tail && j != i)
	{ //让p指向第i个位置的节点
		p = p->Rlink;
		j++;
	}
	Dnode<T> *newnode = new Dnode<T>;
	newnode->Data = item;
	p->Llink->Rlink = p->Rlink;
	p->Rlink->Llink = p->Llink;
	delete p;
	cout << "元素值为" << item << "的节点已删除" << endl;
}

int main()
{
	int a[4] = {2, 4, 3, 8};
	DuLinklist<int> s(a, 4);
	s.aft_printf();	  //后续输出
	s.pre_printf();	  //前序输出
	s.Locate_item(2); //查找值为2的元素所在的地址
	s.get_i(2);		  //查找值为2的元素所在的位置序号
	s.Insert(4, 100);	  //插入值为6的元素到位置序号为2里
	s.pre_printf();	  //前序输出查看调试结果
	s.Delete_i(1, 2); //删除位置序号为1，元素值为2的元素
	s.pre_printf();	  //前序输出查看调试结果
}