[toc]

#### stringstream

- 由于 to_string 是 c++11 的,面对不能用 to_string 的时候可以用 stringstream;

```C++ {.line-numbers}
template <class out_type, class in_value>//输入的类型，转换的类型
out_type transf(const in_value &t)
{
   stringstream stream; out_type result;
   stream << t, stream >> result, stream.sync();//stream.sync 表示清空流,因为ss会调用大量的内存
   return result;
}
int main()
{
   string s = "532";
   double t = transf<double>(s); // <>里的是要转换的类型名，()里的是被转换的变量名
}
/*单独转int*/
string tostring(int n)
{
    string ans;
    stringstream stream;
    stream << n ,stream>>ans,stream.sync();
    return ans;
}
```

#### 判断回文数

```C++ {.line-numbers}
if (string s == string(s.rbegin(),s.rend()));//12321发过来相等的就是回文了。
```

#### 对于一种模拟题的解法

- 例:蓝桥杯的一道基础题 [](http://lx.lanqiao.cn/problem.page?gpid=T48)
- 解法很简单,首先从 10000 开始,判断每一个数是不是回文数,然后再 to_string 输出就好
  ```C++ {.line-numbers}
  int sum(int n)
  {
     int ans = 0;
     while(n)
     {
        ans +=n%10,n/10;
     }
     return ans;
     int main()
     {
        int n;
        cin>>n;
        for(int i = 1e4;i<1e6;i++)
           {
               if(sum(i)==n)
               {
                  string s = to_string(i);
                  if(string s = string(s.rebegin(),s.rend()))
                        cout<<s<<endl;
               }
           }
     }
  }
  ```
