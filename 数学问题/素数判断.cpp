#include <bits/stdc++.h> //（循环大众版）(效率低，t长)
using namespace std;
int main()
{
    int n, m, sum = 0, i, j, sum1 = 0;
    cin >> n >> m;
    for (j = n; j <= m; j++)
    {
        for (i = 2; i < j; i++) //从2 开始一直除到这个数，看是不是只有1和他自己。
        {
            if (j % i == 0)
                break;
        }
        if (j == i) //表示，除了1和他自己，没数能除了
        {
            sum++;
            sum1 += j;
        }
    }
    printf("%d %d", sum, sum1);
}
int prime(int p)
{
    int i;
    if (p < 2)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (p % i == 0)
            return 0;
    }
    return 1;
}
int main() 25 = 22 + 3
{
    for (i = m;i<=n;i++)
        for (j = 1;j<m/2;j++)
            if (p(i)&&p(j)&&)

    
}
真素数判断
#include <stdio.h>
#include <math.h>
int prime(int p)
{
    int i;
    if (p < 2)
        return 0;
    for (i = 2; i <= sqrt(p); i++)
    {
        if (p % i == 0)
            return 0;
    }
    return 1;
}
int PrimeSum(int m, int n)
{
    int sum = 0;
    for (int i = m; i <= n; i++)
    {
        if (prime(i))
            sum += i;
    }
    return sum;
}
哥德巴赫猜想
例 25 = 22 + 23；
#include <bits/stdc++.h>
        using namespace std;
int p(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 2; i <= N / 2; i++)
    {
        int j = N - i; // j永远比i大
        if (p(i) && p(j))
        {
            cout << N << " = " << i << " + " << j << endl;
            break;
        }
    }
    return 0;
}