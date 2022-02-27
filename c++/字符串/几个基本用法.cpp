#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s, s1, s2,d,s3;
	int n, i, j, a, b, c, e, f;
	cin >> n >> s;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> s1;
			s = s + s1;//string 直接相加
			cout << s << endl;
		}
		if (a == 2)
		{
			cin >> b >> c;
			d = s.substr(b, c);//截取 从b开始截取c
			s = d;
			cout << s << endl;
		}
		if (a==3)
		{	cin>>e>>s2;
			s = s.insert(e,s2);//插入
			cout<<s<<endl;
		}
		if (a==4)
		{	cin>>s3;
			if(s.find(s3)<s.size())
				cout<<s.find(s3)<<endl;//查找
			else
			cout<<-1<<endl;
		}
	}

}