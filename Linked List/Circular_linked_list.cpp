#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
} *Head = NULL;

// Creating a Circular linked list
// The only difference is its last node points to the first and creats a circle
void Create(int A[], int n)
{
  int i;
  struct Node *t, *last;
  Head = new Node;
  Head->data = A[0];
  Head->next = Head;
  last = Head;

  for (i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = last->next;
    last->next = t;
    last = t;
  }
}

// Displaying Circular linked list through do while loop
// The condition is pointer should not be equal to the head while after doing it one time
void Display(struct Node *h)
{
  do
  {
    cout << h->data << " ";
    h = h->next;
  } while (h != Head);
}

// Recursive way of displaying elements in a circular linked list
void RDisplay(struct Node *h)
{
  static int flag = 0;
  if (h != Head || flag == 0)
  {
    flag = 1;
    cout << h->data << " ";
    RDisplay(h->next);
  }
  flag = 0;
}

// Function to find out the total nodes in an circular linked list
int Length(struct Node *p)
{
  int len = 0;
  do
  {
    len++;
    p = p->next;
  } while (p != Head);
  return len;
}

// Function to insert an element at any index
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
    if (Head == NULL)
    {
      Head = t;
      Head->next = Head;
    }
    else
    {
      while (p->next != Head)
      {
        p = p->next;
      }
      p->next = t;
      t->next = Head;
      Head = t;
    }
  }
  else
  {
    for (i = 0; i < index - 1; i++)
    {
      p = p->next;
    }
    t = new Node;
    t->data = x;
    t->next = p->next;
    p->next = t;
  }
}

// Function to delete at an index
int Delete(struct Node *p, int index)
{
  struct Node *q;
  int i, x;

  if (index < 0 || index > Length(p))
  {
    return -1;
  }
  if (index == 1)
  {
    while (p->next != Head)
    {
      p = p->next;
    }
    x = Head->data;
    if (Head == p)
    {
      free(Head);
      Head = NULL;
    }
    else
    {
      p->next = Head->next;
      free(Head);
      Head = p->next;
    }
  }
  else
  {
    for (i = 0; i, index - 2; i++)
    {
      p = p->next;
    }
    q = p->next;
    p->next = q->next;
    x = q->data;
    free(q);
  }
  return x;
}

int main()
{
  int A[] = {2, 3, 4, 5, 6};
  Create(A, 5);
  Display(Head);
  cout << endl;

  RDisplay(Head);
  
  cout << endl;

  cout << Length(Head);
  cout << endl;

  Insert(Head, 2, 36);
  Display(Head);
  cout << endl;

  cout << Delete(Head,3);
  Display(Head);
  cout << endl;
}
