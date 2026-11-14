// left-right-root
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

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{

    /*
            4
            /\
           2  5
           /\
          3  1
    */
    node *root, *n1, *n2, *n3, *n4;
    root = createnode(4);
    n1 = createnode(2);
    n2 = createnode(5);
    n3 = createnode(1);
    n4 = createnode(3);

    root->right = n2;
    root->left = n1;

    n1->right = n3;
    n1->left = n4;

    postorder(root);

    return 0;
}