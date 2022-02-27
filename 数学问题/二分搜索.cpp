#include <bits/stdc++.h>
using namespace std;
int main()
int binarysearch(int a[],int key,int n)//二分搜索原理
{
     int left = 0;
     int right = n;
     int mid = (left+right/2)
     if(key == a[mid])
       return mid;
      else if (a[mid]>key)
        right = mid;
      else
      left = mid+1;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{   //lower_bound 返回值为一个指针，所以减去数组的指针就是一个int变量了
    //lower_bound 返回在区间中检索的第一个小于或！！！！（等于）！！！idx的位置。
    //lower_bound 还自带去重
    int n,a[11]={1,2,3,4,5,6,7,8,9};
    //lower_bound （数组名，数组名加你要检索的长度，idx检索数）-数组；
    int *pos3 = lower_bound(a,a+9,3);
    int pos = lower_bound(a,a+9,3)-a;
     cout<<*pos3<<endl<<pos;
    //upper_bound同理
    int pos1 = upper_bound(a,a+9,10)-a;
    int pos2 = upper_bound(a,a+9,3)-a;
    cout<<" "<<pos1<<" "<<pos2<<endl;

    //stl binary_search() 二分查找，找到就返回1，找不到返回0
    int indx = binary_search(a,a+9,2);
    cout<<indx;
}