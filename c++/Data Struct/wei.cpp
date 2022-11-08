#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
	T data;			//����������
	Node<T> *prior; //����ǰ��
	Node<T> *next;	//���ָ��
};
template <class T>
class DList
{				   // Ӧ�õ���Node ���ڵ�
	Node<T> *head; //����ͷ���
	Node<T> *tail; // �����½�һ��β�����������
	int len;	   // ���Զ���һ�����ȣ����������Ժ���㳤�ȷ���
public:
	DList();					//�޲ι��캯��
	DList(T a[], int n);		//�вι��캯��
	~DList();					//��������
	void Insert(int i, T x);	//��ֵΪx���½����뵽˫�����С�
	void Delete(int i);			//ɾ��ָ����i��㡣
	void change(int i, T item); //�޸ĵ�i����㣬itemΪ���޸ĵ�ֵ��
	int Locate(T item);			//�غ�̷���ֵ����Ԫ�أ�����������ֵΪitem��Ԫ�����
	bool isEmpty();				//�ж������Ƿ�Ϊ��
	void print1();				//˳���������
	void print2();				//�����������
	int Length();				//����˫����ĳ��ȡ�
};
//�޲ι��캯��
template <class T>
DList<T>::DList()
{ // ѭ������ĳ�ʼ����ͷ��β�ڵ�ָ��������β����������
	head = new Node<T>;
	tail = new Node<T>;
	head->prior = tail;
	tail->next = head;
	len = 0;
}
//�вι��캯��
template <class T>
DList<T>::DList(T a[], int n)
{	head = new Node<T>;//����ͷ���
	tail = new Node<T>;

	Node<T>
	for (int i = 0; i < n; i++)
	{
		p->data = a[i]; // pָ���½��
		s->next = p;
		p->prior = s;
		s = p; // �ڵ����
	}
	// �����s��β���
	tail = s; //
	len = n;  // �����ȵ���n
	tail->next = head;
	head->prior = tail;
}
//�����������ͷ����д洢
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
	cout << "�����ɹ�" << endl;
}
//���뺯������ֵΪx���½����뵽˫�����У���巨����
template <class T>
void DList<T>::Insert(int i, T x)
{
	Node<T> *p = head;
	if (i <= 0 || i > Length())
	{
		cout << "����λ�ò��Ϸ�" << endl;
		exit(1);
	}
	else //����λ��λ��������֮��
	{
		for (int j = 0; j < i - 1; j++)
		{
			p = p->next; //��ʱָ��pָ��i-1�����
		}
		Node<T> *s = new Node<T>;
		s->data = x;
		s->prior = p;
		s->next = p->next;
		p->next->prior = s;
		p->next = s;
		//����ѭ��˫����Ĳ���
		cout << "����ɹ�" << endl;
	}
}
//ɾ��������ɾ��ָ����i��㡣
template <class T>
void DList<T>::Delete(int i)
{
	Node<T> *p = head;
	if (i <= 0 || i > Length())
	{
		cout << "�Ƿ�ɾ��" << endl;
		exit(1);
	}
	// �����ʵ���Ե����ȵ� ������Ҫɾ����iλ��
	else
	{
		for (int j = 0; j < i; j++)
		{
			p = p->next;
		}
		p->next->prior = p->prior;
		p->prior->next = p->next;
		delete p;
		cout << "ɾ���ɹ�" << endl;
	}
}
//�޸ĺ������޸ĵ�i����㣬itemΪ���޸ĵ�ֵ��
template <class T>
void DList<T>::change(int i, T item)
{
	if (i < 0 || i > Length())
	{
		cout << "�޸�λ�÷Ƿ�" << endl;
		exit(1);
	}
	Node<T> *p = head;
	for (int j = 0; j < i; j++)
	{
		p = p->next;
	}
	p->data = item;
}
/*���Һ���:�غ�̷���ֵ���ҽ������ҵ�ֵitem��˫�����ÿ���ڵ�Ԫ��
���ν��бȽ�,�ɹ��򷵻ص�һ����Ԫ�ص���ţ����򷵻�ֵ0����������ʧ�ܡ�*/
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
//�пպ������ж������Ƿ�Ϊ�ա�
template <class T>
bool DList<T>::isEmpty()
{ // ���س����Ƿ�Ϊ0�ͺ���
	return len == 0;
}
//˳���������:��ͷ��㿪ʼ�������
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
//�����������:��β��㿪ʼ�������
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
//����˫����ĳ���:���һ��ָ�룬��˫�����һ����㿪ʼ���ɨ�裬ֱ���ص�ͷ��������
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
	//����
	// cout << "��������Ҫ�����λ�ã�";
	// cin >> b;
	// cout << "��������Ҫ�����ֵ��";
	// cin >> c;
	// d.Insert(b, c);
	d.print1();
	d.Length();
}
