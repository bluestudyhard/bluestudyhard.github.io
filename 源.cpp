#include <iostream>
using namespace std;
const int MAXSIZE = 100;
template <typename T>
class Sqlist
{
private:
	T *elem;	//���ڴ������Ԫ�ص�����
	int length; //˳�����Ԫ�صĸ���
public:
	void lnitlist_Sq(Sqlist &L);
	Sqlist();						 //˳���L�ĳ�ʼ��
	Sqlist(int n, T a[]);			 //˳���Ĺ��캯����������ֵ
	void Destroy_Sq(Sqlist L);		 //�������Ա�L
	void Clean_Sq();				 //���һ�����Ա�
	void Length_Sq();				 //�����Ա�ĳ���length
	bool Empty_Sq(Sqlist L);		 //�ж�һ�����Ա��Ƿ�Ϊ��
	void Get_elem(int i);			 //����˳���L�е�i��Ԫ��(�±�Ϊi-1)��ֵ
	void Locate_elem(T item);		 //����˳���L��ֵΪitem��Ԫ�����ڵ�λ��
	void Delete_elem(int i);		 //ɾ����i��Ԫ��
	void Insert_elem(int i, T item); //����һ��Ԫ��item����i��λ��
	void Printf_elem();				 //��ӡ���Ա��Ԫ��
};
//��ʼ��һ���յ����Ա�L
template <typename T>
// ������void ������return
void Sqlist<T>::lnitlist_Sq(Sqlist &L)
{							 //����һ���յ�˳���L
	L.elem = new T[MAXSIZE]; //Ϊ˳���L����ռ�
	if (!L.elem)
	{
		cout << "�洢����ʧ�ܣ�������ֹ";
		exit(1);
	}
	L.length = 0; //�ձ���Ϊ0
	cout << "�洢����ɹ�";
}
//���캯����������ֵ
template <typename T>
Sqlist<T>::Sqlist(int n, T a[])
{ //����Ϊn,Ԫ��Ϊa[]�е�Ԫ���е�˳���
	cout << "����������˳���ĳ��Ⱥͱ���Ԫ�أ�";
	if (n < 0 || n > MAXSIZE)
	{
		cout << "�����Ƿ�";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		elem[i] = a[i];
		length = n;
	}
}
//�������Ա�L
template <typename T>
void Sqlist<T>::Destroy_Sq(Sqlist L)
{
	if (L.elem)
	{ //ǰ����L�Ѿ�����
		cout << "�ռ����ͷ�";
		delete elem; //�ͷſռ�
	}
}
//���һ�����Ա�
template <typename T>
void Sqlist<T>::Clean_Sq()
{
	cout << "���Ա�������";
	length = 0; //�����Ա�ĳ�����Ϊ0
}
//��һ�����Ա�ĳ���
template <typename T>
void Sqlist<T>::Length_Sq()
{
	cout << "���Ա�ĳ���:" << length;
}
//��һ�����Ա��Ƿ�Ϊ�ձ�
template <typename T>
bool Sqlist<T>::Empty_Sq(Sqlist L)
{
	if (length < 0 || L.length > MAXSIZE)
	{
		cout << "˳���Ƿ�";
		exit(1);
	}
	else if (length == 0)
	{ //Ϊ�ձ���true ,��Ϊ�ձ���false
		return true;
	}
	else
	{
		return false;
	}
}
//����˳���L�е�i��Ԫ��(�±�Ϊi-1)��ֵ
template <typename T>
void Sqlist<T>::Get_elem(int i)
{
	if (i < 1 || i > length)
	{
		cout << "����λ�÷Ƿ�";
		exit(1);
	}
	cout << "��i��Ԫ�ص�ֵ��" + elem[i - 1]; //��i��Ԫ�ص��±�Ϊi-1
}
//����˳���L��ֵΪitem��Ԫ�����ڵ�λ��
template <typename T>
void Sqlist<T>::Locate_elem(T item)
{
	for (int i = 0; i < length; i++)
	{
		if (elem[i] == item)
		{
			cout << "��Ԫ�����ڵ�λ�ã�" + i + 1; //�±�Ϊi��Ԫ�����ڵĴ洢��ԪΪi+1
		}
	}
}
//ɾ����i��Ԫ��
template <typename T>
void Sqlist<T>::Delete_elem(int i)
{
	if (i < 1 || i > length)
	{
		cout << "�����Ƿ�";
		exit(1);
	}
	for (int j = i; j < L.length; j++)
	{
		L.elem[j - 1] = L.elem[j];
		L.length--; //����-1
	}
	cout << "��Ԫ����ɾ��";
}
//����һ��Ԫ��item����i��λ��
template <typename T>
void Sqlist<T>::Insert_elem(int i, T item)
{
	if (i < 1 || i > length + 1)
	{
		cout << "����Ƿ�";
		exit(1);
	}
	if (L.length == MAXSIZE)
	{
		cout << "�洢�ռ�����";
		exit(1);
	}
	for (int j = length - 1; j >= i - 1; j--)
	{
		elem[j + 1] == elem[j]; //����Ԫ��֮���Ԫ�غ���
		elem[i - 1] = item;
		L.length++; //����+1
	}
	cout << "��Ԫ���Ѳ���";
}
template <typename T>
void Sqlist<T>::Printf_elem()
{
	for (int i = 0; i < length; i++)
	{
		cout << elem[i] << endl;
	}
}
int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int l = 5;
	Sqlist s(5, a);
	s.Insert_elem(2, 3);
	s.Printf_elem();
}