// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll fib(int n)
// {
//     return fib(n) * fib(n - 1);
// }
// // vector<int> kk;
// // int n;
// // void dfs(int u)
// // {
// //     if (u > n)
// //     {
// //         for (auto i : kk)
// //             cout << i << " ";
// //         cout << endl;
// //         return;
// //     }
// //     kk.push_back(u);
// //     dfs(u + 1);
// //     kk.pop_back();
// //     dfs(u + 1);
// //     return;
// // }
// int a[50]; // 0
// bool f[50];
// int n, m;
// void dfs(int u) // start 记录节点
// {
//     if (u > m)
//     {
//         for (int i = 1; i <= m; i++)
//         {
//             cout << a[i] << " ";
//         }
//         cout << endl;
//         return;
//     }
//     for (int i = a[u - 1] + 1; i <= n; i++)
//     {
//         a[u] = i;
//         dfs(u + 1);
//         // u-1
//     }
//     return;
// }
// int main()
// {
//     // cin >> n >> m;
//     // dfs(1);

//     // int n;
//     // string s;
//     // cin >> n;
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cin >> s;

//     //     if (s[0] == 'y' || s[0] == 'Y')
//     //     {
//     //         if (s[1] == 'e' || s[1] == 'E')
//     //         {
//     //             if (s[2] == 's' || s[2] == 'S')
//     //             {
//     //                 cout << "YES" << endl;
//     //                 continue;
//     //             }
//     //         }
//     //     }
//     //     else
//     //     {
//     //         cout << "NO" << endl;
//     //         continue;
//     //     }

//     //     cout << "NO" << endl;
//     // }
//     // bool st[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//     // int n, m;
//     // string s;
//     // cin >> n;
//     // while (n--)
//     // {
//     //     int cnt = 0;
//     //     cin >> m;
//     //     cin >> s;
//     //     for (int i = 0; i < s.length(); i++)
//     //     {
//     //         if (st[s[i]] == false)
//     //         {
//     //             cnt += 2;
//     //             st[s[i]] = true;
//     //         }
//     //         else
//     //         {
//     //             ++cnt;
//     //             st[s[i]] = false;
//     //         }
//     //     }image.pngl;
//     // }
//     // int n, t;
//     // cin >> t;
//     // while (t--)
//     // {
//     //     string s;
//     //     cin >> n >> s;.-
//     //     set<char> ss;
//     //     for (auto x : s)
//     //         ss.insert(x);
//     //     cout << ss.size() * 2 + s.size() - ss.size() << endl; //因为set去重，只出现一次字母，x2，然后加上所有的字符，再减去已经x2的就行了
//     // }

//     // vector<int> a = {1,2,3};
//     // a.erase(a.begin()+2);
//     // for(int i = 0;i<a.size();i++)
//     //     cout<<a[i]<<" ";

//     // set<int> kk;
//     // int n, k, sum = 0;
//     // cin >> n >> k;
//     // int m[n + 1];
//     // for (int i = 1; i <= n; i++)
//     //     cin >> m[i];
//     // for (int i = 1; i <= 2 * k; i += 2)
//     // {
//     //     if (i == 2*k)
//     //         break;
//     //     sum += m[i + 1] - m[i];
//     // }
//     // cout << sum;
//     // int n, m;

//     // cin >> n;
//     // while (n--)
//     // {
//     //     cin >> m;
//     //     int cnt = 0;
//     //     int a[m + 5];
//     //     for (int i = 1; i <= m; i++)
//     //     {
//     //         cin >> a[i];
//     //     }
//     //     sort(a + 1, a + m + 1);
//     //     int minn = 1e9;
//     //     int minn1 = 0;
//     //     for (int i = 1; i <= m - 1; i++)
//     //     {
//     //         if (a[i] == a[i + 1] && a[i] == a[i - 1])
//     //         {
//     //             cout << "0" << endl;
//     //             break;
//     //         }
//     //         else if (a[i] < minn)
//     //         {
//     //             minn = a[i];
//     //         }
//     //         else if (a[i] == a[i + 1])
//     //         {
//     //             cnt = 1;
//     //             minn1 = a[i + 2] - a[i + 1];
//     //             cout << minn1 - minn << endl;
//     //             break;
//     //         }
//     //         else if (a[i - 1] != a[i] && a[i] != a[i + 1] && a[i + 1] != a[i- 1] )
//     //         {
//     //             int ans = a[i + 1] - a[i - 1];
//     //             cout << ans << endl;
//     //             break;
//     //         }
//     //     }

