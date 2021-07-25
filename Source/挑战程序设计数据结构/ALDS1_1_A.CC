#include <iostream>
using namespace std;

void InsertSort(int* A, int n);
void PrintArray(int* A, int n);

int main()
{
    int n, A[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    PrintArray(A, n);
    InsertSort(A, n);

    return 0;
}

void InsertSort(int* A, int n)
{
    int new_card, i, j;
    for (i = 1; i < n; ++i) {
        new_card = A[i];
        j = i - 1;
        while (j >= 0 && new_card < A[j]) {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = new_card;
        PrintArray(A, n);
    }
}

void PrintArray(int* A, int n)
{
    // 这里注意最后不要多打一个空格
    for (int i = 0; i < n; ++i) { 
        if (i)
            cout << " " << A[i];
        else
            cout << A[i];
    }
    cout << endl;
}
