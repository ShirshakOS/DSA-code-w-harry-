// checking if the binary tree is binary search tree or not

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
    n->right = NULL;
    n->left = NULL;
    return n;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{
    node *root, *n1, *n2, *n3, *n4;
    root = createnode(9);
    n1 = createnode(4);
    n2 = createnode(11);
    n3 = createnode(2);
    n4 = createnode(5);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    // inorder(root);
    inorder(root);
    cout << endl;

    node *n;
    n = search(root, 5);

    if (n != NULL)
    {
        cout << "Found: " << n->data << endl;
    }
    else
    {
        cout << "Element not found!";
    }
    return 0;
}