#include <iostream>
using namespace std;
int main()
{
    int a, b, c, s[16000];
    int i, j, k, max=0, l;
    cin >> a >> b >> c;
    for (i = 1; i <= a; i++)
        for (j = 1; j <= b; j++)
            for (k = 1; k <= c; k++)
                s[i+j+k]++;
    for (i = 1; i <=a+b+c; i++)
        if (s[i] > s[max])
        {
            max = i;
        }else if(s[i]==s[max])
        {
            if(max>i) max=i;
        }
    printf("%d", max);
}
