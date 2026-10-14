// array as abstract data type using class
#include <iostream>
using namespace std;
class myArray
{
    int usedsize, totalsize, *ptr;

public:
    void createArray(int tsize, int usize)
    {
        usedsize = usize;
        totalsize = tsize;
        ptr = new int[tsize];
    }
    void getArray()
    {
        int i;
        cout << "\nEnter elements: \n";
        for (i = 0; i < usedsize; i++)
        {
            cout << "NUM " << i + 1 << ": ";
            cin >> ptr[i];
        }
    }
    void showArray()
    {
        int i;
        cout << "\nThe elements are:\n";
        for (i = 0; i < usedsize; i++)
        {
            cout << ptr[i] << " ";
        }
    }
};
int main()
{
    myArray A;
    A.createArray(100, 5);
    A.getArray();
    A.showArray();
    return 0;
}