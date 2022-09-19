[toc]

### dfs 暴力枚举，排列问题，组合问题

- 暴力枚举排列的题目一般是问:xx 东西在
```C++ {.line-numbers}
/*stl里的全排列*/
要先预先sort好序
int main()
{   int i,j;
    int a[3] = {1,2,3};
    do
    {
        cout << a[0] << " " << a[1] << " " << a[2] << " ";
        cout << endl;
    } while (next_permutation(a, a + 3));
}

用dfs实现
int path[10], i, j;
bool s[10]; //默认为0
int n;
void dfs(int u)//u代表访问的层数
{   /*1.终止条件*/
    if(u==n)//返回条件，一直遍历到最后一层，返回输出
    {
        for(i = 0;i<n;i++)
            {
                printf("%d ",path[i]);
            }
            cout<<endl;
            return;//
    }
    /*遍历候选节点*/
        for(i = 1;i<=n;i++)
        {
            if(!s[i])//if(s[i]==false)
            {
                path[u] = i;//第一层赋值
                s[i] = true;//标记为有
                dfs(u+1);
                s[i] = false;//重新回溯的时候，把数字从新的开始，比如1轮完了轮2
            }
        }
}
```
- 实现几个数里面选几个数的组合
- 例题[洛谷P1157 组合的输出](https://www.luogu.com.cn/problem/P1157)
```C++ {.line-numbers} 
void dfs(int u)
{
   #include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000], j, n, k, sum, m;
bool v[1000];
void dfs(int u)
{ /*终止条件*/
    int i;
    if (u > m)
    {
        for (i = 1; i <= m; i++)
            cout<<setw(3)<<a[i];//c++中打间隔的方式
        cout << endl;
        return;
    }
    for (i = a[u - 1] + 1; i <= n; i+++)
    {
        a[u] = i; // 1 25
        dfs(u + 1);
    }
}
int main()
{
    cin >> n >> m;
    dfs(1);
}
}
```

### 经典的迷宫问题

#### 找最短路问题

- 解题思路,比如在一个 10x10 的迷宫里面，起始坐标是(0,0),重点是(5,4),要求找到一条最短的路
- ![img](img/mi.png)
- 如同所示,那么要想实现这玩意的话,就得用回溯了,在一次次的走和实验中,发现最短路

```C++ {.line-numbers}
int x, y, x1, y1, step = 0;
int minn = 999999;
int a[100][100]; // 1表示空地可走,2表示有障碍物.
int v[100][100]; // 0 表示未访问,1表示已访问,全局变量默认0
void dfs(int x, int y, int step)
{
    if (x == x1 && y == y1)
    {
        if (step < minn)
            minn = step;
        return; //开始回溯
    }
    /*顺时针运动,要明白,因为二维数组,向右移动改变的是竖列,即y在变
    /*right*/
    //判断能不能往右走
    if (a[x][y + 1] == 1 && v[x][y + 1] == 0)
    {
        v[x][y + 1] = 1; //走过就标记已访问
        dfs(x, y + 1, step + 1);
        v[x][y + 1] = 0; //等到回溯的时候,就可以用了，因为是往下走,那么你走过的点,标记为未走过就行了
    }
    /*down*/
    if (a[x + 1][y] == 1 && v[x + 1][y] == 0)
    {
        v[x + 1][y] = 0;
        dfs(x + 1, y, step + 1);
        v[x + 1][y] = 1;
    }
    /*left*/
    if (a[x][y - 1] == 1 && v[x + 1][y - 1] == 0)
    {
        v[x][y - 1] = 0;
        dfs(x, y - 1, step + 1);
        v[x][y - 1] = 1;
    }
    /*up*/
    if (a[x - 1][y - 1] == 1 && v[x - 1][y - 1] == 0)
    {
        v[x - 1][y - 1] = 0;
        dfs(x - 1, y - 1, step + 1);
        v[x - 1][y - 1] = 1;
    }
    return;
}
int main()
{
    int m, n;
    int xstart, ystart;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    cin >> xstart >> ystart >> x1 >> y1;
    dfs(xstart, ystart, 0);
    cout << minn;
}
```

####排列选数问题
思路：我们要明白，我们想实现什么，我们要实现的是，将 n 个数中选 m 个数，然后让他们进行排列，不能有重复的数字。2.怎么避免选重复的数字，

```C++ {.line-numbers}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool v[10000];
int n, m, i, j, sum = 0,k;
bool isprime(int n)
{
   for (i = 2; i <= sqrt(n); i++)
   {
      if (n % i == 0)
         return false;
   }
   return true;
}
int a[25];
long long ans;
void dfs(int m, int sum, int startx)
{   //边界条件
   if (m == k)
   {
      if (isprime(sum))
         ans++;
      return;
   }
   for (int i = startx; i < n; i++)
      dfs(m + 1, sum + a[i], i + 1);
   return;
}
int main()
{
   scanf("%d%d", &n, &k);
   for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
   dfs(0, 0, 0);
   printf("%d\n", ans);
   return 0;
}

```

#### dfs 标准模版题

- 对于这种题目，我的理解能力比较难以理解，就是为什么递推，一定要回溯
- 此类题目就是一个很近的
- 题目链接

```C++ {.line-numbers}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool v[10000];
int n, m, i = 0, j, sum = 1, sum1, k;
int minn = 999999999;
int a[10000], b[10000];
void dfs(int u)
{
    if (u == n)
    {
        return;
    }
    else
    {
        sum *= a[u];
        sum1 += b[u];
        minn = min(abs(sum - sum1), minn);
        //cout << "minn shang : " << minn << endl;
        //cout<<"sum:shang  " <<sum << " " << sum1 << endl;
        //cout <<"u = " <<u<<endl;
        dfs(u + 1);
        sum /= a[u];
        sum1 -= b[u];
        //cout <<"xia: " <<sum << " " << sum1 << endl; 
        dfs(u+1);
    }
    if(sum1==1&&sum==0)
        return;
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    dfs(0);
    cout << minn;
}
```
