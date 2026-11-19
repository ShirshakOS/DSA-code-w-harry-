#include <iostream>
using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
};

void traversal_inorder(node *root)
{
    if (root != NULL)
    {
        traversal_inorder(root->left);
        cout << root->data << " ";
        traversal_inorder(root->right);
    }
}

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
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *deletenode(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == data)
    {
        delete root;
        return NULL;
    }
    node *ipre; // inorder predecesor

    // search for the node to be deleted
    if (data < root->data)
    {
        root->left = deletenode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletenode(root->right, data);
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
    /*
                5 root
                /\
            n1 3  6  n2
              /\
          n3 1  4 n4
    */
    node *root, *n1, *n2, *n3, *n4;
    root = createnode(5);
    n1 = createnode(3);
    n2 = createnode(6);
    n3 = createnode(1);
    n4 = createnode(4);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    cout << "Before deletion:\n";
    traversal_inorder(root);

    root = deletenode(root, 6);

    cout << "\nAfter deletion:\n";
    traversal_inorder(root);

    return 0;
}