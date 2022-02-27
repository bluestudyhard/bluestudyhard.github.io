#include <bits/stdc++.h>
using namespace std;
long long pow(int a, int b)
{
    long long sum1 = 1;
    for (int i = 1; i <= b; i++)
    {
        sum1 *= a;
    }
    return sum1;
}
int main()
{
    int n, i, j, cnt = 0, a;
    long long sum = 0;
    cin >> n;
    for (i = pow(10, n - 1); i <= pow(10, n)-1; i++)
    {
        a = i;
        sum = 0;
        for (j = 1; j <= n; j++)
        {
            cnt = a % 10;
            a /= 10;
            sum += pow(cnt, n);
        }
        if (i == sum)
            cout << i << endl;
    }
}