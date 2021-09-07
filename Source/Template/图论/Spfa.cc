// Spfa：Bellman-Ford改进算法，使用于任意图

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
bool st[N]; // 是否在队列中

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa(int start)  // start到其他所有点的最短距
{
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;

    queue<int> q;
    q.push(start);
    st[start] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
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
    spfa(1);

    // example: 1->n
    if (dist[n] == 0x3f3f3f3f)
        puts("impossible");
    else
        printf("%d\n", dist[n]);

    return 0;
}
