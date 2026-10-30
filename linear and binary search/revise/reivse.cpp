// linear search
#include <iostream>
using namespace std;
int linearsearch(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {21, 32, 1, 3, 24, 2, 1, 32, 3, 66};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 2;
    int index = linearsearch(arr, size, num);
    cout << "Index of " << num << " is: " << index << endl;
    return 0;
}