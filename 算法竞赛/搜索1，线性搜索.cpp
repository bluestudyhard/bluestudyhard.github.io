#include <bits/stdc++.h>
using namespace std;
int search(int a[], int word, int n)
{
	int i = 0;
	a[n] = word;
	while (a[i] != word) //including if ()
		i++;
	return i != n; // 表示，在i到最后一位前，一直输出
}
int main()
{
	int n, m, i, sum = 0, word, a[100001], number;
	cin >> n;
	for (i = 0; i < n; i++)
	{	cin>>a[i];
		//cin >> number;
		//a[i] = number;
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> word;
		if (search(a, word, n))//找到相同的数字标记，就加一
			sum++;
	}
	cout << sum;
}