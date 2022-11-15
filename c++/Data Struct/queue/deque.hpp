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
        arr = new T[len]; // ��ͨ���캯������һ��5�Ŀռ�
        front = rear = 0;
    }
    dequeue(T *a, int size)
    {
        arr = new T[MAXSIZE]; // ��ʼ��һ��16�ռ�
        if (size > MAXSIZE)
            reserve(MAXSIZE * 2 + 1);
        for (int i = 0; i < size; i++)
        {
            arr[i] = a[i];
        }
        front = 0;
        rear = size - 1; // ��βΪ��ʼ������ĳ���
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
        cout << "����Ԫ��Ϊ" << endl;
        cout << arr[front] << endl;
        return arr[front];
    }
    T get_rear()
    {
        cout << "��βԪ��Ϊ" << endl;
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
                arr[i] = temp[i]; // ��֮ǰ�����ݴ����
            }
            delete temp;
        }
    }
    bool isempty()
    {
        if (front == rear && front == 0 || front == 0 && rear == 0)
        {
            cout << "����Ϊ��" << endl;
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
            cout << "ջ���ˣ���������" << endl;
            return true;
        }
        else
        {
            cout << "û����" << endl;
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
            cout << "����Ϊ��" << endl;
            return;
        }
        cout << "���е�Ԫ��Ϊ:" << endl;
        for (int i = front; i < len; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
