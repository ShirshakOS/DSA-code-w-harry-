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

void merge(int *a, int low, int high, int mid)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
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
        k++;
        i++;
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
        merge(a, low, high, mid);
    }
}

int main()
{
    int a[] = {7, 1, 8, 2};
    int n = 4;
    mergesort(a, 0, n - 1);
    display(n, a);
    return 0;
}