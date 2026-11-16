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

void traversalInorder(node *root)
{
    if (root != NULL)
    {
        traversalInorder(root->left);
        cout << root->data << " ";
        traversalInorder(root->right);
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

void insert_in_BST(node **root, int key)
{
    node *find;
    find = search(*root, key);
    if (find != NULL)
    {
        cout << "The element is already present in the BST\n";
    }
    else
    {
        if (root == NULL)
        {
            cout << "Empty tree\n";
            return;
        }
        node *x;
        x = *root;
        node *n;
        n = createnode(key);
        node *prev;
        while (x != NULL)
        {
            prev = x;
            if (x->data < key)
            {
                x = x->right;
            }
            else
            {
                x = x->left;
            }
        }
        x = n;
        if (prev->data > key)
        {
            prev->left = x;
        }
        else
        {
            prev->right = x;
        }
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

    cout << "Before insertion:\n";
    traversalInorder(root);

    cout << "\nAfter insertion:\n";
    insert_in_BST(&root, 9);
    traversalInorder(root);

    return 0;
}