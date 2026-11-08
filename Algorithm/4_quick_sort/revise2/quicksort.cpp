// quicksort ascending sorting algorithm
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

int partition(int *a, int low, int high)
{
    int pivot = a[low], i = low + 1, j = high;
    do
    {
        while (a[i] <= pivot && i <= high)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    int temp = a[j];
    a[j] = a[low];
    a[low] = temp;

    return j;
}

void quicksort(int *a, int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(a, low, high);
        quicksort(a, low, partitionindex - 1); // sort the left side of the partition index
        quicksort(a, partitionindex + 1, high);
    }
}

int main()
{
    int a[] = {2, 4, 3, 9, 1, 7, 6, 8, 5}, n = 9;
    cout << "Before sorting:\n";
    display(n, a);
    cout << "After sorting:\n";
    quicksort(a, 0, n - 1);
    display(n, a);
    return 0;
}