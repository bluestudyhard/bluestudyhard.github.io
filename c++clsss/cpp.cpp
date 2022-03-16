#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void a(int n)
{
    if (n == u)
        return;
    for (int i = 1; i <= n; i++)
    {
        a(n + 1);
        cnt++;
    }
}
int main()
{
    int u;
    a(0);
}
