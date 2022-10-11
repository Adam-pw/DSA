#include <iostream>
using namespace std;

// Creating a doubly linked list which contains address of two nodes one of previous and one of next
// With doubly linked list we can treverse in both the directions
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *first = NULL;

// Create function for doubly linked list
void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Display function for doubly linked list
void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Finding length of the doubly linked list
int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Insert at any poistion in Doubly linked list
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > Length(p))
    {
        return;
    }
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

// Delete function for doubly linked list
int Delete(struct Node *p, int index)
{
    int x = -1, i;

    if (index == 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;

            x = p->data;
            free(p);
        }
        else
        {
            for (i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            if (p->next)
            {
                p->next->prev = p->prev;
            }
            x = p->data;
            free(p);
        }
        return x;
    }
}

int main()
{
    int Arr[] = {12, 24, 36, 49, 57, 68};
    Create(Arr, 6);
    Display(first);
    
    Insert(first,4,96); 
    cout << endl;
    Display(first);

    Delete(first,5);
    cout << endl;
    Display(first);
}