#include <iostream>
using namespace std;
int main()
{
    int l, m, i, j, b, c, sum = 0;
    cin >> l >> m;
    int a[l + 1] = {0};

    for (i = 1; i <= m; i++) //砍树，被砍掉的树变成1
    {
        cin >> b >> c;
        for (j = b; j <= c; j++)
            a[j] = 1;
    }
    for(i = 0; i <= l; i++)
        if(a[i] == 0) // 判断，0为有树的情况
            sum++;
    printf("%d", sum);
}
