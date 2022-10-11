#include <iostream>
using namespace std;

// Defining the size of the queue here
#define SIZE 5

// We are using array as base for queue data structure 
int items[SIZE], rear = -1, front = -1;

// For adding elements to the circular queue
// Circular queue is space efficient it moves back to first if first is empty and starts adding element there
void enQueue(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
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
        if (rear == front)
        {
            front = rear = -1;
        }
        cout << "Deleted -> " << items[front] << endl;
        front = (front + 1) % SIZE;
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
        cout << "Front -> " << front << endl;
        cout << "Items - >  " << endl;
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            cout << items[i] << " ";
        }
        cout << items[i] << " ";
        cout << endl;
        cout << "Rear -> " << rear << endl;
    }
}

int main()
{
  // Fails because front = -1
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
  enQueue(6);

  Display();
  deQueue();

  Display();

  enQueue(7);
  Display();

  // Fails to enqueue because front == rear + 1
  enQueue(8);

}