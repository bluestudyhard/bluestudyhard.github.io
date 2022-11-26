#include <iostream>
#include <queue>
#include <stack>
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
    // 动态插入节点生成
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
    /*
        @brief 返回节点数
    */
    int get_Nodes()
    {
        cout << "bst树的节点数为" << endl;
        return treelen;
    }
    // 插入节点
    void Insert(T data)
    {
        root = Insert(root, data); // 在这里的根就是我们原本设定的一个全局变量，动态的表示更换的节点。
        treelen++;
    }

    // 返回树的根
    Node *get_root()
    {
        return root;
    }
    // 二叉搜索树中删除节点
    void Remove(T data)
    {
        if (Remove(root, data) != nullptr)
            cout << "删除节点成功" << endl;
        else
            cout << "节点不存在/树空" << endl;
    }
    Node *Remove(Node *p, T data)
    {
        // 判断是叶子节点，直接删除
        if (p == nullptr)
            return p;
        // 判断在左右子树
        else if (p->data > data)
        {
            p->left = Remove(p->left, data); // 一直遍历到这个要删除的节点
        }
        else if (p->data < data)
        {
            p->right = Remove(p->right, data);
        }
        // ok 遍历到该节点后
        else
        { // 是叶子节点
            if (p->left == nullptr && p->right == nullptr)
            {
                delete p;
                p = nullptr;
            }
            // 如果是一个父节点的左孩子或右孩子，而且后面还有子节点，就直接越过这个节点到后面的节点。
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
            // 一个节点的度为2 即有两个孩子
            else
            {
                Node *temp = find_min(p->right);
                p->data = temp->data;
                p->right = Remove(p->right, temp->data);
            }
        }

        return p;
    }
    // 判断节点是否在树内
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
    // 二叉搜索树中找最小值
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
    // 二叉搜索树找最大值
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
        cout << "树的高度/深度为:" << find_height(root) << endl;
    }

    // 前序遍历
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
    // 中序遍历
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
    // 后序遍历
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
    // 层序遍历
    void level_order()
    {
        if (root == nullptr)
        {
            cout << "empty tree!" << endl;
        }
        queue<Node *> kk;

        kk.push(root); // 一开始将根节点入队列
        while (!kk.empty())
        {
            Node *current = kk.front();   // 当前的元素等于队首元素
            cout << current->data << " "; // 每次都打印一次队首
            // 将左右儿子入队
            if (current->left != nullptr)
                kk.push(current->left);
            if (current->right != nullptr)
                kk.push(current->right);
            kk.pop(); // 一次循环结束，更换队首
        }
        cout << endl;
    }
    // 判断是否为二叉搜索树
    bool isbst(Node *p, T minn, T maxx)
    {
        if (p == nullptr)
            return true;
        // 先递归左子树，判断区间范围，如果不属于这个区间就不是二叉搜索树，即左子树有大于前面节点的，右子树有小于前面节点的。
        if (p->data >= minn && p->data <= maxx && isbst(p->left, minn, p->data) && isbst(p->right, p->data, maxx))
            return true;
        else
            return false;
    }
    void isBinarySearchTree()
    {
        if (isbst(root, INT_MIN, INT_MAX))
        {
            cout << "该二叉树为二叉搜索树" << endl;
        }
        else
            cout << "该二叉树不是二叉搜索树" << endl;
    }
};