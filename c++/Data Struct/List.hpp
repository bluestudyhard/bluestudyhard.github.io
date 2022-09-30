#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    class Node
    {
        T data;     //当前结点的值
        Node *next; //为什么是Node类型呢，因为next指向的是下一个链表域，其中也包含着next，和data，所以是个类指针。可以理解为他指向的是下一个抽屉。
    };
    Node *head; //头结点 头结点不算节点，只是方便理解，他是空的。*next 才是第一个元素，可以理解为数轴的0
    Node *tail; //尾结点
    int length; //链表长度

public:
    List()
    {
        head = tail = new Node();
        head->data = 0;
        head->next = nullptr;
    }
    ~List()
    {
        this->clear();
        delete head, tail;
    }
    int get_len()
    {
        return length;
    }
    void Create_list(int size)
    {
        Node *pnew, ptemp;
        ptemp = head;
        if (size < 0)
        {
            exit(-1);
        }
        for (int i = 0; i < size; i++)
        {
            pnew = new Node;
            cin >> pnew->data;
            pnew->next = nullptr; //下一节点设为空指针。
            ptemp->next = pnew;   // 当前节点的下一个设为新的节点。
            ptemp = pnew;         // 当前节点设为新节点
        }
    }

    Node *find(int index) //返回第index个结点。
    {
        int i = 0;
        Node *p = this->head; //结点指向头结点
        while (p and i++ < index)
            p = p->next; //将next中的值赋 给p
        return p;
    }
    int find_ele(T e)
    {
        int i = 0;
        Node *p = this->head; //从头开始
        while (p->next != nullptr)
        {
            if (p->data == e)
                return i;
            else
                p = p->next;
            i++;
        }
    }
    void insert_index(T e, int index)
    {
        if (index < 0 || index > length)
        {
            cout << "insert error!" << endl;
        }
        Node *ptemp = new Node; //创建一个新的节点
        ptemp->data = data;     //
        Node *p = head;
        int i = 1;
        while (n > 1)
        {
            p = p->next;
            i++;
        }
        ptemp->next = p->next;
        p->next = ptemp;
    }
};