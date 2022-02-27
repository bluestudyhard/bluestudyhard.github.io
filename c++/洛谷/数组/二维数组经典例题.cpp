#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n, i, j, k = 0;
    int a[1001][3], sum[1001];
    cin >> n;
    for (i = 0; i < n; i++)     //遍历行
        for (j = 0; j < 3; j++) //遍历列，因为只有3个成绩，所以每次都输入3列
        {
            cin >> a[i][j];    //输入行列的值，数组的输入，本质上就是将数存在数组里，默认从第0个开始，你输入a[i]表示在第一层循环时，你输入的数存入了数组的第一个里面。
            sum[i] += a[i][j]; //用另一个数组储存和
        }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            if (abs(a[i][0] - a[j][0]) <= 5 && abs(a[i][1] - a[j][1]) <= 5 && abs(a[i][2] - a[j][2]) <= 5 && abs(sum[i] - sum[j]) <= 10)
                k++;
        }
    printf("%d", k);
}
