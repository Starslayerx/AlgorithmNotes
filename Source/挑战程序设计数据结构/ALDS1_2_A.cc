#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int* A, int n);
void PrintArray(int* A, int n);

int main()
{
    int n, A[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    BubbleSort(A, n);

    return 0;
}

void BubbleSort(int *A, int n)
{
    int count = 0;
    bool swapped = false;
    for (int i = n-1; i > 0; --i) 
    {
        for (int j = 0; j < i; ++j)
        {
            if (A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
                ++count;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
    PrintArray(A, n);
    cout << count << endl;
}

void PrintArray(int* A, int n)
{
    for (int i = 0; i < n; ++i) { 
        if (i)
            cout << " " << A[i];
        else
            cout << A[i];
    }
    cout << endl;
}
