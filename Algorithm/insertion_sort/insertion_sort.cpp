#include<iostream>
using namespace std;

void insertionsort(int n, int *a)
{
    int i,j;
    int key;
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=a[i];
        while(j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void display(int n, int *a)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[] = {18, 7, 21, 19, 2, 6, 10};
    int n = 7;

    insertionsort(n,a);
    display(n,a);

    return 0;
}