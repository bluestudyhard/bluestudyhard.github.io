#include <iostream>
using namespace std;
// ����ʵ�� https://blog.csdn.net/weixin_44132627/article/details/107336512
template <typename T>
struct BSTNode
{
    T data;
    BSTNode *left;
    BSTNode *right;
    BSTNode() : data(0), left(nullptr), right(nullptr){};
    BSTNode(T num) : data(num), left(nullptr), right(nullptr){};
    BSTNode(T data, BSTNode *left, BSTNode *right) : data(data), left(left), right(right){};
};

template <typename T>
class BSTtree
{
private:
    typedef BSTNode<T> Node;
    Node *root;
    int treelen;

public:
    BSTtree()
    {
        root = nullptr; // ��ʼ�� rootΪ��
        treelen = 0;
    }
    // ��̬��������
    void bulid_tree(T *arr, int len)
    {

        for (int i = 0; i < len; i++)
        {
            Insert(arr[i]);
        }
        treelen = len;
    }
    ~BSTtree()
    {
    }
    // ����ڵ�
    // ������p��һ����ʱ��������ʾ���ȥ�Ժ��ÿһ�������Ľڵ�
    // ˳·����������
    Node *Insert(Node *p, T data)
    {
        if (p == nullptr)
        {
            Node *newnode = new Node(data);
            p = newnode;
            return p; // ���ڵ�
        }
        if (data <= p->data) // �͸��ȴ�С���ȸ���Ͳ���������������������
        {
            p->left = Insert(p->left, data);
        }
        else if (data > p->data)
        {
            p->right = Insert(p->right, data);
        }
        return p;
    }
    void Insert(T data)
    {
        root = Insert(root, data); // ������ĸ���������ԭ���趨��һ��ȫ�ֱ�������̬�ı�ʾ�����Ľڵ㡣
        treelen++;
    }

    void Remove();
    bool find(T e)
    {
        if (find(root, e))
        {
            cout << "Found" << endl;
            return true;
        }
        cout << "Not Found!" << endl;
        return false;
    }
    bool find(Node *p, T e)
    {
        if (p == nullptr)
            return false;
        else if (p->data == e)
        {
            return true;
        }
        else if (e <= p->data)
        {
            return find(p->left, e);
        }
        else
        {
            return find(p->right, e);
        }
    }
    void pre_order()
    {
        cout << "ǰ��������Ϊ��" << endl;
        pre_order(root);
        cout << endl;
    }
    void pre_order(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
    void mid_order()
    {
        cout << "����������Ϊ" << endl;
        mid_order(root);
        cout << endl;
    }
    void mid_order(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        mid_order(root->left);
        cout << root->data << " "; // ����ʱ���ջԪ�أ��������е��������Ѿ������ù��ˣ����Ի���ʱ�������ڵ㣬���ﵽ����ҵ�Ч����
        mid_order(root->right);
    }
    void after_order()
    {
        cout << "����������Ϊ: " << endl;
        after_order(root);
        cout << endl;
    }
    void after_order(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        after_order(root->left);
        after_order(root->right);
        cout << root->data << " ";
    }
};