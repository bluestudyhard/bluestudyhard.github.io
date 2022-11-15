#include <iostream>
using namespace std;
template <typename T>
class dequeue
{
private:
    int front;
    int rear;
    int len;
    T *arr;
    int MAXSIZE = 16;

public:
    dequeue()
    {
        len = 5;
        arr = new T[len]; // 普通构造函数开辟一个5的空间
        front = rear = 0;
    }
    dequeue(T *a, int size)
    {
        arr = new T[MAXSIZE]; // 初始化一个16空间
        if (size > MAXSIZE)
            reserve(MAXSIZE * 2 + 1);
        for (int i = 0; i < size; i++)
        {
            arr[i] = a[i];
        }
        front = 0;
        rear = size - 1; // 队尾为初始化数组的长度
        len = size;
    }
    ~dequeue()
    {
        delete arr;
    }
    void push(T e)
    {
        arr[++rear] = e;
        len++;
    }
    void pop()
    {
        front++;
    }
    T get_front()
    {
        cout << "队首元素为" << endl;
        cout << arr[front] << endl;
        return arr[front];
    }
    T get_rear()
    {
        cout << "队尾元素为" << endl;
        cout << arr[rear] << endl;
        return arr[rear];
    }
    void reserve(int thecapacity)
    {
        if (len < thecapacity)
            return;
        else
        {
            T *temp = arr;
            arr = new T[thecapacity];
            for (int i = 0; i < len; i++)
            {
                arr[i] = temp[i]; // 将之前的数据存回来
            }
            delete temp;
        }
    }
    bool isempty()
    {
        if (front == rear && front == 0 || front == 0 && rear == 0)
        {
            cout << "队列为空" << endl;
            return true;
        }
        else
        {

            return false;
        }
    }
    bool isfull()
    {
        if (front == rear && front > 0 || len == MAXSIZE)
        {
            cout << "栈满了，动不了了" << endl;
            return true;
        }
        else
        {
            cout << "没满呢" << endl;
            return false;
        }
    }
    void clear()
    {
        front = rear = 0;
        len = 0;
    }
    void show_queue()
    {
        if (isempty())
        {
            cout << "队列为空" << endl;
            return;
        }
        cout << "队列的元素为:" << endl;
        for (int i = front; i < len; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
