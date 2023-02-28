#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:
    T *arr;
    int capacity;
    int thesize;

public:
    Vector(int thesize = 0) : thesize(thesize), capacity(capacity + thesize){};
    void create_arrary(T *arr, int len);
    void resize()
    {
        if (thesize < capacity)
            return;
        reverse(thesize * 2 + 1);
    }
    void reverse(int newcapacity)
    {
        if (newcapacity < capacity)
            return;
        T *temp = arr;
        arr = new T[newcapacity];
        for (int i = 1; i <= newcapacity; i++)
        {
            arr[i] = temp[i];
        }
        delete temp;
    }

    void insert(T e, int index)
    {
        for (int i = index; i < thesize; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[index] = e;
        thesize++;
        /*
            for(int i = thesize+1;i>=index;i--)
            {
                arr[i] = arr[i-1];
            }
        */
    }
    void remove(int index)
    {
        for (int i = index; i <= thesize; i++)
        {
            arr[i] = arr[i + 1];
        }
        --thesize;
    }
    bool find_e(T e);
    void push_back(T e)
    {
        resize();

        arr[++thesize] = e;
    }
    void pop();
    void display();
    T &operator[](int i)
    {
        return arr[i];
    }
};

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;
    int len;

public:
    List()
    {
        head = new Node;
        head->data = 0;
        head->next = nullptr;
    }
    ~List()
    {
        delete head;
    }
    void create_list(T *arr, int len)
    {
        Node *p = head;
        for (int i = 1; i <= len; i++)
        {
            Node *pnew = new Node;
            pnew->data = arr[i];
            p->next = pnew;
            p = pnew;
        }
        p->next = nullptr;
    }
    void insert(T e, int index)
    {
        Node *p = head;
        for (int i = 1; i <= index; i++)
        {
            p = p->next;
        }
        Node *temp = new Node;
        temp->data = e;
        temp->next = p->next;
        p->next = temp;
        len++;
    }
    void remove(int index)
    {
        Node *p = head;

        Node *temp = find(index);
        while (p->next != temp)
        {
            p = p->next;
        }
        p->next = temp->next;
        temp = nullptr;
        delete temp;
        len--;
    }
    bool find_e(T e)
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            if (p->data == e)
                return true;
            p = p->next;
        }
        return false;
    }
    Node *find(T e)
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            if (p->data == e)
                return;
            p = p->next;
        }
        return nullptr;
    }
    void show_list()
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    void reverse()
    {
        int flag = 1;
        Node *p = head->next;
        while (p != nullptr)
        {

            Node *temp1 = p->next;       // p的下一个
            Node *temp2 = p->next->next; // p的下下一个节点
            temp2->next = p;
        }
        
    }
};
