#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k, sum[100];
    int a[25][25] = {0};
    cin >> n;
    for (i = 1; i <= n; i++)//给第一排最后一排赋值
    {
        a[i][i] = 1;
        a[i][1] = 1;
    }
    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }

for(int i=1;i<=n;i++) //打表方法
	{
		for(int j=1;j<=i;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

}



