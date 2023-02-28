#include <bits/stdc++.h>
using namespace std;

/*堆排序*/
void make_heap(int *arr, int start, int end)
{ // start 就是开始的父节点，end 就是右节点
    int dad = start;
    int left = 2 * dad + 1;
    int right = 2 * dad + 2;

    if (left <= end && right <= end)
    {
        if (arr[left] > arr[dad])
        { // 先比较做左儿子节点和父节点，谁大谁做爹
            dad = left;
        }
        if (arr[right] > arr[dad])
        {
            dad = right;
        }
        // 表示父节点已经更换了，那么再放回堆里面去向下调整
        if (dad != start)
        {
            swap(arr[dad], arr[start]);
            make_heap(arr, dad, end);
        }
    }
}
void heap_sort(int *arr, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        make_heap(arr, i, len - 1);
    }
    // 走完上面那一步以后我们已经建立好了一个大顶堆，然后这个时候我们要交换当前堆的父节点，和大顶堆的堆顶
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        make_heap(arr, 0, i - 1);
    }
}
int main()
{                             // 生成随机数
    srand((unsigned)time(0)); // 随机种子
    // for (int i = 1; i <= 10000; i++)
    //     cout << rand() % 10000 + 1 << endl; // 生成 1-6的随机数
    // for (int i = 1; i <= 10; i++)
    //     cout << (rand() % (100 - 10) + 10) << endl; // 10-100 任意区间
    int arr[10];
    for (int i = 1; i <= 10; i++)
    {
        int temp = rand() % 10 + 1;
        arr[i] = temp;
    }
    for (int i : arr)
        cout << arr[i] << " ";
    heap_sort(arr, 10);
    cout << endl;
    for (int i : arr)
        cout << arr[i] << " ";
}