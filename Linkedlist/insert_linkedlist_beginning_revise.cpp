#include <iostream>
using namespace std;

// creating structure of node
struct node
{
    int data;
    node *next;
};

// Creating a function to traverse through the linked list
void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// function to return the updated head node
node *insert_beginning(int data, node *head)
{
    // creating a node to store updated data
    node *update;

    // allocating memory dynamically for update node
    update = new node;

    // assiging new data to new head and linking its next reference to the former head
    update->data = data;
    update->next = head;

    return update;
}

int main()
{
    node *topper;
    node *fifth;
    node *third;
    node *second;
    node *last;

    // allocating memory for all nodes dynamically
    topper = new node;
    fifth = new node;
    third = new node;
    second = new node;
    last = new node;

    // linking..

    // topper node to second node
    topper->data = 3;
    topper->next = second;

    // second node to third node
    second->data = 1;
    second->next = third;

    // third node to fifth node
    third->data = 100;
    third->next = fifth;

    // fifth node to last node
    fifth->data = 211;
    fifth->next = last;

    // terminate last node
    last->data = 9090;
    last->next = NULL;

    // traverse before update
    cout << "BEFORE UPDATE:\n";
    traverse(topper);

    topper = insert_beginning(1, topper);

    cout << "After update: \n";
    traverse(topper);

    return 0;
}