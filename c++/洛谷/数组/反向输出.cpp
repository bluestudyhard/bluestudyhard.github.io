#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b[1000] = {0}, i, j;
	cin >> n;
	if (n==0)
	cout<<"0";
	for (i = 1; n != 0; i++)
	{
		a = n % 10;
		b[i] = a;
		n /= 10;
	}
	for (j = i-1; j>=1; j--)
	{	
		printf("%d ", b[j]);
	}
}