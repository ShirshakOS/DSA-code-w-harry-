// quick sort sorting algorithm

#include<iostream>
using namespace std;

void display(int n, int *a)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<< " ";
    }
    cout<<endl;
}

int partition(int *a, int low, int high)
{
    int pivot=a[low], i=low+1, j=high;
    do{
        while(i<=high && a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    while(i<j);
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quicksort(int *a, int low, int high)
{
    int partitionindex;
    if(low<high)
    {
        partitionindex=partition(a,low,high);
        quicksort(a,low,partitionindex-1);
        quicksort(a,partitionindex+1,high);
    }
}

int main()
{
    int a[]={325,4132,45,3,90}, n=5;
    cout<<"Before sorting:\n";
    display(n,a);
    quicksort(a,0,n-1);
    cout<<"After sorting:\n";
    display(n,a);
    return 0;
}