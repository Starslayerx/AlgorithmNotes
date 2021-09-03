#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;

int bfs(string state)
{
    queue<string> q;
    unordered_map<string, int> d;  // 存储距离
    
    q.push(state);
    d[state] = 0;

    string end = "123456780";
    int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        if (t == end)
            return d[t];

        int distance = d[t];
        int pos = t.find('0');
        for (int i = 0; i < 4; ++i)
        {
            int x = pos / 3 + dx[i], y = pos % 3 + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                swap(t[pos], t[x*3+y]);
                if (!d.count(t)) // 该状态未找过
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[pos], t[x*3+y]);
            }

        }
    }
    return -1;
}

int main()
{

    char s[2];
    string state;
    for (int i = 0; i < 9; ++i)
    {
        cin >> s;
        state += *s;
    }


    cout << bfs(state) << endl;

    return 0;
}
