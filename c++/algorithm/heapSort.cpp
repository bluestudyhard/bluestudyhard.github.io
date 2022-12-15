#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 先将序列变为大顶堆
void MakeHeap(vector<int> &arr, int start, int end)
{ // 100 5 3 11 6 8 7
    int parent = start;
    int son = start * 2 + 1; // 我们构建完全二叉树的下标，他的子节点的下标是跨过
    // 在范围内
    while (son <= end)
    {
        // 第一步左右儿子开始比较，得到较大的儿子
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        // 如果父节点已经够大了，表示不用换，就直接return
        if (arr[parent] > arr[son])
            return;
        // 如果父节点比较小，交换，然后继续和孙节点比较，如果已经到叶子节点了，就会跳出循环
        else
        {
            swap(arr[parent], arr[son]);
            parent = son;
            son = parent * 2 + 1;
        }
    }
}
void heap_sort(vector<int> &arr, int len)
{
    // 先从最后一个非叶子节点开始
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        MakeHeap(arr, i, len - 1);
    }
    // 调整好后将尾和头交换，然后缩短长度，表示已经调整过了
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        MakeHeap(arr, 0, i - 1);
    }
}
int main()
{
    vector<int> arr{100, 5, 3, 11, 33, 6, 8, 7};
    heap_sort(arr, arr.size());
    for (auto i : arr)
    {
        cout << i << " ";
    }
}