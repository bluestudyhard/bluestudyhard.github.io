#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>
template <typename T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T data, TreeNode *left = nullptr, TreeNode *right = nullptr) : data(data), left(left), right(right) {}
};
template <typename T>
class binarytree
{
    typedef TreeNode<T> Node;

private:
    Node *root;
    int treelen;

public:
    binarytree()
    {
        root = nullptr;
        treelen = 0;
    }
    ~binarytree()
    {
        Destroy();
    }
    /*
        @brief 返回节点数
    */
    int get_Nodes()
    {
        cout << "普通二叉树的节点数为" << endl;
        return treelen;
    }
    // 前序遍历创建二叉树
    void precreate(Node *p)
    {
        T data;
        cin >> data;
        if (data == -1)
        {
            p = nullptr;
            return;
        }
        treelen++;
        p = new Node(data);
        precreate(p->left);
        precreate(p->right);
    }
    /*
        @brief 获取根节点
    */
    Node *get_root()
    {
        return root;
    }
    /*
        @brief 获取树的高度
        @param 原理就是看谁递归的层次够深
    */
    int get_height(Node *p)
    {
        if (p == nullptr)
            return -1;
        int left = get_height(p->left) + 1;
        int right = get_height(p->right) + 1;
        return max(left, right);
    }
    void get_height()
    {
        cout << "树的高度/深度为：" << get_height(root) << endl;
    }
    /*
        @brief 判空
    */
    bool isempty()
    {
        return root == nullptr ? true : false;
    }
    /*
        判断节点是否存在子树
    */
    bool isexist(Node *p, bool direct)
    { // 如果有左右节点或者左右子树
        if (p == nullptr || p->left != nullptr && direct || p->right != nullptr && !direct)
            return true;
        return false;
    }
    /*
        @brief 查找节点，并返回
    */
    void find_node(T data)
    {
        Node *p = find_node(root, data);
        if (p != nullptr)
            cout << "返回节点值为" << data << "的节点" << p
                 << "值为" << p->data << endl;
        else
            cout << "nodes not exist!" << endl;
    }

    Node *find_node(Node *p, T data)
    {
        if (p == nullptr)
            return nullptr;
        if (p->data == data)
        {
            return p;
        }
        // 在左右子树中搜索节点
        Node *temp = find_node(p->left, data);
        // return find_node(p->left, data);
        if (temp != nullptr)
        {
            return temp;
        }
        else
            return find_node(p->right, data);
    }
    /*
        @brief 在树中找到节点的儿子
    */
    void find_parent(T data)
    {
        Node *son = find_node(root, data);
        Node *p = find_parent(root, son);
        if (p != nullptr)
        {
            cout << "节点" << son->data << "的父节点元素为" << p << " " << p->data << endl;
        }
        else
        {
            cout << "Not root or root is nullptr or is root" << endl;
            return;
        }
    }
    Node *find_parent(Node *p, Node *son)
    { // 还要特判一个根节点的父元素
        if (p == nullptr || son == root)
            return nullptr;
        // 如果属于父节点的左或右子树,甚至是根的话
        if (p->left == son || p->right == son)
            return p;
        // 在左子树中递归搜索
        Node *temp = find_parent(p->left, son);
        if (temp != nullptr)
        {
            return temp;
        }
        // 在右子树中递归搜索
        else
        {
            return find_parent(p->right, son);
        }
    }

