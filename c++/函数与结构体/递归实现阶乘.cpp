#include <bits/stdc++.h>
using namespace std;
int re(int n) //定义一个函数
{
    if (n == 1) //第一位就是1
        return 1;
    return n * re(n - 1); //调用自己x自己，直到n
}
int main()
{
    int n;
    cin >> n;
    cout << re(n);
}
