#include <iostream>
using namespace std;

void mergesort(int *a, int mid, int high, int low)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int c[8];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        j++;
        k++;
    }
    for (int x = low; x < high; x++)
    {
        a[x] = c[x];
    }
}

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    //          i     j
    //          0 1 2 3 4 5 6 7
    int a[100] = {2, 4, 6, 8, 1, 3, 5, 7};
    cout << "Before:\n";
    display(8, a);
    cout << "After:\n";
    mergesort(a, 3, 7, 0);
    display(8, a);
}