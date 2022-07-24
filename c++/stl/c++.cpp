#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
int st(int a,int b,int c)
{   int kk[10] = {0};
    while(a)
    {
        kk[a%10]++;
        a/=10;
    }
    while(b)
    {
        kk[b%10]++;
        b/=10;
    }
    while(c)
    {
        kk[c%10]++;
        c/=10;
    }
    for(int i = 1;i<=9;i++)
    {
        if(kk[i]!=1)
        return 0;
    }
    return 1;
}
int main()
{
    for(int i = 1000;i<=9999;i++)
        for(int j = 1;j<=100;j++)
            {
                int k = i/j;
                if(st(i,j,k)&&i%k==0)
                {
                    printf("%d = %d x %d",i,j,k);
                    cout<<endl;
                }
            }
}
*/
/*ll fpow(ll a, ll b)
{
  ll sum = 1;
  while(b)
  {
      if(b&1)
      {
          sum*=a;
      }
      a*=a;
      b>>=1;
  }
  return sum;
}
int main()
{
  cout<<fpow(2,3);
}*/

bool v[10000];
int n, m, i, j, sum = 0, k;
bool isprime(int n)
{
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int a[25];
long long ans;
void dfs(int m, int sum, int startx)
{   int i;
    if (m > k)
    {
        if (isprime(sum))
            ans++;
        return;
    }
    cout << "m = " << m << " sum = " << sum << " i = " << i << endl;
    for (i = startx; i <= n; i++)
    {
        cout << "m = " << m << " sum = " << sum << " i = " << i << endl;
        dfs(m + 1, sum + a[i], i + 1);
        //cout << "m = " << m << " sum = " << sum << " i = " << i << endl;
    }
    return;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(1, 1, 1);
    printf("%d\n", ans);
    return 0;
}
