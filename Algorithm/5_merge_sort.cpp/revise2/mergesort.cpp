#include <iostream>
using namespace std;

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
        while (j <= high)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    for (int x = 0; x < k; x++)
    {
        a[low + x] = b[x];
    }
}

void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[] = {3, 2345, 34, 5645, 32, 432, 134, 5435, 64, 5};
    int n = 10;
    cout << "Before merge sorting:\n";
    display(n, a);

    cout << "After merge sorting:\n";
    mergesort(a, 0, n - 1);
    display(n, a);
}