#include <iostream>
using namespace std;
int main()
{
    int n, m, b[10] = {0}, i, c, j;
    cin >> m >> n;
    for (i = m; i <= n; i++)
    {
        for (c = i; c; c /= 10)
        {
            j = c % 10;
            b[j]++; //
        }
    for (i = 0; i < 10; i++)
        printf("%d ", b[i]);
}
