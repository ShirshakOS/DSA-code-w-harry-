// sorting an unsorted array in ascending order using quick sort

// put the element in the low as pivot
// compare it in such a way through out the array that the right portion of it has elements greater and left portion has elements smaller
// in other words the pivot is put in the correct position in the array if it was sorted

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
        while ( i <= high  && a[i] <= pivot ) // better than while(a[i]<=pivot && i<=high) because compiler evaluates left side of the && first
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
    } while (i <= j);

    /*int temp = pivot; // This swaps the pivot variable, not the actual pivot element in the array.
    pivot = a[j];
    a[j] = temp;*/

    int temp = a[low];
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

int main()
{
    int a[8] = {2, 1, 4, 6, 8, 5, 4, 3};
    int n = 8;
    cout << "Before quick sort:\n";
    display(n, a);
    cout << "After quick sort:\n";
    quicksort(a, 0, n - 1);
    display(n, a);
    return 0;
}