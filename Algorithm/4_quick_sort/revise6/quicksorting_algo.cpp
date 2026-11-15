#include <iostream>
using namespace std;

int partition(int *a, int low, int high)
{
    int pivot, i, j;
    pivot = a[low];
    i = low + 1;
    j = high;
    do
    {
        while (a[i] <= high && a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    int temp;
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int *a, int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(a, low, high);
        quicksort(a, low, partitionindex - 1);
        quicksort(a, partitionindex + 1, high);
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
    int a[] = {3, 24, 3, 35, 4, 56, 4, 76};
    int n = 8;
    int low = 0, high = 7;
    cout << "Before sorting:\n";
    display(a, n);
    quicksort(a, low, high);
    cout << "After sorting:\n";
    display(a, high);
    return 0;
}