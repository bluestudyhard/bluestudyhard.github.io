#include <iostream>
using namespace std;
const int MAXSIZE = 100;
template <typename T>
class Sqlist
{
private:
	T *elem;	//用于存放数据元素的数组
	int length; //顺序表中元素的个数
public:
	void lnitlist_Sq(Sqlist &L);
	Sqlist();						 //顺序表L的初始化
	Sqlist(int n, T a[]);			 //顺序表的构造函数——赋初值
	void Destroy_Sq(Sqlist L);		 //销毁线性表L
	void Clean_Sq();				 //清空一个线性表
	void Length_Sq();				 //求线性表的长度length
	bool Empty_Sq(Sqlist L);		 //判断一个线性表是否为空
	void Get_elem(int i);			 //查找顺序表L中第i个元素(下标为i-1)的值
	void Locate_elem(T item);		 //查找顺序表L中值为item的元素所在的位置
	void Delete_elem(int i);		 //删除第i个元素
	void Insert_elem(int i, T item); //插入一个元素item到第i个位置
	void Printf_elem();				 //打印线性表的元素
};
//初始化一个空的线性表L
template <typename T>
// 这里是void 不可以return
void Sqlist<T>::lnitlist_Sq(Sqlist &L)
{							 //构造一个空的顺序表L
	L.elem = new T[MAXSIZE]; //为顺序表L分配空间
	if (!L.elem)
	{
		cout << "存储分配失败，程序终止";
		exit(1);
	}
	L.length = 0; //空表长度为0
	cout << "存储分配成功";
}
//构造函数——赋初值
template <typename T>
Sqlist<T>::Sqlist(int n, T a[])
{ //长度为n,元素为a[]中的元素中的顺序表
	cout << "请依次输入顺序表的长度和表中元素：";
	if (n < 0 || n > MAXSIZE)
	{
		cout << "参数非法";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		elem[i] = a[i];
		length = n;
	}
}
//销毁线性表L
template <typename T>
void Sqlist<T>::Destroy_Sq(Sqlist L)
{
	if (L.elem)
	{ //前提是L已经存在
		cout << "空间已释放";
		delete elem; //释放空间
	}
}
//清空一个线性表
template <typename T>
void Sqlist<T>::Clean_Sq()
{
	cout << "线性表已重置";
	length = 0; //将线性表的长度置为0
}
//求一个线性表的长度
template <typename T>
void Sqlist<T>::Length_Sq()
{
	cout << "线性表的长度:" << length;
}
//求一个线性表是否为空表
template <typename T>
bool Sqlist<T>::Empty_Sq(Sqlist L)
{
	if (length < 0 || L.length > MAXSIZE)
	{
		cout << "顺序表非法";
		exit(1);
	}
	else if (length == 0)
	{ //为空表返回true ,不为空表返回false
		return true;
	}
	else
	{
		return false;
	}
}
//查找顺序表L中第i个元素(下标为i-1)的值
template <typename T>
void Sqlist<T>::Get_elem(int i)
{
	if (i < 1 || i > length)
	{
		cout << "查找位置非法";
		exit(1);
	}
	cout << "第i个元素的值：" + elem[i - 1]; //第i个元素的下标为i-1
}
//查找顺序表L中值为item的元素所在的位置
template <typename T>
void Sqlist<T>::Locate_elem(T item)
{
	for (int i = 0; i < length; i++)
	{
		if (elem[i] == item)
		{
			cout << "该元素所在的位置：" + i + 1; //下标为i的元素所在的存储单元为i+1
		}
	}
}
//删除第i个元素
template <typename T>
void Sqlist<T>::Delete_elem(int i)
{
	if (i < 1 || i > length)
	{
		cout << "参数非法";
		exit(1);
	}
	for (int j = i; j < L.length; j++)
	{
		L.elem[j - 1] = L.elem[j];
		L.length--; //长度-1
	}
	cout << "该元素已删除";
}
//插入一个元素item到第i个位置
template <typename T>
void Sqlist<T>::Insert_elem(int i, T item)
{
	if (i < 1 || i > length + 1)
	{
		cout << "插入非法";
		exit(1);
	}
	if (L.length == MAXSIZE)
	{
		cout << "存储空间已满";
		exit(1);
	}
	for (int j = length - 1; j >= i - 1; j--)
	{
		elem[j + 1] == elem[j]; //插入元素之后的元素后移
		elem[i - 1] = item;
		L.length++; //长度+1
	}
	cout << "该元素已插入";
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