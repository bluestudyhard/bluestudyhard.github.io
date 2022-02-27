#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> k;
    int n, i, m;
    string a;
    scanf("%d", &n);
    while (n--)
    {
        cin >> a;
        if (a == "insert")
        {
            cin >> m;
            k.push_front(m);
        }
        else if (a == "deleteFirst")
            k.pop_front();
        else if (a == "deleteLast")
            k.pop_back();
        else if (a == "delete")
        {
            cin >> m;
            for (auto i = k.begin(); i != k.end(); i++)
                // lower_bound 并不适用于list int pos = lower_bound(k.begin(),k.end(),m);
                if (*i == m)
                {
                    k.erase(i);
                    break;
                }
        }
        for (auto i : k)
            cout << i << " ";
        cout << endl;
    }
    for (auto i : k)
        cout << i << " ";
}