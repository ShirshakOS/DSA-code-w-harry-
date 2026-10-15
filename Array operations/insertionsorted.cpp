// insert in sorted array
// binary search self written algorithm
#include <iostream>
using namespace std;
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
void insert(int ori[], int cpy[], int size, int num)
{
    int countindex[size];
    for (int i = 0; i < size; i++)
    {
        cpy[i] = ori[i];
        countindex[i] = 0;
    }

    int index;
    index = (cpy[0] + cpy[size - 1]) / 2;
    countindex[index]++;
    while (true)
    {
        if (cpy[index] > num)
        {
            index = (cpy[0] + cpy[index]) / 2;
            countindex[index]++;
            if (countindex[index] == 3)
            {
                index++;
                break;
            }
        }
        else if (cpy[index] < num)
        {
            index = (cpy[index] + cpy[size - 1]) / 2;
            countindex[index]++;
            if (countindex[index] == 3)
            {
                index++;
                break;
            }
        }
    }
    for (int i = size + 1; i >= index; i--)
    {
        ori[i + 1] = ori[i];
    }
    ori[index] = num;
}
int main()
{
    cout<<"hi"<<endl;
    int a[100] = {1, 2, 3, 4, 5, 6, 8,9};
    int dummy[100];
    insert(a, dummy, 8 , 7);
    display(a, 9);
    return 0;
}