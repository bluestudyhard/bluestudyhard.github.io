#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
    T *arr;
    int len;
    int thecapacity;

public:
    Stack()
    {
        len = 0;
        arr = new T[len];
    }
    Stack(int length)
    {
        arr = new T[length];
        thecapacity = length;
        len = 0;
    }
    ~Stack()
    {
        delete arr;
    }
    void resize(int newsize) //用于判断我们想要存进去的数据，会不会超过原本我们开辟的空间
    {
        if (newsize < thecapacity)
            return;
        else if (newsize > thecapacity) //如果超过了，就调用reserve函数，给空间扩容。
        {
            reserve(newsize * 2 + 1); //使原本的空间扩容2倍并，+1是表示在没有定义初始空间时，0size时，保证有1个元素的空间。
        }
        len = newsize; //扩完容以后就让这个超过的长度变成现在的数组长度。
    }
    void reserve(int newcapacity)
    {
        if (newcapacity < thecapacity)
            return;
        T *temp = arr;            //先用一个数组来暂时存储我们原本的数据。
        arr = new T[newcapacity]; //扩容

        for (int i = 1; i <= len; i++)
        {
            arr[i] = temp[i]; //再把数据存回新的空间
        }
        delete temp; //删除临时交换数组。
    }
    void push(T e)
    {
        cout << "压入元素:" << e << endl;
        if (len == thecapacity)
        {
            reserve(thecapacity * 2 + 1);
        }
        arr[++len] = e;
    }
    void pop()
    {
        if (len < 0)
        {
            cout << "栈空，pop不动了" << endl;
        }
        len--;
    }
    T top()
    {
        cout << "栈顶元素为" << arr[len] << endl;
        return arr[len];
    }
    bool isempty()
    {
        if (len > 0)
        {
            cout << "栈不为空" << endl;
            return false;
        }
        else
        {
            cout << "栈空" << endl;
            return true;
        }
    }
    int size()
    {
        return len;
    }
    void clear()
    {
        delete arr;
    }
    void show_stack()
    {
        if (len == 0)
        {
            cout << "栈空" << endl;
        }
        cout << "栈的元素从顶开始依次为" << endl;
        for (int i = len; i >= 1; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};