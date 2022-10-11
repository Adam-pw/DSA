#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void Push(int value)
{
    struct Node *q;
    q = new Node;
    if (q == NULL)
    {
        cout << "Stack is overflowed" << endl;
    }
    else
    {
        q->data = value;
        q->next = head;
        head = q;
        cout << q->data << " is pushed into the stack" << endl;
    }
}

int Pop()
{
    struct Node *t;
    int x;

    if (head == NULL)
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        t = head;
        head = head->next;
        x = t->data;
        cout << x << " is removed from the stack" << endl;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *q;
    q = head;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Pop();
    Display();

    cout << endl << "By Adam Pithenwala" << endl;
    return 0;
}