#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int data)
{
    node *p;
    p = new node;
    p->data = data;
    p->right = NULL;
    p->left = NULL;
    return p;
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    /*
         4 root
        /\
    p1 1  6 p2
      /\
  p3 5  2  p4
    */

    node *root, *p1, *p2, *p3, *p4;
    root = createNode(4);
    p1 = createNode(1);
    p2 = createNode(6);
    p3 = createNode(5);
    p4 = createNode(2);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    postOrder(root);

    return 0;
}