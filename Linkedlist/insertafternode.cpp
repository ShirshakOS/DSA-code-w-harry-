// insert a node after the given node

// header file
#include <iostream>
using namespace std;

// defining node structure
struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct node *insertafterNode(int data, struct node *PrevNode, struct node *head)
{
    struct node *newnode;
    newnode = new node; // allocate memory for new node on heap

    newnode->data = data;

    newnode->next = PrevNode->next;

    PrevNode->next = newnode;

    return head;
}

// function to create linked list and test insertion
int main()
{
    node *head, *first, *second;

    head = new node;
    first = new node;
    second = new node;

    head->data = 23;
    head->next = first;

    first->data = 33;
    first->next = second;

    second->data = 9;
    second->next = NULL;

    cout << "Before update:\n";
    traverse(head);

    head = insertafterNode(7, first, head);

    cout << "After update:\n";
    traverse(head);

    return 0;
}