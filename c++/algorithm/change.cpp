#include <bits/stdc++.h>
using namespace std;
/*
手动转2进制
*/
void changetwo(int n)
{
    vector<int> k;
    int m;
    while (n)
    {
        m = n % 2;
        k.push_back(m);
        n /= 2;
    }
    reverse(k.begin(), k.end());
    for (auto i : k)
    {
        cout << i;
    }
    cout << endl;
}

template <typename in, typename out>
out transf(const in &value)
{
    stringstream stream;                              // stringstream 输入流
    out result;                                       // 转换后输出的结果
    stream << value, stream >> result, stream.sync(); // 将想转换成字符串的输入流
                                                      // 转换成字符串
                                                      // 清空流
    return result;
}
/*
任意进制转10进制
*/
int changeten(string s, int radix)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            ans = ans * radix + (c - '0'); // 以2进制为例子 , 2转10 需要
        }
        else
            ans = ans * radix + abs(c - 'a') + 10;
    }
    cout << ans << endl;
    return ans;
}
/*
任意转16进制
*/
int change16(string s)
{
    int sum = 0;
    for (int i = s.size() - 1, j = 0; i >= 0; i--, j++)
    {
        if (isdigit(s[i]))
        {
            sum = sum + (s[i] - '0' * pow(16, i));
        }
        else
            sum = sum + s[i] - 'A' * pow(16, i);
    }
    cout << sum << endl;
    return sum;
}
/*
    10进制转任意进制
*/
string tochangeten(int n, int radix)
{
    int m = n;
    string ans = "";
    while (n)
    {
        int t = n % radix;
        if (t >= 0 && t <= 9)
            ans += t + '0';
        else
            ans += t - 10 + 'a';
        n /= radix;
    }
    reverse(ans.begin(), ans.end());
    cout << "10base: " << m << "changebase" << radix << " result: " << ans << endl;
    return ans;
}
int main()
{
    // c++指定数转为 16 10 8 2 进制

    cout << hex << 35 << endl;      // 16
    cout << oct << 35 << endl;      // 8
    cout << dec << 35 << endl;      // 10
    cout << bitset<16>(35) << endl; // 2
    changetwo(35);

    string s = "1000";
    int aa = 1000;
    cout << transf<int, string>(aa)[1] << endl; // 已经转换成功了所以可以输出第一个
    int number = transf<string, int>("1000");
    cout << number << endl;
    changeten(s, 2);     // 将1000 2进制数转换为10进制
    changeten("7F", 16); // 将7F 16进制转换为10进制
    tochangeten(112, 16);
    changeten("FFF", 16);
    change16("7F");
}