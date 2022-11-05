#include <iostream>
using namespace std;
template <typename T>
class double_circle_list
{
private:
    class Node
    {
    public:
        Node *next;
        Node *pre;
        T data;
    };
    Node *head, *tail;
    int len;

public:
    double_circle_list()
    {
        head = new Node;
        tail = new Node;
        // 头尾完全相连hhh
        head->next = head->pre = tail; //头的下一个节点和前一个节点都指向尾
        tail->pre = tail->next = head;
        head->data = tail->data = 0;
        len = 0;
    }
    ~double_circle_list()
    {

        clear();
        delete head;
        delete tail;
    }
    void create_list(int l)
    {
        Node *p = head;
        for (int i = 1; i <= l; i++)
        {
            Node *newnode = new Node; // 创建一个新的节点
            cin >> newnode->data;     //
            p->next = newnode;        //当前节点指向下一个节点
            newnode->pre = p;         //下一个节点的前驱指向当前节点
            newnode->next = nullptr;  //下一个节点指向空
            p = newnode;              // 当前节点等于下一个节点
        }
        // 此时p已经到尾了，要让尾变成p，然后再和头相连
        tail = p;
        tail->next = head; // 尾的后继指向头
        head->pre = tail;  //头的前驱指向尾，多么稳定的结构
        len = l;
    };
    // 前序遍历
    void show_list()
    {
        if (isempty())
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *p = head->next;
        cout << "链表的各个节点元素为" << endl;
        for (int i = 1; i <= len; i++)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    // 后序遍历
    void show_reverse()
    {
        if (isempty())
        {
            cout << "Empty List" << endl;
            return;
        }
        Node *p = tail;
        cout << "链表从后往前遍历的节点为" << endl;
        while (p != head)
        {
            cout << p->data << " ";
            p = p->pre;
        }
        cout << endl;
    }
    // 替换节点
    void replace_ele(T e, int index)
    {
        if (index < 0 || index > len)
        {
            cout << "替换失败" << endl;
            return;
        }

        Node *temp = new Node;
        temp->data = e;
        Node *p = head;
        for (int i = 1; i <= index; i++)
        {
            p = p->next; // 遍历到要插入的位置 p指的就是temp要插入的位置
        }
        cout << "替换成功" << endl;
        temp->pre = p->pre; // temp 的前驱
        temp->next = p->next;
        p->next->pre = temp; // 后一个节点的前驱指向这个
        p->pre->next = temp;
    }
    // 任意位置插入节点
    void insert_ele(T e, int index)
    {
        if (index <= 0 || index > len)
        {
            cout << "insert err" << endl;
            return;
        }
        else
            cout << "插入成功" << endl;
        Node *newnode = new Node; // 为什么新的节点一定要new出来呢，你想没有new出一个节点相当于你这个节点没有开辟一个新的空间，系统就会给你分配一个随机的，可能用过的地址.而且没new空间怎么储存数据。
        newnode->data = e;
        // 用2分的思想来插入
        if (index <= len / 2)
        {
            Node *p = head;
            for (int i = 1; i <= index; i++)
            {
                p = p->next; // 遍历到要插入的这个位置 比如说 在2的位置插入，遍历到2 此时 p-data = 2;
            }
            newnode->next = p;      // 插入节点的下一个指针指向p
            newnode->pre = p->pre;  // 插入节点的前一个指针指向p的前一个节点
            p->pre->next = newnode; // p的前一个节点指向插入节点
            p->pre = newnode;       // p的前指针指向插入节点 比如在 1 2 3 二插入3 这样处理完以后就变成了 1 3 2 3
        }
        else
        {
            Node *p = tail;
            for (int i = len; i >= index; i--)
            {
                p = p->pre; // 从尾部遍历到要插入的节点位置 假如说我在4的位置插入 p的位置遍历到4
            }
            // 与前面同理
            newnode->next = p;
            newnode->pre = p->pre;
            p->pre->next = newnode;
            p->pre = newnode;
        }
        len++;
    }
    int get_len()
    {
        cout << "当前链表的长度为" << len << endl;
        return len;
    }
    // 删除节点
    void delete_ele(int index)
    {
        if (index <= 0 || index > len)
        {
            cout << "delete error!" << endl;
            return;
        }
        //  Node *temp = new Node;
        if (index <= len / 2)
        {
            Node *p = head;
            for (int i = 1; i <= index; i++)
            {
                p = p->next; // 前驱遍历到要删除的节点
            }
            p->next->pre = p->pre;  // 后一个节点指向当前节点的前一个节点
            p->pre->next = p->next; // 前一个节点指向当前节点的后一个节点
            delete p;
        }
        else
        {
            Node *p = tail;
            for (int i = len; i >= index; i--)
            {
                p = p->pre; // 前驱遍历到要删除的节点
            }
            p->next->pre = p->pre;  // 后一个节点指向当前节点的前一个节点
            p->pre->next = p->next; // 前一个节点指向当前节点的后一个节点
            delete p;
        }
        cout << "删除节点成功" << endl;
        len--;
    }
    // 查找节点
    Node *find_Node(int index)
    {
        if (index <= 0 || index > len)
        {
            cout << "找不到辣！别找辣" << endl;
            return nullptr;
        }
        if (index <= len / 2)
        {
            Node *p = head;
            for (int i = 1; i <= index; i++)
            {
                p = p->next;
            }
            cout << "返回的节点为 " << p << endl;
            return p;
        }
        else
        {
            Node *p = tail;
            for (int i = len; i >= index; i--)
            {
                p = p->pre;
            }
            cout << "返回的节点为 " << p << endl;
            return p;
        }
    }
    // 查找元素 返回找到的第一个元素的下标
    int find_ele(T e)
    {
        Node *p = head;
        for (int i = 1; i <= len; i++)
        {
            if (p->data == e)
            {
                cout << "该元素第一次出现的位置: " << i << endl;
                return i;
            }
            p = p->next;
        }
        cout << "未找到该元素喔！" << endl;
        return -1;
    }

    //清空链表
    void clear()
    {
        int length = len;
        for (int i = 1; i <= length; i++)
        {
            delete_ele(1);
        }
        if (len == 0)
        {
            cout << "clear success!" << endl;
        }
        else
            cout << "clear error!";
    }
    // 判断是否为空
    bool isempty()
    {
        if (len == 0)
        {
            cout << "当前链表为空" << endl;
        }
        return len == 0;
    }
    // 尾插法
    void push_tail(T e)
    {

        Node *temp = new Node;
        temp->next = tail;
        temp->next = tail->next; // 新节点的下一个指针指向头
        temp->pre = tail;        // 前驱指向尾
        tail->next = temp;       // 尾的后继变为插入节点
        head->pre = temp;        // 头的前驱变为插入节点
        temp->data = e;
        tail = temp; // 将尾变成插入节点

        len++;
    }
};