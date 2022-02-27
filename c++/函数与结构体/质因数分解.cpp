/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    for (i = 2; i<n; i ++)
    {
        if (n % i == 0)
        {   
            printf("%d", n / i);
            break;
        }
    }
}
/*/
#include <bits/stdc++.h>//素数判断加质因数分解
using namespace std;//例100--2--50--25--5
int main()
{
    int n, i,sum=1;
    cin >> n;
    for (i = 2; i<n; i++)
    {    
        if (n % i == 0)
        {   n/=i;
            sum++;
             i = 2;
        }
    }
    printf("%d", sum);
}
//素数判断加素数求和
#include <stdio.h>
#include <math.h>
int prime(int p)
{
    int i;
    if (p<2)
        return 0;
    for (i = 2; i <= sqrt(p); i++)
    {
        if (p%i==0)
            return 0;
    }
    return 1;
}
int PrimeSum(int m, int n)
{   int sum = 0;
    for (int i = m; i <= n; i++)
    {
        if (prime(i))
            sum += i;
    }
    return sum;
}