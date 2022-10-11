#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = first;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Rotate(struct Node *p)
{
    struct Node *q;
    q = p->next;
    first = q;
}

int Length(struct Node *p)
{
    int count = 0;
    do
    {
        p = p->next;
        count++;
    } while (p != first);
    return count;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *q;
    q = new Node;
    q->data = x;
    if (index == 0)
    {
        q->next = first->next;
        first = q;
    }
    else
    {
        if (index == Length(first))
        {
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
            q->next = first;
            p->next = q;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
            q->next = p->next;
            p->next = q;
        }
    }
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != first);
}

int main()
{
    int Arr[] = {7, 4, 8, 6, 4};
    Create(Arr, 5);
    Display(first);
    cout << endl;
    // Rotate(first);
    Insert(first, 5, 8);
    Display(first);
}