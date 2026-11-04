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

void selectionsort(int n, int *a)
{
    int i, j, key, track;
    for (i = 0; i < n - 1; i++)
    {
        key = a[i];
        track = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < key)
            {
                key = a[j];
                track = j;
            }
        }
        a[track] = a[i];
        a[i] = key;
    }
}

int main()
{
    int a[] = {4, 1, 43, 55, 82, 82, 0};
    int n = 7;

    cout << "Before sorting:\n";
    display(n, a);
    cout << "After sorting:\n";
    selectionsort(n, a);
    display(n, a);
    return 0;
}