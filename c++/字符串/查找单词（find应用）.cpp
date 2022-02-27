#include <bits/stdc++.h>
using namespace std;
int main()
{
    string w, s; //words,sentence
    getline(cin, w);
    getline(cin, s);
    int p, i, j = 0, n = 0;
    s.insert(0, " ");
    w = w + ' ';
    w.insert(w.begin(), ' ');
    for (i = 0; i < w.size(); i++)
        w[i] = tolower(w[i]);
    for (i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    if (s.find(w) == string::npos//-1)
        cout << -1 << endl;
    else
    {
        while (s.find(w, n) != -1)
        {
            j++;
            n = s.find(w, n) + 1;//从第一位开始，找w，如果找到，统计加一，
        }
        cout << j << " " << s.find(w);
    }
}
