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

node *inorderpredecessor(node *root)
{
    root = root->left;
    while (root != NULL)
    {
        root = root->right;
    }
    return root;
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

node *deletenode(node *root, int key)
{
    node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL && root->left == NULL && root->data == key)
    {
        delete root;
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}

int main()
{
    node *root, *n1, *n2, *n3, *n4;
    root = createnode(5);
    n1 = createnode(3);
    n2 = createnode(6);
    n3 = createnode(1);
    n4 = createnode(4);

    root->right = n2;
    root->left = n1;

    n1->right = n4;
    n1->left = n3;

    cout << "Before deletion:\n";
    inorder(root);

    deletenode(root, 1);

    cout << "After deletion:\n";
    inorder(root);
    return 0;
}
