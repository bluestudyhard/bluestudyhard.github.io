#include <bits/stdc++.h>
using namespace std;
int a[500050], b[50050], c[50050] = {0};
int len = 1, i, j;
void f(int n)
{
    a[1] = 1;
    b[1] = 2;
    for (i = 3; i <= n; i++)
    {
        for (j = 1; j <= len; j++)
            c[j] = a[j] + b[j];
        for (j = 1; j <= len; j++)
        {
            if (c[j] > 9)
            {
                c[j + 1] += c[j] / 10;
                c[j] %= 10;
                if (j + 1 > len)
                    len++;
            }
        }
        for (j = 1; j <= len; j++)
        {
            a[j] = b[j];
            b[j] = c[j];
        }
    }
}
int main()
{
    int n;
    cin >> n;
    if (n < 3)
    {
        cout << n;
        return 0;
    }
    f(n);
    for (i = len; i >= 1; i--)
        cout << c[i];
}