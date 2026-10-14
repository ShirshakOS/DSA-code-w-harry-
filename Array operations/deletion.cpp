// deletion operation in array
#include <iostream>
using namespace std;
void deletion(int a[], int num, int size);
void show(int a[], int size);
int main()
{
    int size = 8;
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int num = 7; 
    deletion(a, num, size);
    size--;
    show(a, size);
    return 0;
}
void deletion(int a[], int num, int size)
{
    int index;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == num)
        {
            index = i;
        }
    }
    for (int i = index; i < size; i++)
    {
        a[i] = a[i + 1];
    }
}
void show(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}