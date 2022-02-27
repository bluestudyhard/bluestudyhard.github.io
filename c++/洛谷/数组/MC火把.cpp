#include <iostream>
using namespace std;

int main()
{
    int map[110][110] = {0};
    int x, y, i, j, duck=0, n, hb, ys;
    cin >> n >> hb >> ys;
    while (hb--)
    {
        cin >> y >> x;
        for (i = y - 1; i <= y + 1; i++)
            for (j = x - 1; j <= x + 1; j++)
                map[i][j] = 1;
        map[y - 2][x] = 1, map[y][x - 2] = 1, map[y][x + 2] = 1, map[y + 2][x] = 1;
    }

    while (ys--)
    {
        cin >> y >> x;
        for (i = y - 2; i <= y + 2; i++)
            for (j = x - 2; j <= x + 2; j++)
                map[i][j] = 1;
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (map[i][j] == 0)
                duck++;
        }

    cout << duck;
}