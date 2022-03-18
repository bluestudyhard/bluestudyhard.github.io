[toc]
#### stringstream
- 由于to_string是c++11的,面对不能用to_string的时候可以用stringstream;
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