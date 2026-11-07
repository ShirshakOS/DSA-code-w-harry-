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
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do
    {
        /*
        THIS CODE GAVE CORRECT OUTPUT ONLY BECAUSE THE ARRAY WENT OUT OF BOUND AND LUCKILY THE MEMORY CONTAINED VALUE GREATER THAN PIVOT
        while (a[i] <= pivot) 
        {
            i++;
        }*/
        while (a[i] <= pivot && i<=high) // corrected
        {
            i++;
        }
        while (a[j] > pivot ) //a[j]>pivot where pivot=a[0] code itself doesn't let j go beyond the bound
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
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
        quicksort(a, low, partitionindex - 1);  // sort left subarray
        quicksort(a, partitionindex + 1, high); // sort right subarray
    }
}

int main()
{
    int a[] = {9,4,4,8,7,6};
    int n = 6;

    cout << "Before:\n";
    display(n, a);

    quicksort(a, 0, n - 1);
    cout << "After: " << endl;
    display(n, a);
    return 0;
}