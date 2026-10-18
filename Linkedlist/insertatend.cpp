// insert a node at the end of linkedlist
#include <iostream>
using namespace std;

//defining the node structure
struct node
{
    int data;
    struct node *next; // self referencing structure
};

// define the function to insert a new node at the end and return the head node pointer
struct node *insertatend(int data, struct node *head)
{
    struct node *newnode;
    newnode = new node; //Allocate memory  for the new node

    struct node *ptr;

    ptr = head; // start traversal from the head

    //traverse until the last node is reached
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    //initialize the new node and link it to the last node
    newnode->data = data;
    newnode->next = NULL;
    ptr->next = newnode;

    return head; // return the head of the updated list
}

// define the function to traverse and display the list
void traverse(struct node *ptr)
{
    // Run the loop until the last node is reached
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next; // move to the next node
    }
}

//main function to create a linked list and test insertion
int main()
{
    struct node *head, *second, *third;

    // allocate memory for three nodes on the heap
    head = new node;
    second = new node;
    third = new node;

    //initialize node data and establish links
    head->data = 3;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 22;
    third->next = NULL;

    cout << "Before update:\n";
    traverse(head);

    head = insertatend(88, head);

    cout << "After update:\n";
    traverse(head);

    return 0;
}