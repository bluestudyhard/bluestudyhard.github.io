#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int a[26] = {0};
	int b=0;
	getline(cin, s); //输入有空格的字符串
	for (int i = 0; i < s.size(); i++)
	{		if(s[i]>='A'&&s[i]<='Z'&&a[s[i]-'A']==0)//标记字符串
		{
			cout <<s[i];//满足条件的大写先输出
					a[s[i]-'A']=1;//将输出过的大写字符设为1，这样剩下的
					b = 1;
		}
	}
	if (b == 0)
		printf("Not Found");
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int i;
	getline(cin, s);
	for (i = 0; i < s.size()-1; i++)
	{
		if (isupper(s[i]))
			s[i] = tolower (s[i]);
		else if (islower(s[i]))
			s[i] = toupper (s[i]);
		cout << s[i];
	}
}