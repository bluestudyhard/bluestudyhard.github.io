#include <iostream>
using namespace std;
template <typename T>
class list_queue
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *front;
    Node *rear;
    int len;

public:
    list_queue()
    {
        front = rear = nullptr; // ��ʼ��Ϊ��
        len = 0;
    }
    ~list_queue()
    {
        Node *p = front;
    }
    void push(T e)
    {
        Node *newnode = new Node;
        newnode->data = e;
        newnode->next = nullptr;
        if (rear != nullptr) // ���rear��Ϊ��
        {
            rear->next = newnode;
        }
        else
        {
            front = newnode; // ���пյ�ʱ���ö��׵��ڵ�һ��Ԫ�أ���βҲ�ǣ�Ȼ����׾Ͳ����ˡ�
        }
        rear = newnode;
        len++;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "pop��ghost,���п�" << endl;
            return;
        }
        Node *p = front;     //һ���ڵ���ڵ�ǰ�Ķ���
        front = front->next; // ����ָ����һ��
        delete p;
        len--;
    }
    void show_list()
    {
        if (isempty())
        {
            cout << "empty queue" << endl;
            return;
        }
        Node *p = front;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    bool isempty()
    {
        if (front == nullptr || rear == nullptr || len == 0)
            return true;
        return false;
    }
    T get_front()
    {
        cout << "����Ԫ��Ϊ: " << front->data << endl;
        return front->data;
    }
    T get_back()
    {
        cout << "��βԪ��Ϊ: " << rear->data << endl;
        return rear->data;
    }
    void clear()
    {
        while (front != nullptr)
        {
            Node *p = front;
            front = front->next;
            len--;
            delete p;
        }
    }
};