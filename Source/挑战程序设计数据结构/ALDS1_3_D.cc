#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int sum = 0;
    char ch;
    stack<int> S1;  // 存储距离
    stack<pair<int, int>> S2; // 存储<编号，一个池子的面积>

    for (int i = 0; cin >> ch; ++i)
    {
        if (ch == '\\')
            S1.push(i);
        else if (ch == '/' && S1.size() > 0)
        {
            int j = S1.top();
            sum += i - j;
            int a = i - j;
            S1.pop();

            while (S2.size() && S2.top().first > j)
            {
                a += S2.top().second;
                S2.pop();
            }
            S2.push({j, a});
        }
    }

    vector<int> ans;

    cout << sum << endl;
    cout << S2.size();

    while (S2.size())
    {
            ans.push_back(S2.top().second);
            S2.pop();
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << " " << ans[i];
    cout << endl;


    return 0;
}
