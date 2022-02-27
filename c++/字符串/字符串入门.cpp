#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;//string a== int a[]={};
	cin >> a;
	for (int i = 1; i <=a.size(); i++)//a.size()=a.length()表示字符串的个数，长度
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
	}
	cout << a;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			s[i]++;
			if (s[i] > 'z')
				s[i] = 'a';//涉及ascll码的，圆环的z-a的都这样用，回到a
		}
	}
	cout << s;
	return 0;
}