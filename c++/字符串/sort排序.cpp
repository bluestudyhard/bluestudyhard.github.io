#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s[10000];
    int i, l;
    cout << "After sorted:" << endl;
    for (i = 0; i < 5; i++)
    {
        cin >> s[i];
    }
        sort(s,s+i);//sort(s,s+a);
    for (i = 0; i < 5; i++)
    {
        cout << s[i] << endl;
    }
}
