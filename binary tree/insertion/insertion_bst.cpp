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

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void insert(node **root, int key)
{
    node *find;
    node *n;
    node *x;
    x = *root;
    find = search(*root, key); // check if there is a duplicate node
    if (find == NULL)          // no duplicate node
    {
        n = createnode(key);
        node *prev = NULL;
        while (x != NULL)
        {
            prev = x;
            if (key < x->data)
            {
                x = x->left;
            }
            else if (key > x->data)
            {
                x = x->right;
            }
        }
        x = n;
        if (key < prev->data)
        {
            prev->left = x;
        }
        else
        {
            prev->right = x;
        }
    }
    else
    {
        cout << "Element already exists in the binary search tree\n";
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
    inorder(root);

    cout << "\nAfter insertion:\n";
    insert(&root, 1);
    inorder(root);

    return 0;
}