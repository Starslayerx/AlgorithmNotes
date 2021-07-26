#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    string str;
    int a, b;

    while (cin >> str)
    {
        if (str[0] == '+')
        {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(a + b);
        }
        else if (str[0] == '-')
        {
            b = s.top(); s.pop();
            a = s.top(); s.pop();
            s.push(a - b);
        }
        else if (str[0] == '*')
        {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(a * b);
        }
        else
            s.push(atoi(str.c_str()));  // 非符号转整数
    }
    cout << s.top() << endl;

    return 0;
}
