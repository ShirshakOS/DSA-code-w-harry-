// insert node at the begining of the linked list
#include<iostream>

using namespace std;

//create node structure
struct node{
    int data;
    node *next;
};

//update head of the linked list
node *updatehead(int data, node *head)
{
    node *newhead;
    newhead=new node;
    newhead->data=data;
    newhead->next=head;
    return newhead;
}

//traverse and print the linked list
void traverse(node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    node *head, *second, *third, *fourth;

    // allocate memory for nodes in head dynamically
    head = new node;
    second =  new node;
    third =  new node;
    fourth =  new node;

    // link nodes
     head->data=78;
     head->next = second;

     second->data=88;
     second->next=third;

     third->data=22;
     third->next=fourth;

     fourth->data=99;
     fourth->next=NULL;

     //traverse before updating linked list with new head
     cout<<"Before update:\n";
     traverse(head);

     head = updatehead(32, head);

     // traverse after updating linked list with new head
     cout<<"After update:\n";
     traverse(head);

     return 0;
}