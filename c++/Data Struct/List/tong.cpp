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
	DuLinklist(); //�޲ι��캯��
	DuLinklist(T data[], int L);
	~DuLinklist(); //��������
	void pre_printf();
	void aft_printf();
	int get_i(int item);		  //���ҵ�i��Ԫ�ص�ֵ
	void Locate_item(T item);	  //����ֵΪitem��Ԫ�����ڵ�λ�����
	void Insert(int i, T item);	  //����ֵΪitem��Ԫ�ص���i��λ��
	void Delete_i(int i, T item); //ɾ����i��Ԫ��
};
/*
�޲ι��캯��
����һ����ͷ���Ŀ�ѭ��˫����
*/
template <typename T>
DuLinklist<T>::DuLinklist()
{
	head = new Dnode<T>; //Ϊͷ�ڵ���䴢��ռ�
	tail = new Dnode<T>;
	if (head == NULL) // '=='
	{
		cout << "�洢�������" << endl;
		exit(1);
	}
	head->Rlink = tail; //˫ѭ������ṹ�ص�
	tail->Llink = head;
}
/*
�������Ĺ��캯��
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
�������������ͷ�
*/
template <typename T>
DuLinklist<T>::~DuLinklist()
{
	delete head;	
	delete tail;
	cout << "�ô洢�ռ����ͷ�" << endl;
}
/*
��ӡ����˳�����
*/
template <typename T>

void DuLinklist<T>::pre_printf()
{
	Dnode<T> *output = head->Rlink;
	cout << "��������������Ԫ�أ�" << endl;
	while (output != head)
	{
		cout << output->Data << " ";
		output = output->Rlink;
	}
	cout << endl;
}
/*
��ӡ�����������
*/
template <typename T>
void DuLinklist<T>::aft_printf()
{
	Dnode<T> *output = tail;
	cout << "���������������Ԫ�أ�" << endl;
	while (output != head)
	{
		cout << output->Data << " ";
		output = output->Llink;
	}
	cout << endl;
}
/*
����ֵΪitem��Ԫ�����ڵĵ�ַ
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
	cout << "��Ԫ�ص����ڵĵ�ַ��" << p << endl;
}

/*
����ֵΪitem��Ԫ�����ڵ�λ�����
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
	cout << "��Ԫ�ص����ڵ�λ����ţ�" << j << endl;
	return j;
}
/*
����Ԫ����ֵΪitem��λ�����Ϊi��λ��
*/
template <typename T>
void DuLinklist<T>::Insert(int i, T item)
{	
	Dnode<T> *p = new Dnode<T>;
	p = head->Rlink;
	int j = 1;
	while (p != tail && j != i)
	{ //��pָ���i��λ�õĽڵ�
		p = p->Rlink;
		j++;
	}
	Dnode<T> *newnode = new Dnode<T>;
	newnode->Data = item;
	newnode->Llink = p->Llink;
	p->Llink->Rlink = newnode;
	newnode->Rlink = p;
	p->Llink = newnode;
	cout << "�ýڵ��Ѿ�����" << endl;
}
/*
ɾ��λ�����Ϊi��Ԫ��
*/
template <typename T>
void DuLinklist<T>::Delete_i(int i, T item)
{
	Dnode<T> *p = new Dnode<T>;
	p = head->Rlink;
	int j = 1;
	while (p != tail && j != i)
	{ //��pָ���i��λ�õĽڵ�
		p = p->Rlink;
		j++;
	}
	Dnode<T> *newnode = new Dnode<T>;
	newnode->Data = item;
	p->Llink->Rlink = p->Rlink;
	p->Rlink->Llink = p->Llink;
	delete p;
	cout << "Ԫ��ֵΪ" << item << "�Ľڵ���ɾ��" << endl;
}

int main()
{
	int a[4] = {2, 4, 3, 8};
	DuLinklist<int> s(a, 4);
	s.aft_printf();	  //�������
	s.pre_printf();	  //ǰ�����
	s.Locate_item(2); //����ֵΪ2��Ԫ�����ڵĵ�ַ
	s.get_i(2);		  //����ֵΪ2��Ԫ�����ڵ�λ�����
	s.Insert(4, 100);	  //����ֵΪ6��Ԫ�ص�λ�����Ϊ2��
	s.pre_printf();	  //ǰ������鿴���Խ��
	s.Delete_i(1, 2); //ɾ��λ�����Ϊ1��Ԫ��ֵΪ2��Ԫ��
	s.pre_printf();	  //ǰ������鿴���Խ��
}