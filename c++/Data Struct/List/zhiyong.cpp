#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class Node
{

public:
    int length;
    T value;
    Node<T> *next;
    Node<T> *pre;
    Node() = default;

    Node(T value) : value(value)
    {
    }

    int getLength()
    {
        return length;
    }

    void setLength(int length)
    {
        this->length = length;
    }

    T getValue()
    {
        return value;
    }

    void setValue(T value)
    {
        this->value = value;
    }

    Node<T> *getNext()
    {
        return next;
    }

    void setNext(Node<T> *next)
    {
        this->next = next;
    }

    Node<T> *getPre()
    {
        return pre;
    }

    void setPre(Node<T> *pre)
    {
        Node::pre = pre;
    }
    void print()
    {
        cout << "编号为：" << this->getLength() << "     value值为:" << this->getValue() << endl;
    }
};
template <class T>
class LinkList
{
    Node<T> *head; //前继节点
    int size;
    Node<T> *rear; //后继节点
public:
    //无参构造函数
    LinkList()
    {
        size = 0;
        Node<T> *node = new Node<T>(' ');
        node->setLength(size);
        head = node;
        rear = head;
    }
    //析构函数
    ~LinkList()
    {
        Node<T> *pre, *p;
        pre = head;
        p = pre->getNext();
        while (p != NULL)
        {
            delete pre;
            pre = p;
            p = p->getNext();
        }
        delete pre;
    }

    //头插法
    bool headInsert(Node<T> *node)
    {
        size++;
        if (head->getNext() == NULL)
        {
            head->setNext(node);
            rear = node;
            node->setPre(head);
        }
        else
        {
            node->setNext(head->getNext());
            node->getNext()->setPre(node);
            head->setNext(node);
        }
        rear->setNext(head->getNext());
        node->setPre(rear);
        lengthUpdate();
        return true;
    }

