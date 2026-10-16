// binary search in sorted array
#include <iostream>
using namespace std;
int binarysearch(int a[], int size, int num)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high) // run the loop untill low converges with high or there is no space to compare
    {
        mid = (low + high) / 2;
        if (a[mid] == num)
        {
            return mid;
        }
        if (a[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, index, size, num;
    size = sizeof(arr) / sizeof(arr[0]);
    num = 7;
    index = binarysearch(arr, size, num);
    cout << "Index of " << num << " is: " << index << endl;
    return 0;
}