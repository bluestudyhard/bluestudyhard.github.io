#include <iostream>
using namespace std;
int main()
{
    int n, i, j, m, k, sum = 0, a[34] = {0}, b[34] = {0};
    cin >> n;
    for (i = 1; i <= 7; i++)
    {
        cin >> m;
        a[m] = 1;
    }
    for (i = 1; i <= n;i++)
    {
        sum = 0;
        for (j = 1; j <= 7; j++)
        {
            cin >> m;//重新输入回数组，看有没有与原数组重合的
            if (a[m] == 1)//如果重合，标记
                sum++;
        }
        b[sum]++;
    }
    for (i = 7; i >= 1; i--)
        printf("%d ", b[i]);
}
