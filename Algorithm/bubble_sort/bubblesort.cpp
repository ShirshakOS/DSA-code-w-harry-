#include <iostream>
using namespace std;

void printArray(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubblesort(int n, int *a)
{
    int temp;
    int issorted = 1;
    for (int i = 0; i < n - 1; i++) // for the number of passes
    {
        cout << "Working on pass number " << i + 1 << endl;
        for (int j = 0; j < n - 1 - i; j++) // for comparision in each pass
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}

int main()
{
    // int a[] = {1, 2, 3, 4, 5, 6, 7}; // sorted
    int a[] = {18, 7, 21, 19, 2, 6, 10}; // unsorted
    int n = 7;
    cout << "Before Bubble Sort:\n";
    printArray(n, a);
    bubblesort(n, a);
    cout << "After Bubble Sort:\n";
    printArray(n, a);
    return 0;
}