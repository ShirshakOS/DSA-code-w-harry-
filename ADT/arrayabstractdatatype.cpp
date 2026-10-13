// array as abstract data type
#include <iostream>
using namespace std;
struct myArray
{
    int size;
    int usedsize;
    int *ptr; // we use this integer pointer as the array
};
void createArray(myArray *a, int size, int usedsize)
{
    a->size = size;
    a->usedsize = usedsize;
    a->ptr = new int[usedsize];
}
void showArray(myArray *a, int usedsize)
{
    cout << "Elements of the array:\n";
    int i;
    for (i = 0; i < usedsize; i++)
    {
        cout << a->ptr[i] << " ";
    }
}
void getArray(myArray *a, int used)
{
    cout << "\nEnter the elements of the array:\n ";
    int i;
    for (i = 0; i < used; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> a->ptr[i];
    }
}
int main()
{
    myArray a;
    int total_size = 90;
    int used_size = 5;
    createArray(&a, total_size, used_size);
    getArray(&a, used_size);
    showArray(&a, used_size);
    return 0;
}
