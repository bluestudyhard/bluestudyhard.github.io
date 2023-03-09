#include <bits/stdc++.h>
#include "SORT.hpp"
#include <chrono>
using namespace std;
using namespace std::chrono; // 要使用命名空间

typedef long long ll;
// 生成随机数
vector<int> rand_vec(int len)
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(1, len);
    vector<int> v;
    for (int i = 0; i < len; i++)
    {
        v.push_back(u(e));
    }
    return v;
}
auto bulid_arr(int len)
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(1, len);
    vector<unsigned> v;
    int *arr = new int[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = u(e);
    }
    return arr;
}
void test(int number)
{
    for (int i = 1; i <= 3; i++)
    {
        int len; // number 1-7
        cin >> len;
        vector<int> v1 = rand_vec(len);
        auto start = high_resolution_clock::now();
        if (number == 1)
        {
            heap_sort(v1, len); // 堆排
        }
        else if (number == 2)
        {
            quick_sort(v1, len); // 快排
        }
        else if (number == 3)
        {
            auto a = bulid_arr(len); // 基数排序
            radixsort(a, len);
        }
        else if (number == 4)
        {
            selectionSort(v1, len); // 选择排序
        }
        else if (number == 5)
        {
            bubble_sort(v1, len); // 冒泡排序
        }
        else if (number == 6)
        {
            shellSort(v1, len); // 希尔排序
        }
        else
        {
            auto a1 = bulid_arr(len);
            mergeSort(a1, len); // 使用归并
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        auto s = duration.count() / 1000000;
        auto ms = (duration.count() % 1000000) / 1000;
        cout << duration.count() << endl;
        cout << s << "s " << ms << " ms " << endl; // 运算所得时间
    }
}
string name[7] = {"heap", "quick", "digit", "choose", "bubble", "here", "merge"};
int main()
{
    int number;
    cin >> number;
    cout << "序号1-7分别代表 堆排序，快速排序，基数排序，选择排序，冒泡排序，希尔排序，归并排序" << endl;
    switch (number)
    {
    case 1 /* constant-expression */:
    {
        cout << "进行堆排序测试" << endl;
        test(1);
        break;
    }
    case 2 /* constant-expression */:
    {
        cout << "进行快速排序测试" << endl;
        test(2);
        break;
    }
    case 3 /* constant-expression */:
    {
        cout << "进行基数排序测试" << endl;
        test(3);
        break;
    }
    case 4 /* constant-expression */:
    {
        cout << "进行选择排序测试" << endl;
        test(4);
        break;
    }
    case 5 /* constant-expression */:
    {
        cout << "进行冒泡排序测试" << endl;
        test(5);
        break;
    }
    case 6 /* constant-expression */:
    {
        cout << "进行希尔排序测试" << endl;
        test(6);
        break;
    }
    case 7 /* constant-expression */:
    {
        cout << "进行归并排序测试" << endl;
        test(7);
        break;
    }
    default:
        break;
    }
}
