#include <iostream>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
};

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node *createnode(int data)
{
    node *n;
    n = new node;
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}

node *searchIter(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    node *root, *n1, *n2, *n3, *n4, *n5, *n6;
    root = createnode(10);
    n1 = createnode(5);
    n2 = createnode(20);
    n3 = createnode(2);
    n4 = createnode(7);
    n5 = createnode(15);
    n6 = createnode(25);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    inorder(root);

    node *find;
    find = searchIter(root, 10);

    if (find != NULL)
    {
        cout << "\nFound: " << find->data << endl;
    }
    else
    {
        cout << "\nElement not found\n";
    }
    return 0;
}