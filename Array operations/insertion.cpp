#include <iostream>
using namespace std;
void display(int arr[], int n)
{
    // code for traversal on array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int insert(int arr[], int size, int capacity, int index, int num)
{
    if (size >= capacity)
    {
        return -1;
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = num;
        return 1;
    }
}
int main()
{
    int a[100] = {2, 5, 11, 1, 44};
    int size = 5, index = 2, num = 900;
    display(a, size);
    insert(a, size, 100, index, num);
    size++;
    display(a, size);
    return 0;
}