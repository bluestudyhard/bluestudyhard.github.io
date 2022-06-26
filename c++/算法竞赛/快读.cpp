#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();//原理：读入字符比读入数字更快
    while (ch < '0' && || ch > 9) // while(!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch>='0'&&ch<='9')//while(isdigit(ch))
    {
        x = x*10+ch-'0';//x = (x<<1)+(x<<3)+(ch^48);
        ch = getchar();
    }
    return x*f;
}
int main()
{
    int n = read(),m = read();
}
/*更快的快读
#include <cctype>
inline int getc() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}//fread才是最快的
   
inline int read() {
    int x = 0; 
    bool f = false;
    char s = getc();
    while(!isdigit(s)) {
        if(s == '-') f = true;
        s = getc();
    }
    while(isdigit(s))
        x = x * 10 + s - 48, s = getc();
    return f ? -x : x;
}