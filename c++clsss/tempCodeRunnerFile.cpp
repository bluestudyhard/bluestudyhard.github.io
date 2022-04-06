#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max = 1e8 + 10;
int minn = Max;
int n, m;
bitset<Max> st;
int prime[Max];
bool pp[Max];
int a[40][40];
int main()
{
    cin >> n;
    int a[n + 5];
    int i, j, cnt = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        pp[i] = 1;
    }
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            for (int k = n; k >= 1; k--)
            {
                if (a[i] + a[j] == a[k] && i != j&&pp[k]==1)
                {
                    cnt++;
                    pp[k]=0;
                    break;
                }
            }

    cout << cnt;
}
