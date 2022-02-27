#include <bits/stdc++.h> //使用迭代实现(找鸭子例题)
using namespace std;
int main()
{
    int n, m = 0, a1 = 1, a2 = 1, a3 = 0;
    cin >> n;
    if (n == 1)
        m = 1;
    else
        for (m = 2; a3 < n; m++)
        {
            a3 = a1 + a2;
            a1 = a2;
            a2 = a3;
        }
    cout << m;
}
#include <bits/stdc++.h> 求，斐波那契数列的值
using namespace std;
int f(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int x1 = 1, x2 = 1, x3 = 0;
    for (int i = 3; i <= n; i++)
    {
        x3 = x1 + x2;
        x1 = x2;
        x2 = x3;
    }
    return x3;
}
int main ()
{
    int n;
    cin>>n;
    cout<<f(n);
}


判断斐波那契,可以判断是第几个斐波那契数
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
    return fib(n - 1) + fib(n - 2);
}