    /*
        @brief 在任意已存在的节点插入元素
        direct 表示插入左子树还是右子树，true 为左 false 为右
    */
    bool Insert(Node *parent, Node *son, bool direct)
    { // 如果是空树
        if (parent == nullptr && root == nullptr)
        {
            root = son;
            return true;
        }
        // 已经存在左或右子树
        if (isexist(parent, direct))
        {
            cout << "插入失败,已经存在左或右子树" << endl;
            return false;
        }
        if (direct)
            parent->left = son;
        else
            parent->right = son;
        return true;
    }
    void Insert(T data1, T data2, bool direct)
    {
        Node *son = new Node(data2);
        Node *parent = find_node(root, data1);
        if (Insert(parent, son, direct))
        {
            cout << "插入成功" << endl;
            treelen++;
        }
        else
            return;
    }
    /*
        @brief 销毁二叉树
    */
    void Destroy(Node *p)
    {
        if (p != nullptr)
        {
            Destroy(p->left);
            Destroy(p->right);
            delete p;
            p = nullptr;
        }
    }
    void Destroy()
    {
        Destroy(root);
        root == nullptr;
    }
    /*
        @brief
        已知先序遍历和中序遍历创建二叉树
    */
    void pre_increate(T *pre, T *in, int len)
    {
        treelen = len;
        pre_increate(root, pre, in, treelen);
    }
    void pre_increate(vector<T> pre, vector<T> in)
    {
        int left = 0;
        int right = in.size();
        treelen = right;
        root = pre_increate(pre, in, left, right);
    }
    Node *pre_increate(vector<T> pre, vector<T> in, int left, int right)
    {
        static int cnt = 0; // 静态指针可以表示递归的次数，并且可以再每次递归中移动。
        if (left >= right)
        {
            return nullptr;
        }
        Node *p;
        // int cnt = 0;
        // T value = pre[cnt++];
        // 先在前序中找到根，然后在中序中找到根，中序中根的左边即左子树，右边即右子树。
        // 递归进行的条件和二分是一样的，左区间小于右区间，在前序中遍历，在中序中找到和前序一样的，作为前序中节点的左子树，一直d递归到叶子结点就返回，再回溯的递归右子树。
        if (left < right)
        {
            T value = pre[cnt]; // 每次后移一次cnt
            int i = left;
            while (pre[cnt] != in[i] && i < right)
            {
                i++;
            }
            ++cnt;
            p = new Node(value);
            p->left = pre_increate(pre, in, left, i); // 第一次左区间不变，右区间会不断缩小，直到遍历完根的左子树
            p->right = pre_increate(pre, in, i + 1, right);
        }
        return p;
    }
    /*
        @brief 中后续遍历创建二叉树
    */
    void midpostcreate(vector<T> in, vector<T> post)
    {
        int left = 0;
        int right = post.size() - 1;
        root = midpostcreate(in, post, left, right);
    }
    Node *midpostcreate(vector<T> in, vector<T> post, int left, int right)
    {
        static int cnt = post.size() - 1; // 遍历后序的指针
        if (left >= right)
            return nullptr;
        Node *p;
        T value = post[cnt]; // 一开始指向根 然后每次往后递减
        //中后序创建和前中序创建并无太大区别，前面遍历指针的方式还是一样的
        int i = left;
        while (post[cnt] != in[i] && i < right)
            i++; // 第一次i = 3
        --cnt;
        p = new Node(value);
        // cout << p->data << " ";
        p->right = midpostcreate(in, post, i + 1, right);
        p->left = midpostcreate(in, post, left, i);
        return p;
    }
    /*
        @brief 二叉树前中后序遍历递归版
    */
    void preorder(Node *p)
    {
        if (p == nullptr)
        {
            return;
        }
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
    void preorder()
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        cout << "前序遍历结果为：" << endl;
        preorder(root);
        cout << endl;
    }
    void inorder(Node *p)
    {
        if (p == nullptr)
        {
            return;
        }
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
    void inorder()
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        cout << "中序遍历结果为：" << endl;
        inorder(root);
        cout << endl;
    }
    void postorder(Node *p)
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        if (p == nullptr)
            return;
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
    void postorder()
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        cout << "后序遍历结果为：" << endl;
        postorder(root);
        cout << endl;
    }
    /*
        @brief 层序遍历
    */
    void level_order()
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
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
    /*
        @brief 前中后续遍历非递归版，手动调用栈来存数据
        和层序遍历差不多
    */
    void pre_order()
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        cout << "前序遍历非递归版结果为" << endl;
        Node *p = root;
        stack<Node *> k;
        k.push(p);
        while (!k.empty())
        {
            p = k.top();
            k.pop();
            cout << p->data << " ";
            //
            // 按照递归的方法，前序遍历是把左子树都遍历完了才回溯的，回溯遍历右子树，但是用栈我们无法表达回溯，所以可以先把右子树压入栈底，后面再出栈
            if (p->right != nullptr)
            {
                k.push(p->right);
            }
            if (p->left != nullptr)
            {
                k.push(p->left);
            }
        }
        cout << endl;
    }
    void in_order()
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        cout << "中序遍历非递归版结果为" << endl;
        Node *p = root;
        stack<Node *> k;

        while (!k.empty() || p != nullptr)
        {
            while (p != nullptr)
            {
                k.push(p);
                p = p->left;
            }
            if (!k.empty())
            {
                p = k.top();
                cout << p->data << " ";
                k.pop();
                p = p->right;
            }
        }
        cout << endl;
    }
    void post_order()
    {
        if (root == nullptr)
        {
            cout << "empty tree" << endl;
            return;
        }
        cout << "非递归后续遍历为" << endl;
        Node *p = root;
        if (root == nullptr)
            return;
        stack<Node *> k;
        k.push(p);
        Node *lastpop = nullptr;
        while (!k.empty())
        {

            while (k.top()->left != nullptr)
            {
                k.push(k.top()->left);
            }
            while (!k.empty())
            {
                if (lastpop == k.top()->right || k.top()->right == nullptr)
                {
                    cout << k.top()->data << " ";
                    lastpop = k.top();
                    k.pop();
                }
                else if (k.top()->right != nullptr)
                {
                    k.push(k.top()->right);
                    break;
                }
            }
        }
        cout << endl;
    }
};