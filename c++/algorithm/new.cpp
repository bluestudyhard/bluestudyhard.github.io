#include <bits/stdc++.h>
using namespace std;
int cnt[11], c = 0;
bool fl = false;
int main()
{
    for (int i = 0; i <= 9; i++)
        cnt[i] = 2021;
    while (!fl && ++c)
    {
        int t = c;
        while (t)
            cnt[t % 10]--, t /= 10;
        for (int i = 0; i <= 9; i++)
            if (cnt[i] < 0)
            {
                fl = true;
                break;
            }
    }
    printf("%d", c - 1);
    return 0;
}
