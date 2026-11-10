#include <iostream>
#include <limits>
using namespace std;

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int maximum(int n, int *a)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countsort(int n, int *a)
{
    int i, j;
    int max = maximum(n, a);
    int *count; // count array
    count = new int[max];

    for (int x = 0; x <= max; x++) // initializing all the elements of count array to zero
    {
        count[x] = 0;
    }

    for (int x = 0; x < n; x++) // incremening the elements of count array
    {
        count[a[x]]++;
    }

    i = 0; // track the given array
    j = 0; // track the count array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            j++;
            count[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {32, 34, 45, 65, 4};
    int n = 5;

    cout << "Before:\n";
    display(n, a);

    cout << "After:\n";
    countsort(n, a);
    display(n, a);
    return 0;
}