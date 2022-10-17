#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
    T *arr;
    int len;
public:
    Stack()
    {
        len = 10;
        arr = new T[len];
    }
    ~Stack()
    {
        delete arr;
    }
    void push(T e)
    {
        int i = 0;
        arr[i++] = e;
    }
    void pop()
    {
        len--;
    }
    T top()
    {
        return arr[len];
    }
    bool isempty()
    {
        return size() == 0;
    }
    int size()
    {
        return len;
    }
    void clear()
    {
        delete arr;
    }
};