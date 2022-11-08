#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
	T data;			//链表结点数据
	Node<T> *prior; //链表前驱
	Node<T> *next;	//后继指针
};
template <class T>
class DList
{				   // 应该调用Node 做节点
	Node<T> *head; //附加头结点
	Node<T> *tail; // 可以新建一个尾结点来操作。
	int len;	   // 可以定义一个长度，这样插入以后计算长度方便
public:
	DList();					//无参构造函数
	DList(T a[], int n);		//有参构造函数
	~DList();					//析构函数
	void Insert(int i, T x);	//将值为x的新结点插入到双链表中。
	void Delete(int i);			//删除指定的i结点。
	void change(int i, T item); //修改第i个结点，item为待修改的值。
	int Locate(T item);			//沿后继方向按值查找元素，返回链表中值为item的元素序号
	bool isEmpty();				//判断链表是否为空
	void print1();				//顺序输出链表
	void print2();				//逆序输出链表
	int Length();				//计算双链表的长度。
};
//无参构造函数
template <class T>
DList<T>::DList()
{ // 循环链表的初始化，头和尾节点指向自身，有尾结点会更好理解
	head = new Node<T>;
	tail = new Node<T>;
	head->prior = tail;
	tail->next = head;
	len = 0;
}
//有参构造函数
template <class T>
DList<T>::DList(T a[], int n)
{	head = new Node<T>;//生成头结点
	tail = new Node<T>;

	Node<T>
	for (int i = 0; i < n; i++)
	{
		p->data = a[i]; // p指向新结点
		s->next = p;
		p->prior = s;
		s = p; // 节点更替
	}
	// 到最后，s是尾结点
	tail = s; //
	len = n;  // 链表长度等于n
	tail->next = head;
	head->prior = tail;
}
//析构函数：释放所有存储
template <class T>
DList<T>::~DList()
{
	Node<T> *p = head->next;
	Node<T> *s = NULL;
	while (p != tail)
	{
		s = p;
		p = p->next;
		delete s;
	}
	delete p;
	delete head;
	delete tail;
	cout << "析构成功" << endl;
}
//插入函数：将值为x的新结点插入到双链表中（后插法）。
template <class T>
void DList<T>::Insert(int i, T x)
{
	Node<T> *p = head;
	if (i <= 0 || i > Length())
	{
		cout << "插入位置不合法" << endl;
		exit(1);
	}
	else //所插位置位于链表长度之内
	{
		for (int j = 0; j < i - 1; j++)
		{
			p = p->next; //此时指针p指向i-1个结点
		}
		Node<T> *s = new Node<T>;
		s->data = x;
		s->prior = p;
		s->next = p->next;
		p->next->prior = s;
		p->next = s;
		//进行循环双链表的插入
		cout << "插入成功" << endl;
	}
}
//删除函数：删除指定的i结点。
template <class T>
void DList<T>::Delete(int i)
{
	Node<T> *p = head;
	if (i <= 0 || i > Length())
	{
		cout << "非法删除" << endl;
		exit(1);
	}
	// 这个其实可以到长度的 遍历到要删除的i位置
	else
	{
		for (int j = 0; j < i; j++)
		{
			p = p->next;
		}
		p->next->prior = p->prior;
		p->prior->next = p->next;
		delete p;
		cout << "删除成功" << endl;
	}
}
//修改函数：修改第i个结点，item为待修改的值。
template <class T>
void DList<T>::change(int i, T item)
{
	if (i < 0 || i > Length())
	{
		cout << "修改位置非法" << endl;
		exit(1);
	}
	Node<T> *p = head;
	for (int j = 0; j < i; j++)
	{
		p = p->next;
	}
	p->data = item;
}
/*查找函数:沿后继方向按值查找将待查找的值item与双链表的每个节点元素
依次进行比较,成功则返回第一个该元素的序号；否则返回值0，表明查找失败。*/
template <class T>
int DList<T>::Locate(T item)
{
	Node<T> *p = head->next;
	int j = 1;
	while (p != head && p->data != item)
	{
		p = p->next;
		j++;
	}
	if (p != head)
		return j;
	else
		return 0;
}
//判空函数：判断链表是否为空。
template <class T>
bool DList<T>::isEmpty()
{ // 返回长度是否为0就好了
	return len == 0;
}
//顺序输出链表:从头结点开始依次输出
template <class T>
void DList<T>::print1()
{
	Node<T> *p = head->next;
	while (p != tail)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
//逆序输出链表:从尾结点开始依次输出
template <class T>
void DList<T>::print2()
{
	Node<T> *p = tail;
	while (p != head)
	{
		cout << p->data << " ";
		p = p->prior;
	}
}
//计算双链表的长度:设计一个指针，从双链表第一个结点开始向后扫描，直至回到头结点结束。
template <class T>
int DList<T>::Length()
{

	return len;
}
int main()
{
	int a[] = {12, 23, 34, 21, 13, 15};
	DList<int> d(a, 6);
	// int b, c;
	//插入
	// cout << "请输入你要插入的位置：";
	// cin >> b;
	// cout << "请输入你要插入的值：";
	// cin >> c;
	// d.Insert(b, c);
	d.print1();
	d.Length();
}
