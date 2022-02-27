#include <stdio.h>
#include <math.h>
int IsAutomorphic(int x)
{
    int i, s, f, cnt = 0, p;
    if (x == 1 || x == 0)
        return 1;
    if (x >= 2)
    {
        s = x * x;
        while (s != 0)
        {
            s /= 10;
            cnt++;
        }
        p = pow(10, cnt - 1);
        s = x * x;
        if (s % p == x)
            f = 1;
        else
            f = 0;
    }
    return f;
}