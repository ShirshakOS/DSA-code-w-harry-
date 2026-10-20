// insert node at the end of linked list

#include<iostream>
using namespace std;

struct node {
    int data;
    structn node *next;
};

void traverse(struct node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

struct node *insertatend(struct node *head, int data)
{
    struct node *p,*ptr;
    ptr=new head;
    ptr->data=data;

    p=head;
    while(p!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    
    return head;
}

int main()
{
    struct node *head, *second, *third;

    head = new node;
    second = new node;
    third = new node;

    head->data=3;
    head->next=second;

    second->data=1;
    second->next=third;
    
    third->data=9;
    third->next=NULL;

    cout<<"Before insertion:\n";
    traverse(head);

    head = insertatend(head, 99);

    cout<<"After insertion:\n";
    traverse(head);

    return 0;
}