#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void EnQueue(int x)
{
    struct Node *q;
    q = new Node;
    if (q == NULL)
    {
        cout << "Memory overflow" << endl;
    }
    else
    {
        q->data = x;
        q->next = NULL;
        if (front == NULL)
        {
            front = rear = q;
        }
        else
        {
            rear->next = q;
            rear = q;
        }
    }
}

int DeQueue()
{
    struct Node *q;
    int x = -1;
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        x = front->data;
        q = front;
        front = front->next;
        free(q);
    }
    return x;
}

void Display()
{
    struct Node *q;
    q = front;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);

    Display();
    DeQueue();
    Display();
}