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
int changeten(string s, int radix)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(s[i]))
        {
            ans = ans * radix + (c - '0'); // 以2进制为例子 , 2转10 需要
        }
        else
            ans = ans * radix + c - 'a' + 10;
    }
    cout << ans << endl;
    return ans;
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
10进制转任意进制
*/
/*
任意转16进制
*/
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
    cout << transf<int, string>(aa)[1] << endl;
    changeten(s, 2);
}