这题的思路是，因为输入一个字符串，所以要从整块的去考虑，要理解string的本质
一开始做不出来是因为用了string数组。然后找最小值就先输入第一个，然后与后面一直比就行了
一直都是在string的层面上看的，这样排序的时候也是整体。
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    string s, smin;
    cin >> n;
    cin >> smin;//输入第一个字符串
    for (i = 0; i < n-1; i++)
    {
        cin >> s;
        if (s < smin)
            smin = s;
    }
    cout << "Min is: " << smin;
}
