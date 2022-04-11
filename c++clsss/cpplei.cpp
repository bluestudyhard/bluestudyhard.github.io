#include <bits/stdc++.h>
using namespace std;
/*各类模板*/
typedef long long ll;
const int maxx = 1e8 + 10;
/* 高精+ */
/*vector<int> add(vector<int> &a, vector<int> &b)
{
    if (a.size() < b.size())
        return add(b, a);
    vector<int> c;
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (i < b.size())
            sum += b[i];
        c.push_back(sum % 10);
        //    2468
        sum /= 10;
    }
    if (sum)
        c.push_back(sum);
    return c;
}*/
/* 高精x*/
/*vector<int> muti(vector<int> &a, vector<int> &b)
{
    if (a.size() < b.size())
        return muti(b, a);
    vector<int> c;
    int sum = 0;
    for (int i = 1; i < a.size(); i++)
        for (int j = 1; j < b.size(); j++)
            c[i + j - 1] += a[i] * b[j];
    for (int i = 0; i < a.size() + b.size(); i++)
    {
        if (c[i] > 9)
        {
            c[i + 1] += c[i] % 10;
            c[i] /= 10;
        }
    }
    while (c.size() > 1 && c.back() == 0) //第一位为0的情况
        c.pop_back();
    return c;
}
int main()
{
    vector<int> a, b;
    string n, m;
    n = ' ' + n;
    m = ' ' + m;
    int i;
    cin >> n >> m;
    for (i = 1; i < n.length(); i++)
        a[i] = n[n.length() - i] - '0';
    for (i = 1; i < m.length(); i++)
        b[i] = m[m.length() - i] - '0';
    vector<int> c = muti(a, b);
    for (int i = c.size(); i >= 1; i--)
        cout << c[i];
}*/
int path[10], i, j;
bool s[10]; //默认为0
int n;
void dfs(int u) // u代表访问的层数
{               /*1.终止条件*/
    if (u == n) //返回条件，一直遍历到最后一层，返回输出
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", path[i]);
        }
        cout << endl;
        return; //
    }
    /*遍历候选节点*/
    for (i = 1; i <= n; i++)
    {
        if (!s[i]) // if(s[i]==false)
        {
            path[u] = i; //第一层赋值
            s[i] = true; //标记为有
            dfs(u + 1);
            s[i] = false; //重新回溯的时候，把数字从新的开始，比如1轮完了轮2
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
}