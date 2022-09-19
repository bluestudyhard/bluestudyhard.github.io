#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
int st(int a,int b,int c)
{   int kk[10] = {0};
    while(a)
    {
        kk[a%10]++;
        a/=10;
    }
    while(b)
    {
        kk[b%10]++;
        b/=10;
    }
    while(c)
    {
        kk[c%10]++;
        c/=10;
    }
    for(int i = 1;i<=9;i++)
    {
        if(kk[i]!=1)
        return 0;
    }
    return 1;
}
int main()
{
    for(int i = 1000;i<=9999;i++)
        for(int j = 1;j<=100;j++)
            {
                int k = i/j;
                if(st(i,j,k)&&i%k==0)
                {
                    printf("%d = %d x %d",i,j,k);
                    cout<<endl;
                }
            }
}
*/
/*ll fpow(ll a, ll b)
{
  ll sum = 1;
  while(b)
  {
      if(b&1)
      {
          sum*=a;
      }
      a*=a;
      b>>=1;
  }
  return sum;
}
int main()
{
  cout<<fpow(2,3);
}*/

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// bool v[10000];
// int n, m, i, j, sum = 0, k;
// bool isprime(int n)
// {
//     for (i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }
// int a[25];
// long long ans;
// void dfs(int m, int sum, int startx)
// { /* 递归深度*/
//     if (m == k)
//     {
//         if (isprime(sum))
//             ans++;
//         return;
//     }
//     for (int i = startx; i < n; i++)
//     { /*操作*/
//         sum += a[i];
//         cout << "m = " << m << " sum = " << sum << " i = " << i << endl;
//         dfs(m + 1, sum, i + 1);
//         sum -= a[i];
//         cout << "m = " << m << " sum = " << sum << " i = " << i << endl;
//     }
//     return;
// }
// int main()
// {
//     scanf("%d%d", &n, &k);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &a[i]);
//     dfs(0, 0, 0);
//     printf("%d\n", ans);
//     return 0;
// }

// int main()
// {
//     int a,i,j;
//     char c;
//     cin>>a>>c;
//     j = a/2;
//     for(i = 1;i<=a/2;i++)
//     {
//         cout<<c;
//         j--;
//         if(i-2==j)
//         {
//             cout<<endl;
//         }

//     }
// }

// int isprime(int n)
// {
//     if(n==1||n==2)
//     return 1;
//     for(int i = 2;i<=sqrt(n);i++)
//     {
//             if(n%i==0)
//                 return 0;
//     }
//     return 1;
// }
// stringstream ss;
// int ispp(ll n,ll m)
// {   int a[10] = {0};
//     int b[10] = {0};
//     while(n)
//     {
//         a[n%10]++;
//         n/=10;
//     }
//     while(m)
//     {
//         b[m%10]++;
//         m/=10;
//     }
//     for(int i = 1;i<=9;i++)
//     {
//         if(a[i]!=b[i])
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     // string n;
//     // cin>>n;
//     string n;
//     int flag = 1;
//     cin >> n;
//     int a[22], b[22], a1[10] = {0}, b1[10] = {0};
//     for (int i = 0; i < n.length(); i++)
//     {
//         a[i + 1] = n[i] - '0';
//         b[i + 1] = a[i + 1] * 2;
//     }
//     for (int i = n.length(); i>=1; i--)
//     {
//         if (b[i] > 9)
//         {
//             b[i] -= 10;
//             b[i - 1] += 1;
//         }
//     }
//     for (int i = 1; i <= n.length(); i++)
//     {
//         a1[a[i]]++;
//         b1[b[i]]++;
//     }
//     for (int i = 1; i < n.length(); i++)
//     {
//         if (a1[i] != b1[i])
//         {
//             flag = 0;
//             break;
//         }
//     }
//     if (flag == 1)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//         cout << "No" << endl;
//     for (int i = 1; i <= n.length(); i++)
//     {
//         cout << b[i];
//     }
// }

