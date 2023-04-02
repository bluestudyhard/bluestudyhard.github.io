#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100];
int fib(int n)
{
    a[0] = 1;
    a[1] = 1;
    if (n < 2)
    {

        return a[n];
    }

    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
/*经典的最优子结构问题*/
/*据钢条*/
/*递归版*/
// fish see you randon see kou heng

// int cut(int a[], int n)
// {
//     if (n == 0)
//         return 0;
//     int sum = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         sum = max(sum, a[i - 1] + cut(a, n - i)); // p3 = 1+1+1 1+5 8
//         // cut 的递归部分，得到的是所有情况的，sum的值，因为递归嘛，有一个压栈和回溯。
//     }
//     return sum;
// }
bool st[100]; // 标记选没选
int t[100];   // 存数
int n, k = 1;
void dfs(int n)
{
    /*递归终止条件*/
    if (k == n)
    {
        for (int i = 1; i <= k; i++)
            cout << t[i] << " ";
        cout << endl;
        return;
    }
    t[k] = 1;
    st[k] = true;
    dfs(k + 1);
}
int main()
{
}