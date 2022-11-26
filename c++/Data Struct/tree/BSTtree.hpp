#include <iostream>
#include <queue>
#include <stack>
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
    // ��̬����ڵ�����
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
        Node *p = root;
        while(p!=nullptr)
        {
            remove(p);
        }
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
    /*
        @brief ���ؽڵ���
    */
    int get_Nodes()
    {
        cout << "bst���Ľڵ���Ϊ" << endl;
        return treelen;
    }
    // ����ڵ�
    void Insert(T data)
    {
        root = Insert(root, data); // ������ĸ���������ԭ���趨��һ��ȫ�ֱ�������̬�ı�ʾ�����Ľڵ㡣
        treelen++;
    }

    // �������ĸ�
    Node *get_root()
    {
        return root;
    }
    // ������������ɾ���ڵ�
    void Remove(T data)
    {
        if (Remove(root, data) != nullptr)
            cout << "ɾ���ڵ�ɹ�" << endl;
        else
            cout << "�ڵ㲻����/����" << endl;
    }
    Node *Remove(Node *p, T data)
    {
        // �ж���Ҷ�ӽڵ㣬ֱ��ɾ��
        if (p == nullptr)
            return p;
        // �ж�����������
        else if (p->data > data)
        {
            p->left = Remove(p->left, data); // һֱ���������Ҫɾ���Ľڵ�
        }
        else if (p->data < data)
        {
            p->right = Remove(p->right, data);
        }
        // ok �������ýڵ��
        else
        { // ��Ҷ�ӽڵ�
            if (p->left == nullptr && p->right == nullptr)
            {
                delete p;
                p = nullptr;
            }
            // �����һ�����ڵ�����ӻ��Һ��ӣ����Һ��滹���ӽڵ㣬��ֱ��Խ������ڵ㵽����Ľڵ㡣
            else if (p->left == nullptr)
            {
                Node *temp = p;
                p = p->left;
                delete temp;
            }
            else if (p->right == nullptr)
            {
                Node *temp = p;
                p = p->right;
                delete temp;
            }
            // һ���ڵ�Ķ�Ϊ2 ������������
            else
            {
                Node *temp = find_min(p->right);
                p->data = temp->data;
                p->right = Remove(p->right, temp->data);
            }
        }

        return p;
    }
    // �жϽڵ��Ƿ�������
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
    // ����������������Сֵ
    Node *find_min(Node *p)
    {
        if (p == nullptr)
        {
            cout << "empty tree" << endl;
            return nullptr;
        }
        while (p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }
    T find_min()
    {
        Node *p = root;
        if (p == nullptr)
        {
            cout << "empty tree" << endl;
            return -1;
        }
        while (p->left != nullptr)
        {
            p = p->left;
        }
        return p->data;
    }
    // ���������������ֵ
    Node *find_max(Node *p)
    {
        if (p == nullptr)
        {
            cout << "empty tree" << endl;
            return nullptr;
        }
        while (p->right != nullptr)
        {
            p = p->right;
        }
        return p->data;
    }
    T find_max()
    {
        Node *p = root;
        if (p == nullptr)
        {
            cout << "empty tree" << endl;
            return -1;
        }
        while (p->right != nullptr)
        {
            p = p->right;
        }
        return p->data;
    }
    int find_height(Node *p)
    {
        if (p == nullptr)
            return -1;
        // int leftheight = find_height(p->left) + 1;
        // int rightheight = find_height(p->right) + 1;
        // return max(leftheight, rightheight);
        return max(find_height(p->left), find_height(p->right)) + 1;
    }
    void find_height()
    {
        cout << "���ĸ߶�/���Ϊ:" << find_height(root) << endl;
    }

    // ǰ�����
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
    // �������
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
    // �������
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
    // �������
    void level_order()
    {
        if (root == nullptr)
        {
            cout << "empty tree!" << endl;
        }
        queue<Node *> kk;

        kk.push(root); // һ��ʼ�����ڵ������
        while (!kk.empty())
        {
            Node *current = kk.front();   // ��ǰ��Ԫ�ص��ڶ���Ԫ��
            cout << current->data << " "; // ÿ�ζ���ӡһ�ζ���
            // �����Ҷ������
            if (current->left != nullptr)
                kk.push(current->left);
            if (current->right != nullptr)
                kk.push(current->right);
            kk.pop(); // һ��ѭ����������������
        }
        cout << endl;
    }
    // �ж��Ƿ�Ϊ����������
    bool isbst(Node *p, T minn, T maxx)
    {
        if (p == nullptr)
            return true;
        // �ȵݹ����������ж����䷶Χ������������������Ͳ��Ƕ��������������������д���ǰ��ڵ�ģ���������С��ǰ��ڵ�ġ�
        if (p->data >= minn && p->data <= maxx && isbst(p->left, minn, p->data) && isbst(p->right, p->data, maxx))
            return true;
        else
            return false;
    }
    void isBinarySearchTree()
    {
        if (isbst(root, INT_MIN, INT_MAX))
        {
            cout << "�ö�����Ϊ����������" << endl;
        }
        else
            cout << "�ö��������Ƕ���������" << endl;
    }
};