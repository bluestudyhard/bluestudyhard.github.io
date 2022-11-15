#include <iostream>
using namespace std;
template <typename T>
struct Node
{
	T Data;
	Node<T> *next;
};
template <typename T>
class Linkstack
{
private:
	int length;
	Node<T> *top;

public:
	Linkstack();			 //无参构造函数
	Linkstack(T a[], int L); //带参数的构造函数
	void push(T e);			 //入栈
	void pop();				 //出栈
	void top_e();			 //取栈顶元素
	void empty();			 //判断栈顶元素是否为空
	void printf_elem();
};
/*
无参构造函数——初始化一个空的链栈
*/
template <typename T>
Linkstack<T>::Linkstack()
{
	top = nullptr;
}
/*
带参构造函数——赋初值
*/
template <typename T>
Linkstack<T>::Linkstack(T a[], int L)
{
	length = L;
	top = new Node<T>;
	top = nullptr;
	for (int i = 0; i < length; i++)
	{
		Node<T> *newnode = new Node<T>;
		newnode->Data = a[i];
		newnode->next = top;
		top = newnode;
	}
}
/*
入栈——生成一个新的节点,把要插入的值e赋值给这个节点的data域(newnode->Data = e),
p->next = s将新节点插入栈顶，top = newnode修改栈顶的指针
*/
template <typename T>
void Linkstack<T>::push(T e)
{
	Node<T> *newnode = new Node<T>;
	newnode->Data = e;
	newnode->next = top;
	top = newnode;
	length++;
	cout << "元素：" << e << " 已入栈" << endl;
}
/*
出栈
*/
template <typename T>
void Linkstack<T>::pop()
{
	if (top == nullptr)
	{
		cout << "下溢" << endl;
		exit(1);
	}
	Node<T> *p = new Node<T>;
	cout << "出栈的元素：" << top->Data << endl;
	p = top;
	top = top->next;
	length--;
	delete p;
}
template <typename T>
void Linkstack<T>::printf_elem()
{
	if (top == nullptr)
	{
		cout << "该链栈为空" << endl;
	}
	cout << "该链栈的元素逆序输出：";
	
	Node<T> *output = top;
	// for (int i = 1; i <= length; i++)
	// {
	// 	cout << output->Data << " ";
	// 	output = output->next;
	// }
	while (output != nullptr)
	{
		cout << output->Data << " ";
		output = output->next;
	}
	cout << endl;
}

int main()
{
	int a[5] = {2, 3, 6, 8, 1};
	Linkstack<int> s(a, 5);
	s.printf_elem();
	s.push(4);
	s.push(5);
	s.push(6);
	s.printf_elem();
	s.pop();
	s.pop();
	s.printf_elem();
}
