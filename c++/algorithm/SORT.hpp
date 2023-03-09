#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// 堆排序
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

// 基数排序

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// 根据指定的位数对数组进行计数排序
void countSort(int arr[], int n, int exp)
{
    int output[n];       // 存储输出结果的数组
    int count[10] = {0}; // 存储每个位上数字出现的次数

    // 计算每个位上数字出现的次数
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // 计算每个位上数字在输出数组中的位置
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 将元素按照指定的位数放入输出数组中，保持稳定性
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将输出数组复制到原始数组中
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// 对给定的数组进行基数排序
void radixsort(int arr[], int n)
{

    // 获取最大值，确定最大位数
    int m = getMax(arr, n);

    // 对每个位上的数字进行计数排序，从最低有效位开始
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// 快速排序

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
void quick_sort(vector<int> &arr, int len)
{
    quick_sort(0, len, arr);
}
// 冒泡排序
void bubble_sort(vector<int> &arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j + 1], arr[j]);
        }
    }
}

/*希尔排序*/
void shellSort(vector<int> &arr, int n)
{
    // 初始增量设为数组长度的一半
    int gap = n / 2;
    // 循环直到增量为1
    while (gap > 0)
    {
        // 对每个子序列进行插入排序
        for (int i = gap; i < n; i++)
        {
            // 保存当前元素和其所在子序列的前一个元素的下标
            int temp = arr[i];
            int j = i - gap;
            // 比较并移动元素
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            // 插入当前元素到正确位置
            arr[j + gap] = temp;
        }
        // 减小增量
        gap /= 2;
    }
}

// 选择排序
void selectionSort(vector<int> &arr, int n)
{
    // 循环n-1次
    for (int i = 0; i < n - 1; i++)
    {
        // 初始化选取最小值和其下标
        int min = arr[i];
        int minIndex = i;
        // 在剩余元素中寻找最小值
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        // 如果最小值不在起始位置，交换两个元素
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// 归并排序
void merge(int arr[], int left, int mid, int right)
{
    // 创建临时数组
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    // 复制数据到临时数组
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    // 合并两个临时数组
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // 复制剩余元素
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序函数（迭代）
void mergeSort(int arr[], int len)
{
    // 初始子序列长度为1
    int sublen = 1;
    while (sublen < len)
    {
        // 每次将相邻两个子序列合并
        for (int i = 0; i < len; i += sublen * 2)
        {
            // 左边界
            int left = i;
            // 中间位置
            int mid = min(i + sublen - 1, len - 1);
            // 右边界
            int right = min(i + sublen * 2 - 1, len - 1);
            // 合并操作
            merge(arr, left, mid, right);
        }
        // 子序列长度翻倍
        sublen *= 2;
    }
}