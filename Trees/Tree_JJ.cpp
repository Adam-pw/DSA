#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree {

private:
    Node* root = NULL;

public:
    
};

int main(int argc, char const *argv[])
{
    Tree T;
    return 0;
}
