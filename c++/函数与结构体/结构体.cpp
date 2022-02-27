#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int yw, sx, yy, zf;
} a[10001];//存放各种数据，相当于一个n维数组
int main()
{
    int n, i, j, sum = -1;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].yw >> a[i].sx >> a[i].yy;//直接读入，用.带上面的函数
        a[i].zf = a[i].yw + a[i].sx + a[i].yy;
    }
    for (i = 0; i < n; i++)
        if (a[i].zf > sum)
        {
            sum = a[i].zf;
            j = i;
        }

    cout << a[j].name << " " << a[j].yw << " " << a[j].sx << " " << a[j].yy;
}
/*#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    double gz, fd, zc, sf;
} a[10000];
int main()
{
    int n, i;
    cin >> n;

        for (i = 1; i <= n; i++)
        {
            cin >> a[i].name >> a[i].gz >> a[i].fd >> a[i].zc;
            a[i].sf = a[i].gz + a[i].fd - a[i].zc;
        }
        for (i = 1;i<=n;i++)
            printf("%s %.2f\n",a[i].name.c_str(),a[i].sf);
}