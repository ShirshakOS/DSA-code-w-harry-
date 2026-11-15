#include <iostream>
using namespace std;

void merge(int *a, int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = 0;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
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
        k++;
        j++;
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

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {43, 54, 76, 87, 58};
    cout << "Before mergesort:\n";
    display(a, 5);
    mergesort(a, 0, 4);
    cout << "After mergesort:\n";
    display(a, 5);
    return 0;
}