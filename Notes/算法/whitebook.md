[toc]

# 这个 md 专门记录一些在白书写的题

## 第 x 章 栈

### 例题

```C++ {.line-numbers}
#include<bits/stdc++.h>
using namespace std;
int main()
{ //这题考的还是入栈出栈的基本运用，但是不同的是，这题要考虑转换字符为数字
  //而且一直很让我迷糊的点是，为什么，答案的没有push，容器里就有东西。然后
  //我发现了本题的核心，就是那个非字符，进栈。这样，就可以在读到+-*的时候
  //进行出栈操作，将这两个加起来，再入栈，然后以此类推，下一次-的时候，也是
  //只对-号的两个数字进行处理，然后再与原本处理好的，在栈底的数据运算。
  //最后在栈顶的，只有最终运算的结果
  //例 s: 1 2 + 3 4 - *  1 2 + 3 4 - 4 5 * + => -3  19
    char s; int a, b;
    stack<int> S;
    while ((s = getchar())!='\n')
    {
        if (s == '+'||s == '-' || s == '*')
        {
            b = S.top();S.pop();
            a = S.top();S.pop();
            if (s == '+')
            S.push(a + b);
            else if (s == '-')
            S.push(a - b);
           else  if (s == '*')
            S.push(a * b);
        }
        else if (isdigit(s))//核心
            S.push(s-'0');
    }
    printf("%d\n", S.top());
}
```

## 树

### 有根树

```C++ {.line-numbers}
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

```
