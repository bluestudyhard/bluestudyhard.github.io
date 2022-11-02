#include <iostream>
using namespace std;
template <typename T>
class double_list
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *last;
    };
    Node *head;
    Node *tail;
    int length;

public:
    double_list()
    {
        head = nullptr;
        tail = nullptr;
        head->data = 0;
    }
    ~double_list()
    {
        delete head;
        delete tail;
    }
    //建表
    void create_list(int size)
    {
        length = size;
        if (size < 0)
        {
            return;
        }
        head = new Node;
        head->next = head->last = nullptr;
        tail = head; //空链表头尾指针指向同一位置。
        for (int i = 0; i < size; i++)
        {
            Node *pnew = new Node;
            cin >> pnew->data;
            pnew->next = nullptr; // 新节点指向下一个
            pnew->last = tail;    // 头指针指向前一个元素
            tail->next = pnew;    // 前一个节点指向下一个节点
            tail = pnew;          // tail就是每次循环的上一个节点，每次让他变为新的节点就好了。
        }
        // 到最后，尾结点和最后一个节点的地址是一样的，然后这个时候new一个新的节点，作为尾结点就好了。
        Node *temp = new Node;
        temp->next = nullptr;
        temp->last = tail;
        tail = temp;
    }
    // 前序遍历 即从头往后遍历
    void showhead()
    {
        Node *temp = head->next; //第一个节点
        if (temp == nullptr)
        {
            return;
        }
        while (temp != nullptr && temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // 后驱（序）遍历
    void showtail()
    {
        Node *temp = tail; //从尾部开始
        if (temp == nullptr)
        {
            return;
        }
        while (temp->last != nullptr && temp->last != head) //前一个节点不为空切没到头
        {
            temp = temp->last; //向前遍历
            cout << temp->data << " ";
        }
        cout << endl;
    }
    // 二分的去查找数据，这就是双端链表的优势
    int find_index(int index)
    {
        if (length == 0)
        {
            cout << "empty" << endl;
            return 0;
        }
        if (index > length || index < 0)
        {
            cout << "Not Found" << endl;
            return 0;
        }
        if (index <= length / 2) //前一半
        {
            Node *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }
        else //在后半部分
        {
            Node *temp = tail;
            for (int i = 0; i < length - index + 1; i++)
            {
                temp = temp->last;
            }
            return temp->data;
        }
    }
    // 插入的操作是要实现 3个节点直接互相链接成一个稳定的链结构，也就是，后一个节点的头，和尾都要链接这个新插入的节点。
    void insert(T e, int index)
    {
        if (index < 0 || index > length)
        {
            cout << "insert False" << endl;
            return;
        }
        Node *newnode = new Node;
        newnode->data = e;
        if (index <= length / 2)
        {
            Node *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next; //遍历到该位置
            }
            newnode->last = temp;         //新节点的头连到tmp
            newnode->next = temp->next;   // 尾部指向下一个节点
            (temp->next)->last = newnode; // 后一个节点的头，链接插入的节点 也就是要找到节点temp的后继
            (temp->last)->next = newnode; // 前一个节点的尾部，链接插入的节点 找到节点temp的前驱
            temp->next = newnode;         // 最后temp的下一个节点就变成了插入的这个节点了，然后就直接给他赋值。
        }
        else
        {
            Node *temp = tail;
            for (int i = 0; i < length - index + 1; i++)
            {
                temp = temp->last;
            }
            newnode->last = temp->last;
            (temp->last)->next = newnode;
            temp->last = newnode;
            newnode->next = temp;
        }
        length++;
    }
    void delete_index(int index)
    {
        if (index < 0 || index > length || length == 0)
        {
            return;
        }
        if (index <= length / 2)
        {
            Node *p = head;
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
            p->last->next = p->next;
            p->next->last = p->last;
            delete p;
        }
        else if (index > length / 2)
        {
            Node *p = tail;
            for (int i = 0; i < length - index + 1; i++)
            {
                p = p->last;
            }
            p->last->next = p->next;
            p->next->last = p->last;
        }
        length--;
    }
};