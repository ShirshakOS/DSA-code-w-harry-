// mergesort algo

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

void mergesort(int *a, int low, int high, int mid)
{
    int i = low;
    int j = mid + 1;
    int index = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[index] = a[i];
            i++;
            index++;
        }
        else
        {
            b[index] = a[j];
            index++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[index] = a[i];
        index++;
        i++;
    }
    while (j <= high)
    {
        b[index] = a[j];
        j++;
        index++;
    }
    for (int x = 0; x <= index; x++)
    {
        a[x] = b[x];
    }
}

int main()
{
    int a[] = {1, 3, 5, 2, 4, 6};
    int n = 6;
    cout << "Before sort:\n";
    display(n, a);
    cout << "After sort:\n";
    mergesort(a, 0, n - 1, 2);
    display(n, a);
    return 0;
}
