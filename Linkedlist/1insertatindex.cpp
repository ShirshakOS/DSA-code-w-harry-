// insert node at the given index in a linked list

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next; // self referencing structure
};

void traverse(struct node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

struct node *insertatindex(int data, int index, struct node *head)
{
    struct node *updatenode;
    updatenode=new node;

    struct node *temp;
    temp = head; //get the address of head node

    int i=0;
    while(i!=index-1)
    {
        temp=temp->next;
        i++;
    }
    updatenode->data=data;
    updatenode->next= temp->next;
    temp->next=updatenode;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;

    // allocate memory 
    head = new node;
    second = new node;
    third =  new node;
    fourth = new node;

    head->data =77;
    head ->next = second;

    second->data=31;
    second->next=third;

    third->data=67;
    third->next=fourth;

    fourth->data=88;
    fourth->next=NULL;

    cout<<"Before update:\n";
    traverse(head);

    head = insertatindex(21, 3, head);

    cout<<"After update:\n";
    traverse(head);

    return 0;
}