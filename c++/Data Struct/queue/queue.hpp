#include <iostream>
using namespace std;
template <typename T>
class deque
{
private:
    int front;
    int rear;
    int maxsize;
    T *arr;

public:
    deaque(int size = 10)
    {
        front = 0;
        rear = 0;
        maxsize = size + 1;
        arr = new T[maxsize];
    }
    T back()
    {
        if (empty())
        {
            cout << "EMPTY!" << endl;
            return NULL;
        }
        return arr[rear];
    }
    void push(T e)
    {
        arr[++rear] = e;
    }
    void push_front(T e)
    {
        for (int i = 0; i < size(); i++)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = e;
        front++;
    }
    void back()
    {
        return arr[rear];
    }
    int size()
    {
        return front + rear;
    }
    bool empty();
    void pop()
    {
        rear--;
    }
};