// void text(int a,int b = 9,char c = '*')
// {
//     cout<<"cuf";
// }
// int main()
// {
//     text(0,'*');
// }
int path[10];
bool s[10];
void dfs(int u)
{
    if (u > 8)
    {
        for (int i = 1; i <= 8; i++)
        {
            if (i < 8)
                cout << path[i] << ' ';
            else
                cout << path[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= 8; i++)
    {
        if (!s[i])
        {
            path[u] = i;
            s[i] = true;
            dfs(u + 1);
            s[i] = false;
        }
    }
    return;
}
ll fpow(ll a, ll b, ll p)
{
    ll sum = 1;
    while (b)
    {
        if (b & 1)
        {
            sum = sum * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return sum % p;
}
// 通过递归分割数组元素
void merge(int arr[], int aray[], int left, int mid, int right)
{
    int l_pos = left;
    int r_pos = mid + 1;
    int pps = left;
}
void m_sort(int arr[], int aray[], int left, int right)
{
    //  2  3
    //  0  1
    if (left < right) // 说明至少还存在两个元素没划分
    {
        int mid = (left + right) / 2;
        m_sort(arr, aray, left, mid);
        m_sort(arr, aray, mid + 1, right);
        merge(arr, aray, left, mid, right);
    }
}
void merge_sort(int arr[], int len)
{
    int *aray = new int[len];
    m_sort(arr, aray, 0, len - 1);
    delete aray;
}
const int maxCapacity = 5;
template <typename T>
class dynamic_list
{
private:
    int thesize;
    int thecapacity;
    T *v;

public:
    dynamic_list(int thesize = 0) : thesize(thesize), thecapacity(maxCapacity + thesize)
    {
        v = new T[maxCapacity]; // 初始化一片空间
    }
    dynamic_list(const dynamic_list &L) : thesize(0), thecapacity(0), v(nullptr)
    {
        *this = L; // this 指向当前对象，那么就是说我创建一个拷贝构造函数会给他赋值默认构造函数的值。其实就是创了一个空的表。
    }
    void create_array(T *t, int len)
    {
        for (int i = 1; i <= len; i++)
        {
            v[i] = t[i];
        }
        this->thesize = len;
    }
    void resize(int newsize) //用于判断我们想要存进去的数据，会不会超过原本我们开辟的空间
    {
        if (newsize < thesize)
            return;
        else if (newsize > thecapacity) //如果超过了，就调用reserve函数，给空间扩容。
        {
            reserve(newsize * 2 + 1); //使原本的空间扩容2倍并，+1是表示在没有定义初始空间时，0size时，保证有1个元素的空间。
        }
        thesize = newsize; //扩完容以后就让这个超过的长度变成现在的数组长度。
    }
    void reserve(int newcapacity)
    {
        if (newcapacity < thecapacity)
            return;
        T *temp = v;            //先用一个数组来暂时存储我们原本的数据。
        v = new T[newcapacity]; //扩容

        for (int i = 1; i <= thesize; i++)
        {
            v[i] = temp[i]; //再把数据存回新的空间
        }
        delete temp; //删除临时交换数组。
    }
    bool insert_e(int index, T e)
    {
        if (index < 0 || index > thecapacity)
        {
            cout << "insert false" << endl;
        }
        for (int i = thesize + 1; i >= index; i--)
        {
            v[i] = v[i - 1]; //就是每个元素往后移动1位腾出空间，然后再把数据插入指定的位置就可以了。
            //比如 1 2 3 4 在2的位置插入1那么先变成 1 2 2 3 4 再在2的位置插入1 变成 1 1 2 3 4
        }
        v[index] = e;
        ++thesize; //插入以后长度+1;
        return 1;
    }
    bool remove_e(int index, T e)
    {
        if (index < 0 || index > thecapacity)
        {
            cout << "remove false" << endl;
            return 0;
        }
        for (int i = index; i <= thesize; i++)
        {
            v[i] = v[i + 1]; //和插入同理，就是往前挤掉元素就可以
        }
        --thesize;
        return 1;
    }
    int find_e(T e)
    {
        for (int i = 1; i <= thesize; i++)
            if (v[i] == e)
                return i;
        return 0;
    }
    void push_back(T e)
    {
        if (thesize == thecapacity)
        {
            reserve(thecapacity * 2 + 1);
        }
        v[++thesize] = e; // thesize 默认为0，所以要先自增才插入
    }
    void pop_back()
    {
        --thesize;
    }
    int Thesize()
    {
        return thesize;
    }
    void display()
    {
        for (int i = 1; i <= thesize; i++)
            cout << v[i] << " ";
        cout << endl;
    }
};
int main()
{
    dynamic_list<int> kk;
    for (int i = 1; i <= 10; i++)
        kk.push_back(i);
    kk.display();
    kk.insert_e(2, 2);
    kk.display();
    kk.remove_e(2, 2);
    kk.display();
    cout << kk.find_e(2);

    dynamic_list<int> k;
    int array[6] = {0}, len = 0;
    for (int i = 1; i <= 5; i++)
    {
        array[i] = i;
        len++;
    }
    k.create_array(array, len);
    k.display();
}
// vector<int> kk{1, 2, 3};
// reverse(kk.begin(), kk.end());
// for (auto i = kk.begin(); i != kk.end(); i++)
// {
//     cout << *i;
// }
// dfs(1);
//     char p[5] = {'S', 'H', 'C', 'D', 'J'};
//     int card[55];
//     int number[55];
//     int k;
//     cin >> k;
//     for (int i = 1; i <= 54; i++)
//     {
//         cin >> number[i];
//     }
//     for (int i = 1; i <= 54; i++)
//     {
//         int temp = i;
//         for (int j = 0; j < k; j++)
//         {
//             temp = number[temp];

//         }
//         card[temp] = i;
//     }
//     cout << p[(card[1] - 1) / 13] << (card[1] - 1) % 13 + 1;// 考虑到p的第一位s是p[0]
//     for (int i = 2; i <= 54; ++i)
//         cout << ' ' << p[(card[i] - 1) / 13] << (card[i] - 1) % 13 + 1;
// }

// int n, m, i = 1, j, cnt = 0;
// char c;
// cin >> n >> c;
// m = sqrt((n + 1) / 2.0);// sn = n^2;
// for (i = m; i >= 1; i--)
// {
//     for (j = 1; j <= m - i; j++)
//     {
//         cout << " ";
//     }
//     for (int k = 1; k <= 2 * i - 1; k++)
//     {
//         cout << c;
//         cnt++;
//     }
//     cout << endl;
// }
// for (i = 2; i <= m; i++)
// {
//     for (j = 1; j <= m - i; j++)
//     {
//         cout << " ";
//     }
//     for (int k = 1; k <= 2 * i - 1; k++)
//     {
//         cout << c;
//         cnt++;
//     }
//     cout << endl;
// }
// cout << n - cnt;
// int a[4] = {1,2,7,8};
// int b[4] = {5,6,9};
// int i = 0,j = 0,len = 8, k = 0;
// int c[8] = {0};
// while(i<4&&j<3)
// {
//     if(a[i]<b[j])
//     {
//         c[k++] = a[i];
//         i++;
//     }
//     else
//     {
//         c[k++] = b[j];
//         j++;
//     }
// }
// while(i<4)
// {
//     c[i++] = a[i];
// }
// while(j<3)
// {
//     c[k++] = b[j++];
// }
// for(i = 0;i<len;i++)
// {
//     cout<<c[i];
// }
// 划分
// int a = 1,b = 2,c = 3;
// int maxx = a>b?a:b>c?a:c;
// cout<<maxx;
