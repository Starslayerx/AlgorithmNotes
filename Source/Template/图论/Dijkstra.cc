/* 
 * Dijkstra 单源最短路算法--堆优化版本
 *
 * 正权图
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
const int N = 1e6; // 最大点、边数
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra(int start)  // start到其他所有点的最短距
{
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second;

        if (st[ver]) continue; // 已经确定最短路的点

        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h); // 不能放到函数内初始化,否则会影响add()

    scanf("%d%d", &n, &m);
    int a, b, c;
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    // 得到1号点到各点的最小距离dist[], 若dist[end] = INF,则1到end无最短距离
    dijkstra(1);


    // example: 1->n
    if (dist[n] == 0x3f3f3f3f)
        puts("impossible");
    else
        printf("%d\n", dist[n]);

    return 0;
}
