#include <iostream>
using namespace std;
template <typename T>
class list_stack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *top;
    int length;
public:
    list_stack()
    {
        top = nullptr;
        length = 0;
    }
    ~list_stack()
    {
        Node *p;
        while (top != nullptr)
        {
            p = top->next; // ��ջ����ʼ��һ��������ͷſռ�
            delete top;
            top = p;
        }
    }
    void push(T e)
    {
        Node *newnode = new Node;
        newnode->data = e;
        newnode->next = top;
        top = newnode; // ÿ�β������ջ��
        length++;      //ջ����++
    }
    bool pop()
    {
        if (top == nullptr)
        {
            cout << "ջ��" << endl;
            return false;
        }
        cout << "pop����" << endl;
        Node *p = top;   // ��ջ����ʼ
        top = top->next; //ջ�����ջ������һ����Ȼ��delete���ͺ���
        delete p;
        length--;
        return true;
    }
    T get_top()
    {
        cout << "ջ��Ԫ��Ϊ" << endl;
        return top->data;
    }
    int get_len()
    {
        cout << "��ǰ��ջ����Ϊ" << endl;
        return length;
    }
    void show_stack()
    {
        cout << "��ջ��Ԫ�ش�ջ����ջ������Ϊ" << endl;
        if (isempty())
        {
            cout << "����ջΪ��" << endl;
        }
        Node *p = top;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    bool isempty()
    {
        if (length == 0 || top == nullptr)
        {

            return true;
        }
        else
            return false;
    }
};
int main()
{
    list_stack<int> l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.show_stack();
    cout << l.get_top() << endl;
    l.pop();
    l.show_stack();
    l.pop();
    l.show_stack();
    cout << l.isempty() << endl;
}