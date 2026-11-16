#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void inorderTraversal(node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

node *createnode(int data)
{
    node *n;
    n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *search(node *root, int key)
{
    if (root == NULL) // base conditions
    {
        return NULL;
    }
    if (root->data == key) // base conditions
    {
        return root;
    }
    else if (key < root->data) // key is lesser than root? check the left subtree of the root
    {
        return search(root->left, key);
    }
    else // key is greater than root? check the right subtree of the root
    {
        return search(root->right, key);
    }
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

    inorderTraversal(root);

    node *find1, *find2;
    find1 = search(root, 7);
    find2 = search(root, 90);

    if (find1 != NULL)
    {
        cout << "\nFound: " << find1->data << endl;
    }
    else
    {
        cout << "Element not found\n";
    }

    if (find2 != NULL)
    {
        cout << "Found: " << find2->data << endl;
    }
    else
    {
        cout << "Element not found\n";
    }
    return 0;
}