//     // }

//     //  Read()
//     // {
//     //     int x,len,a;
//     //     scanf("%d",&x);
//     //     len = x;
//     //     Node p;
//     //     p = (PtrToNode)malloc(sizeof(Node));
//     //     for(int i = 0;i<len;i++)
//     //     {
//     //         scanf("%d",&a);
//     //         p->Data = a;
//     //         p = p->next;
//     //     }
//     //     p->next = null;
//     //     return p;
//     // }
//     // Print(List L)
//     // {
//     //    Node p;
//     //     p = (PtrToNode)malloc(sizeof( Node));
//     //     while(p->next!=null)
//     //     {
//     //         printf("%d ",p->Data);
//     //         p = p->next;
//     //     }
//     // }
//     int *p1, *p2, *p3;
//     p1 = new int[10];
//     p2 = p1; //对p2 操作就是对p1操作,p2指向了另一个指针，但是原本的已经改变了的p1，是不会一起变的
//     p2[0] = 1;
//     p2 = p3;
//     for (int i = 0; i < 4; i++)
//     {
//         cout << p1[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < 4; i++)
//     {
//         cout << p2[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < 4; i++)
//     {
//         cout << p3[i] << " ";
//     }
// }
#include <bits/stdc++.h>
using namespace std;
// int minn_p, max_p;
// int maxsum(int *a, int n)
// {
//     int maxx = -1e8, cur_sum = 0, temp = 0;
//     minn_p = 0, max_p = n - 1;
//     for (int i = 0; i < n; i++)
//     {
//         cur_sum += a[i];
//         if (cur_sum < 0)
//         {
//             cur_sum = 0;
//             temp = i + 1; // 如果该数小于0 那么可以直接跳过，因为小于0的只会减小总和，然后temp跳到下一个元素。
//         }
//         else if (cur_sum > maxx)
//         {
//             maxx = cur_sum;
//             minn_p = temp;
//             max_p = i;
//         }
//     }
//     if (maxx < 0)
//         return 0;
//     return maxx;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n + 5];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     cout << maxsum(a, n) << " " << a[minn_p] << " " << a[max_p];
// }

// vector<pair<int, int>> a(100);
// vector<pair<int, int>> b(100);
// vector<pair<int, int>> c(100);
// vector<pair<int, int>> d(100);
// int main()
// {
//     int m, n, k = 0;
//     cin >> m;
//     for (int i = 1; i <= m; i++)
//         cin >> a[i].first >> a[i].second;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> b[i].first >> b[i].second;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             ++k;
//             c[k].first = a[j].first * b[i].first;    // 3 * 5  -5*5 6*5 -2*5
//             c[k].second = a[j].second + b[i].second; // 4 + 20
//             // 15 24
//         }
//     }
//     for (int i = 1; i <= k; i++)
//     {
//         cout << c[i].first << " " << c[i].second << " ";
//     }
//     cout << endl;
// }

int main()
{
    // int n;
    // cin >> n;
    // int m;
    // int m1, n1;
    // vector<int> kk;
    //     while (cin >> m)
    //     {
    //         kk.push_back(m);
    //     }

    // sort(kk.begin(), kk.end() + 1);
    // for (int i = 1; i <= kk.size(); i++)
    // {
    //     cout << kk[i] << " ";
    //     if (kk[i] == kk[i + 1] || kk[i - 1] == kk[i])
    //     {
    //         n1 = kk[i];
    //     }
    //     else if (kk[i] + 1 != kk[i + 1] || kk[i] - 1 != kk[i - 1])
    //         m1 = kk[i] + 1;
    // }
    // cout << m1 << " " << n1;

    // int m, n, v, w, sum_min = 0, sum_max = 0;
    // cin >> m >> n;
    // int maxx = -1e8, mainn = 1e8;
    // for (int i = 1; i <= m; i++)
    // {
    //     cin >> v >> w;
    //     sum_min+=v;
    // }
    
}