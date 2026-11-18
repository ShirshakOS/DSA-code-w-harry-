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

void traversal_inorder(node *root)
{
    if (root != NULL)
    {
        traversal_inorder(root->left);
        cout << root->data << " ";
        traversal_inorder(root->right);
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
    n = search(*root, key); //search the node to check if the node exists
    if (n != NULL) //run this loop of the node exists(i.e the search function returns NULL)
    {
        if (root == NULL) // for handling empty tree
        {
            cout << "Empty tree\n";
            return;
        }
        node *prev, *n;
        n = *root;
        while (n->data != key) // run the loop until the data of current node is equal to the value of key
        {
            prev = n; // also track the node previous to the current node
            if (n->data > key) // if the key is less than the data of current node then go to the left node
            {
                n = n->left;
            }
            else // else go to the right node
            {
                n = n->right;
            }
        }

        // by the time loop ends we are in the leaf node that we want to delete

        if (key < prev->data)  //if the data of the previous node is greater than key then set the left of previous node to NULL
        {
            prev->left = NULL;
        }
        else // if the data of the previous node is lesser than key then set the right of the previous node to NULL
        {
            prev->right = NULL;
        }
        delete n; // deallocate the memory of node that we want to delete
    }
    else //if the node doesn't exists(i.e the search function returns NULL)
    {
        cout << key << " not found in the binary search tree\n";
        return;
    }
}

int main()
{

                /*
                         8
                        /\
                       3  10
                      /\   \
                     1 6   14
                      /\   /
                     4 7  13
                */
    node *root, *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
    root = createnode(8);
    n1 = createnode(1);
    n2 = createnode(3);
    n3 = createnode(4);
    n4 = createnode(6);
    n5 = createnode(7);
    n6 = createnode(10);
    n7 = createnode(14);
    n8 = createnode(13);

    root->right = n6;
    root->left = n2;
    n2->right = n4;
    n2->left = n1;
    n4->right = n5;
    n4->left = n3;
    n6->right = n7;
    n7->left = n8;

    cout << "Before deletion:\n";
    traversal_inorder(root);

    deletion(&root, 4);

    cout << "After deletion:\n";
    traversal_inorder(root);

    return 0;
}