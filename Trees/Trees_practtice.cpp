#include <iostream>
using namespace std;

// Creating node for tree data structure
// Tree data structure has node, edge and child nodes connected to it
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode(int value)
{
    struct Node *newNode = new Node;
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

struct Node *InsertRight(int value, struct Node *root)
{
    root->right = CreateNode(value);
    return root->right;
}

struct Node *InsertLeft(int value, struct Node *root)
{
    root->left = CreateNode(value);
    return root->left;
}

int main()
{
    
}