#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void InsertSort(int *A, int n, int g);
void ShellSort(int *A, int n);


long long cnt;
vector<int> G;

int main()
{
    int n, A[1000000];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) // scanf 比cin更快
        scanf("%d", &A[i]);
    cnt = 0;

    ShellSort(A, n);

    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; --i)
    {
        printf("%d", G[i]);
        if (i)
            printf(" ");
    }
    printf("\n");
    printf("%lld\n", cnt);

    for (int i = 0; i < n; ++i)
        printf("%d\n", A[i]);

    return 0;
}

void ShellSort(int *A, int n)
{
    for (int h = 1;;)
    {
        if (h > n)
            break;
        G.push_back(h);
        h = 3*h + 1;
    }

    for (int i = G.size() - 1; i >= 0; --i)
        InsertSort(A, n, G[i]);
}

void InsertSort(int *A, int n, int g)  // 将每隔g的元素插入排序
{
    int new_card, i, j;
    for (i = g; i < n; ++i)
    {
        new_card = A[i];
        j = i - g;
        while (j >= 0 && A[j] > new_card)
        {
            A[j+g] = A[j];
            j -= g;
            ++cnt;      //记录移动次数
        }
        A[j+g] = new_card;
    }
}
