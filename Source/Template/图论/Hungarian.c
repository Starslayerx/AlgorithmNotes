#include <stdio.h>
#include <string.h>

#define N 505
#define M 100005

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
int st[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = 1;
            if (match[j] == 0 || find(match[j])) // 匹配成功
            {
                match[j] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);
    int a, b;
    while (m--)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= n1; ++i)
    {
        memset(st, 0, sizeof st);
        if (find(i)) 
            ++ans;
    }

    printf("%d\n", ans);

    return 0;
}
