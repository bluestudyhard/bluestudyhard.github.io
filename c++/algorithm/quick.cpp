#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void quick_sort(int left, int right, vector<int> &arr)
{
    if (left >= right)
        return;
    int i = left, j = right, key;
    key = arr[left];
    while (i < j)
    { // 找一个比基准值小的
        while (key <= arr[j] && i < j)
            j--;
        // 找第一个比基准值大的
        while (key >= arr[i] && i < j)
            i++;

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    // 然后再更换左边
    arr[left] = arr[i];
    arr[i] = key;
    quick_sort(left, i - 1, arr);
    quick_sort(i + 1, right, arr);
}
int main()
{
    vector<int> arr{100, 5, 3, 11, 33, 6, 8, 7};
    quick_sort(0, arr.size() - 1, arr);
    for (auto i : arr)
        cout << i << " ";
}