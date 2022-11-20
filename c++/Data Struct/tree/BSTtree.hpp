#include <iostream>
using namespace std;
// 递推实现 https://blog.csdn.net/weixin_44132627/article/details/107336512
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
        root = nullptr; // 初始化 root为空
        treelen = 0;
    }
    // 动态插入生成
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
    // 插入节点
    // 在这里p是一个临时变量，表示插进去以后的每一个子树的节点
    // 顺路函数重载了
    Node *Insert(Node *p, T data)
    {
        if (p == nullptr)
        {
            Node *newnode = new Node(data);
            p = newnode;
            return p; // 根节点
        }
        if (data <= p->data) // 和根比大小，比根大就插入右子树，否则左子树
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
        root = Insert(root, data); // 在这里的根就是我们原本设定的一个全局变量，动态的表示更换的节点。
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
        cout << "前序遍历结果为：" << endl;
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
        cout << "中序遍历结果为" << endl;
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
        cout << root->data << " "; // 回溯时输出栈元素，由于所有的左子树已经被调用过了，所以回溯时先输出左节点，即达到左根右的效果。
        mid_order(root->right);
    }
    void after_order()
    {
        cout << "后序遍历结果为: " << endl;
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