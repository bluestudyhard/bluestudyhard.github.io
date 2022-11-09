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
        cout << "���Ϊ��" << this->getLength() << "     valueֵΪ:" << this->getValue() << endl;
    }
};
template <class T>
class LinkList
{
    Node<T> *head; //ǰ�̽ڵ�
    int size;
    Node<T> *rear; //��̽ڵ�
public:
    //�޲ι��캯��
    LinkList()
    {
        size = 0;
        Node<T> *node = new Node<T>(' ');
        node->setLength(size);
        head = node;
        rear = head;
    }
    //��������
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

    //ͷ�巨
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

    //    β�巨
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
    //    ָ��λ�ò���
    bool insert(int index, Node<T> *node)
    {
        if (index < 1 || index > size + 1)
        {
            cout << "����λ�ò��Ϸ�" << endl;
            return false;
        }
        else if (index == 1)
        {
            //�����һ��Ԫ����ͷ�巨
            return headInsert(node);
        }
        //�������һ��Ԫ����β�巨
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
            temp->getPre()->setNext(node); // temp��ǰһ��ָ���next��ָ��ָ��nodeָ��
            node->setPre(temp->getPre());  // node��preָ��ָ��temp��ǰһ��ָ��
            temp->setPre(node);            // node��nextָ��ָ��tempָ��
            node->setNext(temp);           // temp��preָ��ָ��nodeָ��

            lengthUpdate();
            return true;
        }
    }
    //��Ÿ��º���
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

    // ָ���ڵ�ĸ���
    bool update(int length, T value)
    {

        if ((head->getNext()) == NULL)
        {
            cout << "����Ϊ�գ������޸�" << endl;
            return false;
        }
        Node<T> *temp = head->getNext();
        bool flag = false;
        while (temp != NULL)
        {
            if (temp->getLength() == length)
            {
                //�ҵ���ţ��˳�ѭ��
                flag = true;
                break;
            }
            //û�ҵ���ţ�����ѭ����tempָ��ָ����һ��ָ��
            temp = temp->getNext();
        }
        if (flag)
        {
            temp->setValue(value);
        }
        else
        {
            cout << "û���ҵ����Ϊ" << +temp->getLength() << "�Ľڵ㣬�����޸�" << endl;
            return false;
        }
        return true;
    }

    //���ݽڵ���ɾ��ָ���ڵ�
    bool del(int length)
    {
        if (head->getNext() == NULL)
        {
            cout << "����Ϊ��" << endl;
            return false;
        }
        Node<T> *temp = head;
        bool flag = false;
        while (true)
        {
            //�ж������Ƿ�Ϊ��??
            if (temp->getNext() == NULL)
            {
                break;
            }
            if (temp->getNext()->getLength() == length)
            {
                //�ҵ�ָ����ţ��˳�ѭ��
                flag = true;
                break;
            }
            temp = temp->getNext();
        }
        if (flag)
        {
            //����һ��gɾ���ڵ�ָ��Ҫɾ���Ľ��,����ɾ��
            Node<T> *dele = temp->getNext();
            //���жϽ���Ƿ�ֻ��һ��
            if (size == 1)
            {
                rear = head;
            }
            //Ҫɾ����Ԫ�������һ��Ԫ��
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
            cout << "Ҫɾ���ı��Ϊ" << length << "�Ľ�㲻����" << endl;
            return false;
        }
        return true;
    }

    //˳���������
    void traverse()
    {
        //ѭ�����α���
        if (isEmpty())
        {
            cout << "����Ϊ��" << endl;
            return;
        }
        Node<T> *temp = head->getNext(); //��һ��Ԫ��
        temp->print();
        temp = temp->getNext();
        while (temp != nullptr && temp != head->getNext())
        {
            temp->print();
            temp = temp->getNext();
        }
    }
    //�������
    void reverseTraverse()
    {
        if (isEmpty())
        {
            cout << "����Ϊ��" << endl;
            return;
        }
        Node<T> *temp = rear; //���һ��Ԫ��
        temp->print();
        temp = temp->getPre();
        while (temp != nullptr && temp != rear)
        {
            temp->print();
            temp = temp->getPre();
        }
    }
    //�ж�����Ϊ��
    bool isEmpty()
    {
        return size == 0;
    }
    //����noֵ���ҽڵ�
    Node<T> *getNodeByLength(int length)
    {
        if (isEmpty())
        {
            cout << "����Ϊ��" << endl;
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
            cout << "ҪѰ�ҵı��Ϊ:" << length << " �Ľڵ㲻����" << endl;
        }
        return NULL;
    }
    //����valueֵ���ҽڵ�
    Node<T> *getNodeByValue(T value)
    {
        if (isEmpty())
        {
            cout << "����Ϊ��" << endl;
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
            cout << "ҪѰ�ҵı��value:" << value << " �Ľڵ㲻����" << endl;
            return nullptr;
        }
    }

    //���������
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
    cout << "˳�����" << endl;
    list->traverse();
    cout << "�������" << endl;
    list->reverseTraverse();
    cout << "ɾ����һ��Ԫ��" << endl;
    list->del(1);
    cout << "������Ϊ:" << list->getSize() << endl;
    cout << "˳�����" << endl;
    list->traverse();
    cout << "�ڵ����λ���ϲ���һ��Ԫ��" << endl;
    list->insert(5, new Node<char>('T'));
    cout << "������Ϊ:" << list->getSize() << endl;
    cout << "˳�����" << endl;
    list->traverse();
    cout << "�Ա��Ϊ4�Ľ����и���" << endl;
    list->update(4, 'G');
    cout << "˳�����" << endl;
    list->traverse();
    cout << "����valueΪJ�Ľ��" << endl;
    list->getNodeByValue('J')->print();
    cout << "���ұ��Ϊ6�Ľ��";
    list->getNodeByLength(6)->print();
}
