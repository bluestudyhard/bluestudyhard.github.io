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
        front = rear = nullptr; // 初始化为空
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
        if (rear != nullptr) // 如果rear不为空
        {
            rear->next = newnode;
        }
        else
        {
            front = newnode; // 队列空的时候让队首等于第一个元素，队尾也是，然后队首就不动了。
        }
        rear = newnode;
        len++;
    }
    void pop()
    {
        if (isempty())
        {
            cout << "pop个ghost,队列空" << endl;
            return;
        }
        Node *p = front;     //一个节点等于当前的队首
        front = front->next; // 队首指向下一个
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
        cout << "队首元素为: " << front->data << endl;
        return front->data;
    }
    T get_back()
    {
        cout << "队尾元素为: " << rear->data << endl;
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