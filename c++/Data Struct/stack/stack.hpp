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
    void resize(int newsize) //�����ж�������Ҫ���ȥ�����ݣ��᲻�ᳬ��ԭ�����ǿ��ٵĿռ�
    {
        if (newsize < thecapacity)
            return;
        else if (newsize > thecapacity) //��������ˣ��͵���reserve���������ռ����ݡ�
        {
            reserve(newsize * 2 + 1); //ʹԭ���Ŀռ�����2������+1�Ǳ�ʾ��û�ж����ʼ�ռ�ʱ��0sizeʱ����֤��1��Ԫ�صĿռ䡣
        }
        len = newsize; //�������Ժ������������ĳ��ȱ�����ڵ����鳤�ȡ�
    }
    void reserve(int newcapacity)
    {
        if (newcapacity < thecapacity)
            return;
        T *temp = arr;            //����һ����������ʱ�洢����ԭ�������ݡ�
        arr = new T[newcapacity]; //����

        for (int i = 1; i <= len; i++)
        {
            arr[i] = temp[i]; //�ٰ����ݴ���µĿռ�
        }
        delete temp; //ɾ����ʱ�������顣
    }
    void push(T e)
    {
        cout << "ѹ��Ԫ��:" << e << endl;
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
            cout << "ջ�գ�pop������" << endl;
        }
        len--;
    }
    T top()
    {
        cout << "ջ��Ԫ��Ϊ" << arr[len] << endl;
        return arr[len];
    }
    bool isempty()
    {
        if (len > 0)
        {
            cout << "ջ��Ϊ��" << endl;
            return false;
        }
        else
        {
            cout << "ջ��" << endl;
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
            cout << "ջ��" << endl;
        }
        cout << "ջ��Ԫ�شӶ���ʼ����Ϊ" << endl;
        for (int i = len; i >= 1; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};