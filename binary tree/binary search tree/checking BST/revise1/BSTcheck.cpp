#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
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

void inorder_traversal(node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

int isBST(node *root)
{
    static node *prev = NULL; // prev should not change with every different function call
    if (root != NULL)
    {
        if (!isBST(root->left)) // tracks the left node until the end of Binary tree
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) // checks whether the inorder's previous element is lesser or not
        {
            return 0; // if root's node is greater than the previous one then its not strictly in ascending so return 0 because it's not a BST
        }
        prev = root;
        return (isBST(root->right)); // tracks the right node of the binary tree until NULL
    }
    else
    {
        return 1;
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

    inorder_traversal(root);

    cout << endl;

    if (isBST(root))
    {
        cout << "The Binary tree is BST!";
    }
    else
    {
        cout << "The Binary Tree is not BST!";
    }

    return 0;
}