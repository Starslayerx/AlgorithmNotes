#include <string.h>
#include <stdio.h>

#define N 100005

int n, m;
int h[N], e[N*2], ne[N*2], idx;
int color[N], q[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs(int s)
{
    int hh = 0, tt = -1;
    q[++tt] = s;
    color[s] = 1;

    while (hh <= tt)
    {
        int t = q[hh++];
        int c = color[t];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];

            if (!color[j])
            {
                color[j] = 3 - c;
                q[++tt] = j;
            }
            else if (color[j] == c)
                return 0;
        }
    }
    return 1;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    int a, b;
    while (m--)
    {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }

    int flag = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!color[i])
        {
            if (!bfs(i))
                flag = 0;
        }
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}

