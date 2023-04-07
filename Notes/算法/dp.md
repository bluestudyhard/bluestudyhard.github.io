[toc]

# dp 的核心思想

- dp 的本质,其实就是吧复杂的问题分成一个一个简单的子问题，从而寻找解的过程。
- 道理上来说好像很简单，可是捏，往往在列状态转移方程的时候啥都列不出来。
- 这时候要提到一个 dp 的无序性

### 简单的 dp 问题

- 先从简单的 dp 引入
- 线性 dp 顾名思义就是在线性程度上的，dp 的状态转移方程比较好找，一般用 1 2 个数组就能解决。
- 例 洛谷三角形

```C++ {.line-numbers}
 int a[1005][1005] = {0};
 int dp[1005][1005];
 int maxx = 0;
 int i,j,k,n,m;
 int main()
 {
     int n;
     cin>>n;
     for(i = 1;i<=n;i++)
         for(j = 1;j<=i;j++)
         cin>>a[i][j];
     for(i = 1;i<=n;i++)
         for(j = 1;j<=i;j++)
         {
             dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
             if(dp[i][j]>maxx)
                 maxx = dp[i][j];
         }
     cout<<maxx;
 }
```

### 01 背包问题

```C++ {.line-numbers}

```
