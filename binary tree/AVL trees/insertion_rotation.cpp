#include <iostream>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
    int height;
};

node *createnode(int data)
{
    node *n;
    n = new node;
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    n->height = 1;
    return n;
}

int getheight(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

int getbalancefactor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return (getheight(n->left) - getheight(n->right));
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

node *rightrotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
}

node *leftrotate(node *x)
{
    node *y, *T2;
    y = x->right;
    T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    return y;
}

node *insert(node *n, int data)
{
    if (n == NULL)
    {
        return createnode(data);
    }
    if (data < n->data)
    {
        n->left = insert(n->left, data);
    }
    else if (data > n->data)
    {
        n->right = insert(n->right, data);
    }

    n->height = 1 + max(getheight(n->right), getheight(n->left));
    int bf;
    bf = getbalancefactor(n);

    // left left rotation
    if (bf > 1 && data < n->left->data)
    {
        return rightrotate(n);
    }

    // right right rotation
    if (bf < -1 && data > n->right->data)
    {
        return leftrotate(n);
    }

    // left right rotation
    if (bf > 1 && data > n->left->data)
    {
        n->left = leftrotate(n->left);
        return rightrotate(n);
    }

    // right left rotation
    if (bf < -1 && data<n->right->data)
    {
        n->right = rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
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