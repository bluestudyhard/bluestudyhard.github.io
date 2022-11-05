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
        // ͷβ��ȫ����hhh
        head->next = head->pre = tail; //ͷ����һ���ڵ��ǰһ���ڵ㶼ָ��β
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
            Node *newnode = new Node; // ����һ���µĽڵ�
            cin >> newnode->data;     //
            p->next = newnode;        //��ǰ�ڵ�ָ����һ���ڵ�
            newnode->pre = p;         //��һ���ڵ��ǰ��ָ��ǰ�ڵ�
            newnode->next = nullptr;  //��һ���ڵ�ָ���
            p = newnode;              // ��ǰ�ڵ������һ���ڵ�
        }
        // ��ʱp�Ѿ���β�ˣ�Ҫ��β���p��Ȼ���ٺ�ͷ����
        tail = p;
        tail->next = head; // β�ĺ��ָ��ͷ
        head->pre = tail;  //ͷ��ǰ��ָ��β����ô�ȶ��Ľṹ
        len = l;
    };
    // ǰ�����
    void show_list()
    {
        if (isempty())
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *p = head->next;
        cout << "����ĸ����ڵ�Ԫ��Ϊ" << endl;
        for (int i = 1; i <= len; i++)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    // �������
    void show_reverse()
    {
        if (isempty())
        {
            cout << "Empty List" << endl;
            return;
        }
        Node *p = tail;
        cout << "����Ӻ���ǰ�����Ľڵ�Ϊ" << endl;
        while (p != head)
        {
            cout << p->data << " ";
            p = p->pre;
        }
        cout << endl;
    }
    // �滻�ڵ�
    void replace_ele(T e, int index)
    {
        if (index < 0 || index > len)
        {
            cout << "�滻ʧ��" << endl;
            return;
        }

        Node *temp = new Node;
        temp->data = e;
        Node *p = head;
        for (int i = 1; i <= index; i++)
        {
            p = p->next; // ������Ҫ�����λ�� pָ�ľ���tempҪ�����λ��
        }
        cout << "�滻�ɹ�" << endl;
        temp->pre = p->pre; // temp ��ǰ��
        temp->next = p->next;
        p->next->pre = temp; // ��һ���ڵ��ǰ��ָ�����
        p->pre->next = temp;
    }
    // ����λ�ò���ڵ�
    void insert_ele(T e, int index)
    {
        if (index <= 0 || index > len)
        {
            cout << "insert err" << endl;
            return;
        }
        else
            cout << "����ɹ�" << endl;
        Node *newnode = new Node; // Ϊʲô�µĽڵ�һ��Ҫnew�����أ�����û��new��һ���ڵ��൱��������ڵ�û�п���һ���µĿռ䣬ϵͳ�ͻ�������һ������ģ������ù��ĵ�ַ.����ûnew�ռ���ô�������ݡ�
        newnode->data = e;
        // ��2�ֵ�˼��������
        if (index <= len / 2)
        {
            Node *p = head;
            for (int i = 1; i <= index; i++)
            {
                p = p->next; // ������Ҫ��������λ�� ����˵ ��2��λ�ò��룬������2 ��ʱ p-data = 2;
            }
            newnode->next = p;      // ����ڵ����һ��ָ��ָ��p
            newnode->pre = p->pre;  // ����ڵ��ǰһ��ָ��ָ��p��ǰһ���ڵ�
            p->pre->next = newnode; // p��ǰһ���ڵ�ָ�����ڵ�
            p->pre = newnode;       // p��ǰָ��ָ�����ڵ� ������ 1 2 3 ������3 �����������Ժ�ͱ���� 1 3 2 3
        }
        else
        {
            Node *p = tail;
            for (int i = len; i >= index; i--)
            {
                p = p->pre; // ��β��������Ҫ����Ľڵ�λ�� ����˵����4��λ�ò��� p��λ�ñ�����4
            }
            // ��ǰ��ͬ��
            newnode->next = p;
            newnode->pre = p->pre;
            p->pre->next = newnode;
            p->pre = newnode;
        }
        len++;
    }
    int get_len()
    {
        cout << "��ǰ����ĳ���Ϊ" << len << endl;
        return len;
    }
    // ɾ���ڵ�
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
                p = p->next; // ǰ��������Ҫɾ���Ľڵ�
            }
            p->next->pre = p->pre;  // ��һ���ڵ�ָ��ǰ�ڵ��ǰһ���ڵ�
            p->pre->next = p->next; // ǰһ���ڵ�ָ��ǰ�ڵ�ĺ�һ���ڵ�
            delete p;
        }
        else
        {
            Node *p = tail;
            for (int i = len; i >= index; i--)
            {
                p = p->pre; // ǰ��������Ҫɾ���Ľڵ�
            }
            p->next->pre = p->pre;  // ��һ���ڵ�ָ��ǰ�ڵ��ǰһ���ڵ�
            p->pre->next = p->next; // ǰһ���ڵ�ָ��ǰ�ڵ�ĺ�һ���ڵ�
            delete p;
        }
        cout << "ɾ���ڵ�ɹ�" << endl;
        len--;
    }
    // ���ҽڵ�
    Node *find_Node(int index)
    {
        if (index <= 0 || index > len)
        {
            cout << "�Ҳ�������������" << endl;
            return nullptr;
        }
        if (index <= len / 2)
        {
            Node *p = head;
            for (int i = 1; i <= index; i++)
            {
                p = p->next;
            }
            cout << "���صĽڵ�Ϊ " << p << endl;
            return p;
        }
        else
        {
            Node *p = tail;
            for (int i = len; i >= index; i--)
            {
                p = p->pre;
            }
            cout << "���صĽڵ�Ϊ " << p << endl;
            return p;
        }
    }
    // ����Ԫ�� �����ҵ��ĵ�һ��Ԫ�ص��±�
    int find_ele(T e)
    {
        Node *p = head;
        for (int i = 1; i <= len; i++)
        {
            if (p->data == e)
            {
                cout << "��Ԫ�ص�һ�γ��ֵ�λ��: " << i << endl;
                return i;
            }
            p = p->next;
        }
        cout << "δ�ҵ���Ԫ��ร�" << endl;
        return -1;
    }

    //�������
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
    // �ж��Ƿ�Ϊ��
    bool isempty()
    {
        if (len == 0)
        {
            cout << "��ǰ����Ϊ��" << endl;
        }
        return len == 0;
    }
    // β�巨
    void push_tail(T e)
    {

        Node *temp = new Node;
        temp->next = tail;
        temp->next = tail->next; // �½ڵ����һ��ָ��ָ��ͷ
        temp->pre = tail;        // ǰ��ָ��β
        tail->next = temp;       // β�ĺ�̱�Ϊ����ڵ�
        head->pre = temp;        // ͷ��ǰ����Ϊ����ڵ�
        temp->data = e;
        tail = temp; // ��β��ɲ���ڵ�

        len++;
    }
};