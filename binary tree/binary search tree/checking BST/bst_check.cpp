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

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return (isBST(root->right));
    }
    else
    {
        return 1;
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

    cout << isBST(root);

    return 0;
}