#include <iostream>
#include "Graph.hpp"
using namespace std;

int main()
{
    Graph kk(5);
    string s;
    int node, edge;
    int start, end;
    /*输入顶点个数和边的个数*/
    cout << "输入顶点个数和边的数量" << endl;
    cin >> node >> edge;

    for (int i = 0; i < node; i++)
    {
        cin >> s;
        Node *node = new Node(s);
        kk.insertNode(node);
    }
    for (int i = 0; i < edge; i++)
    {
        cin >> start >> end;
        kk.insertedge(start, end);
    }
    /*打印邻接矩阵*/
    kk.print_matrix();

    // 寻找从0到各个顶点的最短路
    kk.Dijstra();
    cout << endl;
    // 深度优先遍历
    kk.dfs(0);

    kk.delete_edge(0, 1);
    cout << endl;
    kk.print_matrix();
}