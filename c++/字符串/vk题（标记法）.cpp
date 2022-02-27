#include <iostream> //memset(a,0,sizeof(a)); menset初始化
using namespace std;
int main()
{
    int n, i, j, ans = 0;
    string s;
    cin >> n >> s;
    for (i = 0; i < n - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            ans++;
            s[i] = 'v';//找到了就标记为别的，以防重复判断
            s[i + 1] = 'k';
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        if (s[i + 1] == s[i])
        {
            ans++;
            cout << ans;
            break;
        }
    }
    cout << ans;
}