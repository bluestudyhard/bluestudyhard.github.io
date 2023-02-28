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

/*#include <iostream>

// 交换两个元素的值
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 向下调整最大堆
void maxheap_down(int a[], int start, int end) {
    // 当前节点的位置
    int c = start;
    // 左孩子的位置
    int l = 2 * c + 1;
    // 右孩子的位置
    int r = 2 * c + 2;

    // 如果左孩子存在且大于当前节点
    if (l <= end && a[l] > a[c]) {
        // 更新当前节点为左孩子
        c = l;
    }

    // 如果右孩子存在且大于当前节点
    if (r <= end && a[r] > a[c]) {
        // 更新当前节点为右孩子
        c = r;
    }

    // 如果当前节点不是最大的
    if (c != start) {
        // 交换当前节点和最大的孩子
        swap(a[c], a[start]);
        // 继续向下调整以保持最大堆性质
        maxheap_down(a, c, end);
    }
}

// 建立最大堆
void make_maxheap(int a[], int n) {

   for (int i = n / 2 - 1; i >= 0; i--) {
       maxheap_down(a, i, n - 1);
   }
}

// 堆排序（升序）
void heap_sort_asc(int a[], int n) {

   make_maxheap(a, n);

   for (int i = n - 1; i > 0; i--) {
       swap(a[0], a[i]);
       maxheap_down(a, 0, i - 1);
   }
}

int main() {

   int arr[] = {10,20,15,12,40,25,18};
   int len = sizeof(arr) / sizeof(arr[0]);

   heap_sort_asc(arr,len);

   for (int x : arr) {
       std::cout << x << " ";
   }

   std::cout << "\n";

   return 0;
}*/