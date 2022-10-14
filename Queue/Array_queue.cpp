#include <iostream>
using namespace std;

// Defining the size of the queue here
#define SIZE 5

// We are using array as base for queue data structure 
int items[SIZE], rear = -1, front = -1;

// For adding elements to the queue.
// it follows FIFO concept that is first in first out.
// We use two variables as pointers in this data structure.
// For adding the rear variable gets increased and for deleting front variable get increased.
void enQueue(int value)
{
    if (front == 0 && rear == SIZE - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        items[rear] = value;
        cout << "Inserted -> " << items[rear] << endl;
    }
}

// For removing elements from the circular queue
void deQueue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Deleted -> " << items[front] << endl;
        front = front + 1;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Displaying of the circular queue
void Display()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue elements are : " << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << items[i] << " ";
        }
    }
}

int main()
{
    enQueue(4);
    enQueue(7);
    enQueue(8);
    enQueue(45);
    Display();
    deQueue();
    Display();
}