#include <bits/stdc++.h>
using namespace std;
void quicksort(int left,int right,vector<int> a)
{  
    int key = a[left];
    while(left!=right)
    {
        while(key<a[right])
            right--;
        while(key>a[right])
            left++;
        swap(a[left],a[right]);
        key = left+right/2;
        swap(left,key);
    }

}
int main()
{

}