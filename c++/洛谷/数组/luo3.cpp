#include <iostream>
using namespace std;
int main()
{
    int i, j, n, a[110];
    cin >> n;
    a[0] = n;
    for (i = 1; n != 1; i++)
    {
        if (n % 2 == 0)
            n = a[i] = n / 2;
        else
            n = a[i] = n * 3 + 1;
        
    } 
    for (j = i - 1; j >= 0; j--)
        printf("%d ", a[j]);
}