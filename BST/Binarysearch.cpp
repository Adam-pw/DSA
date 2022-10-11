#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
} *root = NULL;

void insert(int key)
{
    Node *t = root;
    Node *r, *p;
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
    }
    else
    {
        while (t != NULL)
        {
            r = t;
            if (key < t->data)
            {
                t = t->lchild;
            }
            else if (key > t->data)
            {
                t = t->rchild;
            }
            else
            {
                return;
            }
        }
        p = new Node;
        p->data = key;
        if (key < r->data)
        {
            r->lchild = p;
        }
        else if (key > r->data)
        {
            r->rchild = p;
        }
    }
}

void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void search(int key)
{
    Node *t = root;
    while (t != NULL)
    {
        if (t->data == key)
        {
            cout << "element found " << key << endl;
            return;
        }
        else if (t->data > key)
        {
            t = t->lchild;
        }
        else if (t->data < key)
        {
            t = t->rchild;
        }
    }
    cout << "element not found" << endl;
}

Node *Rinsert(Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
}
int main()
{
    root = Rinsert(root, 45);
    Rinsert(root, 4);
    Rinsert(root, 89);
    Rinsert(root, 56);
    Rinsert(root, 5);
    inorder(root);
    cout << endl;
    search(14);
    return 0;
}