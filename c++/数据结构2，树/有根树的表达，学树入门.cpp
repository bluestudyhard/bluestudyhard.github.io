//        0
//     1
//   2        4
//     3     5
//              6         10
//
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
struct tree
{
    int parent, left, right;
} t[MAX];
int d[MAX], n;
void print(int u)
{
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << t[u].parent << ", ";
    cout << "depth = " << d[u] << ", ";
    if (t[u].parent = -1)
        cout << "root, ";
    else if (t[u].left == -1)
        cout << "leaf, ";
    else
        cout << "internal node, ";
    cout << " [";
    for (i = 0, c = t[u].left; c != -1; i++, c = t[c].right)
    {
        if (i)
            cout << ", ";
    }
    cout << "]" << endl;
}
void getdepth(int u, int p) // u是节点编号，d是深度
{
    d[u] = p;
    if (t[u].left != -1)
        getdepth(t[u].left, p + 1); //儿子加深度
    if (t[u].right != -1)
        getdepth(t[u].right, p); //兄弟不加深度
}
int main()
{
    int x, y, k, b, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
        t[i].parent = t[i].right = t[i].left = -1;
    for (i = 0; i < n; i++)
    {
        cin >> x >> k; // k为儿子节点编号，x表示第几个节点。
        for (j = 0; j < k; j++)
        {
            cin >> y; //输入后续儿子的信息
            if (j == 0)
                t[x].left = y; //第1个节点编号，储存为左子
            else
                t[b].right = y; //成为上一个的兄弟

            b = y; //第一个节点编号完事后，让他成为下一个的兄弟
            t[y].parent = x;
        }
    }
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].parent == -1) //因为前面我们全部初始化了这棵树为-1，像样例第三行2 0这个值是是没有输入的，所以，为-1;
            root = i;
    }
    getdepth(root, 0);
    for (i = 0; i < n; i++)
        print(i);
}
