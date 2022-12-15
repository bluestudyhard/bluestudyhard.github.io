#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxx = 100;
const int INF = 99999;
// 顶点
struct Node
{
    string data;
    bool visited; // 判断是否被访问

    Node(string data = "") : data(data)
    {
        visited = false;
    }
    // 节点赋值
    Node(const Node &node)
    {
        if (this == &node)
            return;
        *this = node;
    }
};
struct edge
{
    int headNode; // 头顶点
    int tailNode; // 尾顶点
    int weight;   // 权重
    edge(int h, int t) : headNode(h), tailNode(t) {}
    edge(int h, int t, int w) : headNode(h), tailNode(t), weight(w) {}
    edge(const edge &edge)
    {
        if (this == &edge)
            return;
        *this = edge;
    }
};

class Graph
{
private:
    int curnode;                    // 当前顶点数
    int nodesum;                    // 顶点总数
    Node *arr;                      //顶点数组
    int martix[maxx][maxx] = {INF}; // 邻接矩阵
public:
    Graph(int sum)
    {
        nodesum = sum;
        curnode = 0;
        arr = new Node[sum];
        for (int i = 0; i < nodesum; i++)
            for (int j = 0; j < nodesum; j++)
                martix[i][j] = INF;
    }
    ~Graph()
    {
        delete arr;
    }
    Node *getNode(string data)
    {
        Node *node = new Node(data);
        return node;
    }
    // 插入顶点
    void insertNode(Node *node)
    {

        arr[curnode++].data = node->data;
    }
    // 插入边
    void insertedge(int start, int end)
    {
        martix[start][end] = 1;
        martix[end][start] = 1;
    }
    // 删除边
    void delete_edge(int start, int end)
    {
        martix[start][end] = INF;
        martix[end][start] = INF;
    }
    // 打印临接矩阵
    void print_matrix()
    {
        for (int i = 0; i < nodesum; i++)
        {
            for (int j = 0; j < nodesum; j++)
                cout << martix[i][j] << " ";
            cout << endl;
        }
    }
    // 深度优先遍历
    void dfs(int index)
    {

        cout << arr[index].data << " ";
        arr[index].visited = true;
        for (int i = 0; i < nodesum; i++)
        {
            if (arr[i].visited)
                continue;
            dfs(i);
        }
    }

    // 通过dijstra算法求最短路
    // 表示从原点到各个顶点的最短路径，因为我这是非加权无向图，所以都为1，但是可以算原点到各个顶点的最短路径
    void Dijstra()
    {
        int curmin[nodesum]; // 记录每次得到的最短路径
        int p[nodesum];      // 记录每次更新后可达的顶点
        int minn = INF, temp;
        // 初始化，从第一个节点开始
        arr[0].visited = true;
        for (int i = 0; i < nodesum; i++)
        {
            curmin[i] = martix[0][i];
            if (curmin[i] < minn)
            {
                p[i] = 0;
            }
            else
                p[i] = -1;
        }
        curmin[0] = 0;
        // 从第一个顶点开始找到和某个顶点的最短路径
        for (int i = 1; i < nodesum; i++)
        {
            minn = INF - 1; // 每次设定一次最小值，先遍历curmin数组，看看和别的节点的距离
            for (int j = 0; j < nodesum; j++)
            { // 非最大值表示与第j个顶点有链接
                if (arr[j].visited == false && curmin[j] <= minn)
                {
                    temp = j;         // 用temp来记录这个相邻的顶点，比如说检索到
                    minn = curmin[j]; // 找到最小值 无权的是1
                }
            }
            arr[temp].visited = true;
            // 更新curmin中的值
            for (int i = 0; i < nodesum; i++)
            {
                if (arr[i].visited == false && (curmin[temp] + martix[temp][i] < curmin[i]))
                {
                    curmin[i] = curmin[temp] + martix[temp][i];
                    p[i] = temp;
                }
            }
        }
        for (int i = 0; i < nodesum; i++)
        {
            cout << curmin[i] << " ";
        }
        for (int i = 0; i < nodesum; i++)
            arr[i].visited = false;
    }
};
