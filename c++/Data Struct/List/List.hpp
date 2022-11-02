#include <iostream>
using namespace std;
// https://www.bilibili.com/video/BV1BQ4y1R7y5/ 这个视频说的特别好

template <typename T>
class List
{
private:
    class Node
    {
    public:
        T data;     //当前结点的值
        Node *next; //为什么是Node类型呢，因为next指向的是下一个链表域，其中也包含着next，和data，所以是个类指针。可以理解为他指向的是下一个抽屉。
    };
    Node *head; //头结点 头结点不算节点，只是方便理解，他是空的。*next 才是第一个元素，可以理解为数轴的0
    int length; //链表长度
public:
    List()
    {
        head = new Node;
        head->data = 0;
        head->next = nullptr;
    }
    ~List()
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            delete p;
            p = p->next;
        }
        p->next = head->next = nullptr;
    }
    int get_len()
    {
        return length;
    }
    void Create_list1(int size) //创建链表的好理解版本
    {
        Node *p = head; //先得到头节点
        for (int i = 1; i <= size; i++)
        {
            Node *pnew = new Node; //先new一个新的节点
            pnew->data = i;        // 新节点赋值
            pnew->next = nullptr;  //新节点的下一个节点的地址赋值为空
            p->next = pnew;        // p的next指针指向下一个节点。
            p = pnew;              //因为pnew 的地址是new出来的地址，p = pnew 表示，将此时头结点的地址，指向了第i个节点的地址。
        }
    }

    void Create_list(int size) //创建一个链表
    {
        Node *pnew, *ptemp; //
        ptemp = head;
        if (size < 0)
        {
            exit(-1);
        }
        for (int i = 1; i <= size; i++)
        {
            pnew = new Node;      //先定义一个新的节点
            cin >> pnew->data;    // 输入这个节点的data的内容
            pnew->next = nullptr; //当前节点的下一个节点设为空指针。
            ptemp->next = pnew;   // 对于第一个，头节点指向pnew节点，当前节点的下一个设为新的节点。
            ptemp = pnew;         // 当前节点设为新节点，因为pnew是new出来的新节点，所以下次操作就是对这个节点进行操作了。如果是头节点，那就是说明下一次开始就是对第一个节点开始操作了。
            // Phead->pnew
        }
        length = size;
    }
    //遍历链表 打印
    void show_list()
    {
        if (head == nullptr && head->next == nullptr)
        {
            cout << "empty list" << endl;
            exit(-1);
        }
        Node *p = head;
        while (p->next)
        {
            p = p->next;
            cout << p->data << " ";
        }
        cout << endl;
    }
    Node *find(int index) //返回第index个结点。
    {
        int i = 1;
        Node *p = this->head; //结点指向头结点
        if (p == nullptr)
        {
            return nullptr;
        }
        while (p and i++ <= index)
            p = p->next; // 节点不断的往下遍历，直到达到index对应的节点。
        return p;
    }
    int find_ele(T e) // 查找第一个e的位置
    {
        Node *p = head; //获得头结点
        int i = 0;
        while (p->next != nullptr) // 下一个节点不为空
        {
            if (p->data == e)
                return i;
            else
            {
                p = p->next;
                i++;
            }
        }
        return -1;
    }
    //任意位置插入，(插入的数据,位置) 指定位置插入，也就是”切断“之前的两个节点之间的联系，并且插入一个新的元素
    void insert_index(T e, int index)
    {
        if (index < 0 || index > length)
        {
            cout << "insert error!" << endl;
        }
        else
        {
            Node *p = head;
            Node *ptemp = new Node; //创建一个新的节点
            ptemp->data = e;        // 将数据赋给这个节点
            int i = 1;
            while (i < index)
            {
                p = p->next;
                i++;
            }
            ptemp->next = p->next; //将ptemp 的指针指向p的下一个
            p->next = ptemp;       // 然后让p指向ptemp就实现了插入
            length++;
        }
    }
    // 头结点插入数据
    void insert_head(T e)
    {
        Node *newnode = new Node;
        newnode->data = e;
        Node *p = head; //让新节点等于头节点
        if (head == nullptr)
        {
            head = newnode;
        }
        newnode->next = p->next; //新节点指向原来的第一个节点
        p->next = newnode;       //头指向插入的节点
        length++;
    }
    void insert_tail(T e)
    {
        Node *newnode = new Node;
        newnode->next = nullptr;
        newnode->data = e;
        Node *p = head;
        while (p->next != nullptr) //直接遍历到尾结点
        {
            p = p->next;
        }
        p->next = newnode; //让尾结点的下一个指向新节点
        length++;
    }
    //删除同理，断开链接，再去掉节点。
    void delete_index(int index) //删除任意节点
    {
        if (index < 0 || index > length)
        {
            cout << "delete error!" << endl;
        }
        else
        {
            Node *ptemp = find(index); //找到对应的要删除的那个节点，并赋值给ptemp
            Node *p = head;
            while (p->next != ptemp) //遍历到指定节点的前一个节点
            {
                p = p->next;
            }
            p->next = ptemp->next; //让p与指定的节点的下一个节点链接。
            delete ptemp;
            ptemp = nullptr;
            length--;
        }
    }
    void reverse_list()
    {
        Node *cur = head;
        cout << head << endl;
        cout << cur << endl;
        Node *pre = nullptr;
        while (cur)
        {
            Node *temp = cur->next; // 储存cur的下一个节点，以防断链
            cur->next = pre;
            pre = cur;
            cur = temp;
            cout << pre << " ";
        }
        head = pre;
        cout << endl;
        cout << pre << endl;

        cout << head << endl;
    }
    void reverse_list1()
    {
        Node *newhead = nullptr;
        Node *cur = head;
        while (cur)
        {
            Node *temp = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = temp;
        }
        head = newhead;
    }
    void reverse()
    {
        Node *cur = head;
        Node *pre = nullptr;
        Node *temp;
        while (cur)
        {
            temp = cur->next; // 指向下一个节点
            cur->next = pre;  // 下一个节点指向前一个节点
            pre = cur;        // 让前一个节点等于当前节点
            cur = temp;       // 当前节点等于下一个节点
        }
        head = pre;
    }
};