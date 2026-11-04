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
    int indexofmin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;
    }
}

int main()
{
    int a[] = {32, 43, 12, 64, 8};
    int n = 5;
    cout << "Before sorting:\n";
    display(n, a);
    selectionsort(n, a);
    cout << "After sorting:\n";
    display(n, a);
    return 0;
}