#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *P, *Temp, *second;

    P->data = 88;
    P->next = second;

    Temp = P;

    cout << "Element: " << Temp->data << endl;
    cout << "Location: " << Temp->next << endl;

    return 0;
}