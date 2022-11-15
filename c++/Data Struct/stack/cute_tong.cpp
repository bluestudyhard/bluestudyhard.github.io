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
	Linkstack();			 //�޲ι��캯��
	Linkstack(T a[], int L); //�������Ĺ��캯��
	void push(T e);			 //��ջ
	void pop();				 //��ջ
	void top_e();			 //ȡջ��Ԫ��
	void empty();			 //�ж�ջ��Ԫ���Ƿ�Ϊ��
	void printf_elem();
};
/*
�޲ι��캯��������ʼ��һ���յ���ջ
*/
template <typename T>
Linkstack<T>::Linkstack()
{
	top = nullptr;
}
/*
���ι��캯����������ֵ
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
��ջ��������һ���µĽڵ�,��Ҫ�����ֵe��ֵ������ڵ��data��(newnode->Data = e),
p->next = s���½ڵ����ջ����top = newnode�޸�ջ����ָ��
*/
template <typename T>
void Linkstack<T>::push(T e)
{
	Node<T> *newnode = new Node<T>;
	newnode->Data = e;
	newnode->next = top;
	top = newnode;
	length++;
	cout << "Ԫ�أ�" << e << " ����ջ" << endl;
}
/*
��ջ
*/
template <typename T>
void Linkstack<T>::pop()
{
	if (top == nullptr)
	{
		cout << "����" << endl;
		exit(1);
	}
	Node<T> *p = new Node<T>;
	cout << "��ջ��Ԫ�أ�" << top->Data << endl;
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
		cout << "����ջΪ��" << endl;
	}
	cout << "����ջ��Ԫ�����������";
	
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
