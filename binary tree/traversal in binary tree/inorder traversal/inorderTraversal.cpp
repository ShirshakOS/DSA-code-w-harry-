#include <iostream>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
};

node *createnode(int data)
{
    node *n;
    n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    node *root, *n1, *n2, *n3, *n4;
    root = createnode(4);
    n1 = createnode(1);
    n2 = createnode(6);
    n3 = createnode(5);
    n4 = createnode(2);

    root->right = n2;
    root->left = n1;

    n1->right = n4;
    n1->left = n3;

    inOrder(root);

    return 0;
}