/*
 * Flody算法
 *
 * 数据无负环(当心负自环,有的数据会有)
 */

#include <cstdio>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 505;  // 最大点数

int n, m; // n点 m边
int g[N][N];  // 邻接矩阵

void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
    scanf("%d%d", &n, &m);

    // 初始化距离
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;

    int a, b, c;
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    floyd();  // 完成,g[][]中即为最短路

    return 0;
}
