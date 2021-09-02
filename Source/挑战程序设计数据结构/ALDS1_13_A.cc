#include <iostream>
using namespace std;
const int N = 10;

int k;
char Q[8][8];
bool row[N], col[N], dpos[N*2], dneg[N*2];

void dfs(int x, int y, int q)
{
    if (y == 8)
    {
        ++x;
        y = 0;
    }

    if (x == 8)
    {
        if (q == 8)
        {
            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                    cout << Q[i][j];
                cout << endl;
            }
        }
        return;
    }
    
    // 不放皇后,判断下一个点
    dfs(x, y+1, q);

    // 放皇后
    if (!row[x] && !col[y] && !dpos[x+y] && !dneg[x-y+8-1])
    {
        row[x] = col[y] = dpos[x+y] = dneg[x-y+8-1] = true;
        Q[x][y] = 'Q';
        dfs(x, y+1, q+1);
        row[x] = col[y] = dpos[x+y] = dneg[x-y+8-1] = false;
        Q[x][y] = '.';
    }

}

int main()
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            Q[i][j] = '.';
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        Q[x][y] = 'Q';
        row[x] = col[y] = dpos[x+y] = dneg[x-y+8-1] = true;
    }

    dfs(0, 0, k);

    return 0;
}
