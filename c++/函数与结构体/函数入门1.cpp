#include <bits/stdc++.h>
using namespace std;
double s(double x1, double x2, double y1, double y2)//调用函数直接函数名称加括号
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double s1 = s(x1, x2, y1, y2), s2 = s(x2, x3, y2, y3), s3 = s(x1, x3, y1, y3);
    double c = s1 + s2 + s3;
    printf("%.2lf", c);
}