    //    尾插法
    bool lastInsert(Node<T> *node)
    {
        node->setLength(++size);

        if (head->getNext() == NULL)
        {
            head->setNext(node);
            node->setPre(node);
            node->setNext(node);
        }
        else
        {
            head->getNext()->setPre(node);
            rear->setNext(node);
            node->setPre(rear);
            node->setNext(head->getNext());
        }
        rear = node;

        return true;
    }
    //    指定位置插入
    bool insert(int index, Node<T> *node)
    {
        if (index < 1 || index > size + 1)
        {
            cout << "插入位置不合法" << endl;
            return false;
        }
        else if (index == 1)
        {
            //插入第一个元素用头插法
            return headInsert(node);
        }
        //插入最后一个元素用尾插法
        else if (index == size + 1)
        {
            return lastInsert(node);
        }
        else
        {
            size++;
            Node<T> *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->getNext();
            }
            temp->getPre()->setNext(node); // temp的前一个指针的next的指针指向node指针
            node->setPre(temp->getPre());  // node的pre指针指向temp的前一个指针
            temp->setPre(node);            // node的next指针指向temp指针
            node->setNext(temp);           // temp的pre指针指向node指针

            lengthUpdate();
            return true;
        }
    }
    //编号更新函数
    bool lengthUpdate()
    {
        Node<T> *temp = head->getNext();

        for (int i = 1; i <= size; i++)
        {
            temp->setLength(i);
            temp = temp->getNext();
        }
        return true;
    }

    // 指定节点的更新
    bool update(int length, T value)
    {

        if ((head->getNext()) == NULL)
        {
            cout << "链表为空，不能修改" << endl;
            return false;
        }
        Node<T> *temp = head->getNext();
        bool flag = false;
        while (temp != NULL)
        {
            if (temp->getLength() == length)
            {
                //找到编号，退出循环
                flag = true;
                break;
            }
            //没找到编号，继续循环，temp指针指向下一个指针
            temp = temp->getNext();
        }
        if (flag)
        {
            temp->setValue(value);
        }
        else
        {
            cout << "没有找到编号为" << +temp->getLength() << "的节点，不能修改" << endl;
            return false;
        }
        return true;
    }

    //根据节点编号删除指定节点
    bool del(int length)
    {
        if (head->getNext() == NULL)
        {
            cout << "链表为空" << endl;
            return false;
        }
        Node<T> *temp = head;
        bool flag = false;
        while (true)
        {
            //判断链表是否为空??
            if (temp->getNext() == NULL)
            {
                break;
            }
            if (temp->getNext()->getLength() == length)
            {
                //找到指定编号，退出循环
                flag = true;
                break;
            }
            temp = temp->getNext();
        }
        if (flag)
        {
            //创建一个g删除节点指向要删除的结点,后面删除
            Node<T> *dele = temp->getNext();
            //先判断结点是否只有一个
            if (size == 1)
            {
                rear = head;
            }
            //要删除的元素是最后一个元素
            else if (dele == rear)
            {
                temp->setNext(head->getNext());
                head->getNext()->setPre(temp);
                rear = temp;
            }
            else if (dele == head->getNext())
            {
                head->setNext(dele->getNext());
                dele->getNext()->setPre(rear);
                rear->setNext(dele->getNext());
            }

            else
            {
                temp->getNext()->getNext()->setPre(temp);
                temp->setNext(temp->getNext()->getNext());
            }
            delete dele;
            size--;
            lengthUpdate();
        }
        else
        {
            cout << "要删除的编号为" << length << "的结点不存在" << endl;
            return false;
        }
        return true;
    }

    //顺序遍历函数
    void traverse()
    {
        //循环依次遍历
        if (isEmpty())
        {
            cout << "链表为空" << endl;
            return;
        }
        Node<T> *temp = head->getNext(); //第一个元素
        temp->print();
        temp = temp->getNext();
        while (temp != nullptr && temp != head->getNext())
        {
            temp->print();
            temp = temp->getNext();
        }
    }
    //反向遍历
    void reverseTraverse()
    {
        if (isEmpty())
        {
            cout << "链表为空" << endl;
            return;
        }
        Node<T> *temp = rear; //最后一个元素
        temp->print();
        temp = temp->getPre();
        while (temp != nullptr && temp != rear)
        {
            temp->print();
            temp = temp->getPre();
        }
    }
    //判断链表为空
    bool isEmpty()
    {
        return size == 0;
    }
    //根据no值查找节点
    Node<T> *getNodeByLength(int length)
    {
        if (isEmpty())
        {
            cout << "链表为空" << endl;
            return NULL;
        }
        Node<T> *temp = head;
        bool flag = false;
        while (true)
        {
            if (temp == NULL)
            {
                break;
            }
            if (temp->getLength() == length)
            {
                flag = true;
                break;
            }
            temp = temp->getNext();
        }
        if (flag)
        {
            return temp;
        }
        else
        {
            cout << "要寻找的编号为:" << length << " 的节点不存在" << endl;
        }
        return NULL;
    }
    //根据value值查找节点
    Node<T> *getNodeByValue(T value)
    {
        if (isEmpty())
        {
            cout << "链表为空" << endl;
            return NULL;
        }
        Node<T> *temp = head;
        bool flag = false;
        while (true)
        {
            if (temp == NULL)
            {
                break;
            }
            if (temp->getValue() == value)
            {
                flag = true;
                break;
            }
            temp = temp->getNext();
        }
        if (flag)
        {
            return temp;
        }
        else
        {
            cout << "要寻找的编号value:" << value << " 的节点不存在" << endl;
            return nullptr;
        }
    }

    //获得链表长度
    int getSize()
    {
        return size;
    }
};

int main()
{
    auto *list = new LinkList<char>();
    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            list->headInsert(new Node<char>(char(i + 65)));
        }
        else
        {
            list->lastInsert(new Node<char>(char(i + 65)));
        }
    }
    cout << "顺序遍历" << endl;
    list->traverse();
    cout << "反向遍历" << endl;
    list->reverseTraverse();
    cout << "删除第一个元素" << endl;
    list->del(1);
    cout << "链表长度为:" << list->getSize() << endl;
    cout << "顺序遍历" << endl;
    list->traverse();
    cout << "在第五个位置上插入一个元素" << endl;
    list->insert(5, new Node<char>('T'));
    cout << "链表长度为:" << list->getSize() << endl;
    cout << "顺序遍历" << endl;
    list->traverse();
    cout << "对编号为4的结点进行更新" << endl;
    list->update(4, 'G');
    cout << "顺序遍历" << endl;
    list->traverse();
    cout << "查找value为J的结点" << endl;
    list->getNodeByValue('J')->print();
    cout << "查找编号为6的结点";
    list->getNodeByLength(6)->print();
}
