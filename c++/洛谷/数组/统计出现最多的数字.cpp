#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, a[1000], sum = 0, p, maxx = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
    {
        sum = 0;                 //每次从0算起
        for (j = n; j >= 0; j--) //从最后一个往前找，
        {
            if (a[i] == a[j]) //想等就标记加一
                sum++;        //假如有2个4,5个3，那么他们对应的sum是2,5，5比2大，然后，每一次读到3时，
                //p就会重新标记3，而且不会有数的次数大于他，所以出现最多的自然为3
            if (sum > maxx)
            {
                maxx = sum; //找到出现次数最多的
                p = a[i];   //然后这个出现次数最多的数字，用p标记
            }
        }
    }
    cout << p << " " << maxx;
}
//附一个，每输出3个换行，而且尾数不带空格的方法
    for (i = 1; i < n; i++)
    {
        cout<<c[i];
        if (i%3==0)
            cout<<endl;
        else if (i<=n-2)
            cout<<" ";
    }
