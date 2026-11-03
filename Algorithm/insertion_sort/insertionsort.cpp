#include <iostream>
using namespace std;

void insertionsort(int n, int *a)
{
    for (int i = 1; i < n; i++) // pass runs 6 times
    {
        int j = i - 1;
        while (j >= 0)
        {
            if (a[j + 1] < a[j])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                j--;
            }
            else
            {
                break;
            }
        }
    }
}

void display(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[] = {18, 7, 21, 19, 2, 6, 10};
    int n = 7;
    insertionsort(n, a);
    display(n, a);
    return 0;
}