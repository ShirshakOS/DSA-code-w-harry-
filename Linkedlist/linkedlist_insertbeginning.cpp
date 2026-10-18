// insert a node at the beginning of a linked list
#include <iostream>
using namespace std;

// creating linkedlist node structure using struct
struct node
{
    int data;
    node *next; // self referenceing structure
};

// traversing through linked list function
void traverse(node *ptr)
{
    while (ptr != NULL) // Run the loop until the node pointer points to the next node of the last node
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// updating head node of the linked list
node *updatehead(int data, node *head)
{
    node *newhead;
    newhead = new node;
    newhead->data = data;
    newhead->next = head;
    return newhead;
}

// main function
int main()
{
    // creating nodes of the required linked list
    node *head, *second, *third, *fourth;

    // allocating memory for the nodes in HEAP ***DYNAMICALLY***
    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    // linking nodes

    // head and second
    head->data = 32;
    head->next = second;

    // second and third
    second->data = 11;
    second->next = third;

    // third and fourtjh
    third->data = 90;
    third->next = fourth;

    // terminate the last node(fourth node)
    fourth->data = 45;
    fourth->next = NULL;

    // Traverse through the linked list and print until the end node
    cout << "---Before updating head---\n";
    traverse(head);

    head = updatehead(7, head);

    cout << "---After updating head---\n";
    traverse(head);

    return 0;
}