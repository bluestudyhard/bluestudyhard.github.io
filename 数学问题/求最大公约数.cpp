#include <stdio.h>
int gcd(int a, int b)
{                                        // b = a%b;
    return (b == 0) ? a : gcd(b, a % b); //如果a<b的话一模就变成了ba，所以不用做先导判断
}
/*面对大数的最小公倍数*/
int main()
{
    ll a, b;
    cin >> a >> b;
    ll c;
    c = __gcd(a, b);
    cout << (a / c) * (b / c) * c;
}
int bei(int x, y) // 最小公倍数 等于两个数相乘 / 这两个数的最大公约数
{
    int temp, i;
    if (x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    for (i = y; i > 0; i++)
        if (i % x == 0 && i % y == 0)
            break;
    return i;
}

#include <stdio.h>
int gcd(int x, int y)
{
    int c;
    while (y != 0)
    {
        c = x % y;
        x = y; //辗转来相除
        y = c;
    } //原理，以12 4 为例 c = 0，表明，4可以被整除，那么4就是最大公约数。
    // 以 6 4 为例 6%4 = 2；
}
int gb(int x, int y)
{
    int temp;
    if (x < y)
    {
        x = t;
        x = y;
        y = t;
    }
    for (int i = x; i >= 0; i++)
    {
        if (i % x == 0 && i % y == 0)
            break;
    }
    return i;
}
