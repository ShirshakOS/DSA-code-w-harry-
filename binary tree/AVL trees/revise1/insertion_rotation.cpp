#include <iostream>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
    int height; // for avl tree
};

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int getheight(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return (n->height);
    }
}

node *createnode(int data)
{
    node *n;
    n = new node; // memory allocation
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    n->height = 1;
    return n;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getbalancefactor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return (getheight(n->right) - getheight(n->left));
    }
}

node *rotateright(node *x)
{
    node *y = x->left, *t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = 1 + max(getheight(x->right), getheight(x->left));
    y->height = 1 + max(getheight(y->right), getheight(y->left));

    return y;
}

node *rotateleft(node *y)
{

    // set before rotated tree

    node *x = y->right, *t2 = x->left;

    // left rotate the tree
    x->left = y;
    y->right = t2;

    x->height = 1 + max(getheight(x->right), getheight(x->left));
    y->height = 1 + max(getheight(y->right), getheight(y->left));

    return x;
}

node *insert(node *n, int data)
{
    if (n == NULL)
    {
        return createnode(data);
    }
    if (n->data < data)
    {
        n->right = insert(n->right, data);
    }
    else if (n->data > data)
    {
        n->left = insert(n->left, data);
    }
    n->height = 1 + max(getheight(n->left), getheight(n->right));
    int bf = getbalancefactor(n);

    // left left rotation
    if (bf < -1 && data < n->left->data)
    {
        return (rotateright(n));
    }
    // right right rotation
    if (bf > 1 && data > n->right->data)
    {
        return rotateleft(n);
    }
    // left right rotation
    if (bf < -1 && data > n->left->data)
    {
        n->left = rotateleft(n->left);
        return rotateright(n);
    }

    // right left rotation
    if (bf > 1 && data < n->right->data)
    {
        n->right = rotateright(n->right);
        return rotateleft(n);
    }

    return n;
}

int main()
{
    node *root = NULL;
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 18);
    preorder(root);
    return 0;
}
