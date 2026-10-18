//ARRAY AS AN ABSTRACT DATA TYPE(ADT)
#include <iostream>
using namespace std;
struct myArray
{
    int totalsize;
    int usedsize;
    int *p; // used as integer array so allocate size this pointer
};
void createArray(struct myArray *a, int totalsize, int usedsize)
{
    a->totalsize = totalsize;
    a->usedsize = usedsize;
    a->p = new int[totalsize];
}
void show(myArray *a, int usedsize)
{
    int i;
    for(i=0;i<usedsize;i++)
    {
        cout<<a->p[i]<<" ";
    }
}

void get(myArray *a,int usedsize)
{
    int i;
    for(i=0;i<usedsize;i++)
    {
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>a->p[i];
    }
}

int main()
{
    int totalsize, usedsize;
    cout << "Enter size of the array: ";
    cin >> totalsize;
    cout << "Enter size to be used: ";
    cin >> usedsize;
    myArray A;
    createArray(&A, totalsize, usedsize);
    get(&A, usedsize);
    show(&A, usedsize);
    return 0;
}
