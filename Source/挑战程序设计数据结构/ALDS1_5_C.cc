#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<double, double > PII;

void solve(int n, PII l, PII r)
{
    double th = M_PI * 60.0 / 180.0;
    if (n == 0)
        return;
    PII a, b, c;
    a.first = (l.first * 2 + r.first) / 3.0;
    a.second = (l.second * 2 + r.second) / 3.0;
    b.first = (l.first + r.first * 2) / 3.0;
    b.second = (l.second + r.second * 2) / 3.0;
    c.first = (b.first - a.first) * cos(th) - (b.second - a.second) * sin(th);
    c.second = (b.first - a.first) * sin(th) + (b.second - a.second) * cos(th);

    solve(n-1, l, a);
    printf("%.8f %.8f\n", a.first, a.second);
    solve(n-1, a, b);
    printf("%.8f %.8f\n", b.first, b.second);
    solve(n-1, b, c);
    printf("%.8f %.8f\n", c.first, c.second);
    solve(n-1, c, r);
}

int main()
{
    int n;
    cin >> n;
    PII l = {0, 0}, r = {100.0, 0};
    printf("%.8f %.8f\n", l.first, l.second);
    solve(n, l, r);
    printf("%.8f %.8f\n", r.first, r.second);

    return 0;
}
