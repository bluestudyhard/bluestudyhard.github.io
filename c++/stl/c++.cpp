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
                if (*i == m)
                {
                    k.erase(i);
                    break;
                }
        }
    }
    int it = 0;
    for (auto i : k)
    {   if(it++)
        cout <<" ";
        cout << i;
    }
    cout<<endl;
}