#include <iostream> //header file
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

void inorder_traversal(node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void deletion(node **root, int key)
{

    node *n;
    n = search(*root, key);
    if (n != NULL)
    {
        node *x;
        x = *root;
        node *prev = NULL;
        while (x->data != key)
        {
            prev = x;
            if (x->data > key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        if (x->data > prev->data)
        {
            prev->right = x->right;
            node *i;
            i = x->right;
            i->left = x->left;
        }
        else
        {
            prev->left = x->left;
            node *i;
            i = x->left;
            i->right = x->right;
        }
        delete x;
    }
    else
    {
        cout << key << " not found\n";
        return;
    }
}

int main()
{
    node *root, *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
    root = createnode(8);
    n1 = createnode(3);
    n2 = createnode(10);
    n3 = createnode(1);
    n4 = createnode(6);
    n5 = createnode(4);
    n6 = createnode(7);
    n7 = createnode(14);
    n8 = createnode(13);

    root->right = n2;
    root->left = n1;

    n1->right = n4;
    n1->left = n3;

    n4->right = n6;
    n4->left = n5;

    n2->right = n7;
    n7->left = n8;

    cout << "Before deletion:\n";
    inorder_traversal(root);

    deletion(&root, 3);
    cout << "After deletion:\n";
    inorder_traversal(root);
    return 0;
}
