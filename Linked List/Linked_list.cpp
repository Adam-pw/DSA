#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
} *first = NULL, *newone = NULL;

// This converts a array into linked list
// taking arguments as array and its length
// The new linked list can be created every time using a new global pointer
void create(int A[], int n)
{             
  int i;
  struct Node *t, *last;
  first = new Node();
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++)
  {
    t = new Node();
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

// This function display's all the elements in the linked list
// There are two function one with while loop and other with the recursive
// function
void Display(struct Node *p)
{
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
}

void RDisplay(struct Node *p)
{
  if (p != NULL)
  {
    RDisplay(p->next);
    cout << p->data << " ";
  }
}

// This functions counts the node present in a linked list
int Count(struct Node *p)
{
  int c = 0;
  while (p != NULL)
  {
    c++;
    p = p->next;
  }
  return c;
}

int RCount(struct Node *p)
{
  int x = 0;
  if (p)
  {
    x = RCount(p->next);
    return x + 1;
  }
  else
  {
    return 0;
  }
}

// This functions sums up the elements in alinked list
int Sum(struct Node *p)
{
  int sum = 0;
  while (p != NULL)
  {
    sum = sum + p->data;
    p = p->next;
  }
  return sum;
}

int RSum(struct Node *p)
{
  if (p == NULL)
  {
    return 0;
  }
  else
  {
    return RSum(p->next) + p->data;
  }
}

// This functions finds the maximum number in the linked list
int Max(struct Node *p)
{
  int max = INT16_MIN;
  while (p)
  {
    if (p->data > max)
    {
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

int RMax(struct Node *p)
{
  int x = 0;
  if (p == NULL)
  {
    return INT16_MIN;
  }
  else
  {
    x = RMax(p->next);
    if (x > p->data)
    {
      return x;
    }
    else
    {
      return p->data;
    }
  }
}

// This functions finds the maximum number in the linked list
int Min(struct Node *p)
{
  int min = INT16_MAX;
  while (p)
  {
    if (p->data < min)
    {
      min = p->data;
    }
    p = p->next;
  }
  return min;
}

int RMin(struct Node *p)
{
  int x = 0;
  if (p == NULL)
  {
    return INT16_MAX;
  }
  else
  {
    x = RMin(p->next);
    if (x < p->data)
    {
      return x;
    }
    else
    {
      return p->data;
    }
  }
}

// This function searches elements linearly
Node *Search(struct Node *p, int key)
{
  while (p != NULL)
  {
    if (key == p->data)
    {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

Node *RSearch(struct Node *p, int key)
{
  if (p == NULL)
  {
    return NULL;
  }
  if (key == p->data)
  {
    return p;
  }
  return Search(p->next, key);
}

// This Functions first searches the elements in the linked list and place it
// at the first or front. This functions also uses two pointers nto access and
// compare pervious element
Node *Moving_an_element_to_first(struct Node *p, int key)
{
  Node *q = NULL;
  while (p != NULL)
  {
    if (key == p->data)
    {
      q->next = p->next;
      p->next = first;
      first = p;
    }
    q = p;
    p = p->next;
  }

  return NULL;
}

// This functions inserts at any position in the linked list
// Whether its first or last.
void Insert(int pos, int x)
{
  struct Node *p, *t;
  if (pos == 0)
  {
    t = new Node;
    t->data = x;
    t->next = first;
    first = t;
  }
  else if (pos > 0)
  {
    p = first;
    for (int i = 0; i < pos - 1 && p; i++)
    {
      p = p->next;
    }
    if (p)
    {
      t = new Node;
      t->data = x;
      t->next = p->next;
      p->next = t;
    }
  }
}

// This elemnts inserts at the last evry time
// But it uses a last pointer that is pointing to the last note
// That's why its comented out
// void InsertLast(int x)
// {
//     Node *t = new Node;
//     t->data = x;
//     t->next = NULL;
//     if (first = NULL)
//     {
//         first = last = t;
//     }
//     else
//     {
//         last->next = t;
//         last = t;
//     }
// }

// This functions inserts elements in a sorted linked list in a sorted way
void SortedInsert(struct Node *p, int x)
{
  struct Node *t, *q = NULL;
  t = new Node;
  t->data = x;
  t->next = NULL;

  if (first == NULL)
  {
    first = t;
  }
  else
  {
    while (p && p->data < x)
    {
      q = p;
      p = p->next;
    }
    if (p == first)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
  }
}

// Delete's the element of which index is passed and the pointer of which linked
// list is passed Uses two pointers and to hold the index of privous element and
// the one we are going to delete
int Delete(struct Node *p, int index)
{
  struct Node *q = NULL;
  int x = -1, i;
  if (index < 1 || index > Count(p))
  {
    return -1;
  }
  if (index == 1)
  {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  }
  else
  {
    for (i = 0; i < index - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

//  This functions checks whether a linked list is sorted or not
// Taking a argument of pointer of the linked list
int IsSorted(struct Node *p)
{
  int x = INT16_MIN;
  while (p != NULL)
  {
    if (p->data < x)
    {
      return 0;
    }
    x = p->data;
    p = p->next;
  }
  return 1;
}

// It removes the duplicates from the linked list
// Using two pointers to hold the information of two nodes at the same time
void RemoveDup(struct Node *p)
{
  struct Node *q = p->next;
  while (q != NULL)
  {
    if (p->data != q->data)
    {
      p = q;
      q = q->next;
    }
    else
    {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}

// This functions reverse the linked  list with the help of array
// It first takes input in an array then reverse them with the help of it
// It uses a array taking some space and the pointer of the linked list as
// argument
void Reverse_with_array(struct Node *p)
{
  int *A, i = 0;
  struct Node *q = p;
  A = new int[Count(p)];
  while (q != NULL)
  {
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q != NULL)
  {
    q->data = A[i];
    q = q->next;
    i--;
  }
}

// This function also reverse linked list but with the help of pointers taking
// three pointers at a time
void Reverse_with_pointers(struct Node *p)
{
  struct Node *q = NULL, *r = NULL;
  while (p != NULL)
  {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

// This functions also reverse a linked list but with recursion
// Currently not in the main programe because it takes two pointers as arguments
void Reverse_with_recursion(struct Node *q, struct Node *p)
{
  if (p)
  {
    Reverse_with_recursion(p, p->next);
    p->next = q;
  }
  else
  {
    first = q;
  }
}

// Checks whether there is a loop in linked list or not using two pointers
int IsLoop(struct Node *p)
{
  struct Node *q;
  q = p;
  do
  {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while (p && q && p != q);
  if (p == q)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  struct Node *temp;
  int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
  create(A, 8);

  cout << "Displaying Elements through while loop :- ";
  Display(first);
  cout << endl;

  cout << "Displaying Elements through recursion :- ";
  RDisplay(first);
  cout << endl;

  cout << "Countig Elements through while loop :- ";
  cout << Count(first);
  cout << endl;

  cout << "Countig Elements through recursion :- ";
  cout << RCount(first);
  cout << endl;

  cout << "Sum of elements through while loop :- ";
  cout << Sum(first);
  cout << endl;

  cout << "Sum of elements through recursion :- ";
  cout << RSum(first);
  cout << endl;

  cout << "Maximum number through while loop :- ";
  cout << Max(first);
  cout << endl;

  cout << "Maximum number through recursion :- ";
  cout << RMax(first);
  cout << endl;

  cout << "Minimum number through while loop :- ";
  cout << Min(first);
  cout << endl;

  cout << "Minimum number through recursion :- ";
  cout << RMin(first);
  cout << endl;

  cout << "Searching element through while loop :- ";
  cout << Search(first, 32);
  cout << endl;

  cout << "Searching element through recursion :- ";
  cout << RSearch(first, 32);
  cout << endl;

  // cout << "Moving an element to first node :- ";
  // Moving_an_element_to_first(first, 32);
  // Display(first);
  // cout << endl;

  cout << "Inserting an element in the linked list :- ";
  Insert(4, 98);
  Display(first);
  cout << endl;

  cout << "Inserting an element in the sorted linked list :- ";
  SortedInsert(first, 98);
  Display(first);
  cout << endl;

  cout << "Deleting an element in the linked list :- ";
  Delete(first, 5);
  Display(first);
  cout << endl;

  cout << "Checking if the linked list is sorted or not :- ";
  cout << IsSorted(first);
  cout << endl;

  cout << "Checking if the linked list is sorted or not :- ";
  cout << IsSorted(first);
  cout << endl;

  cout << "Reversing the linked list using array :- ";
  Reverse_with_array(first);
  Display(first);
  cout << endl;

  cout << "Reversing the linked list using pointers :- ";
  Reverse_with_pointers(first);
  Display(first);
  cout << endl;

  // cout << "Reversing the linked list using recursion :- ";
  // Reverse_with_recursion(first);
  // Display(first);
  // cout << endl;

  cout << endl;
  cout << "1) Display elements" << endl;
  cout << "2) Counting elements" << endl;
  cout << "3) Sum of elements" << endl;
  cout << "4) Maximum in the list" << endl;
  cout << "5) Minimum in the list" << endl;
  cout << "6) Searching an element" << endl;
  cout << "7) Moving an element to the first node" << endl;
  cout << "8) Inserting at any index" << endl;
  cout << "9) Exit" << endl;
  cout << endl;

  int n = 0;

  do
  {
    cout << "Enter then serial no of operation you want to perform" << endl;
    cin >> n;
    switch (n)
    {
    case 1:
      cout << "The Elements are =";
      cout << endl;
      Display(first);
      cout << endl;
      cout << endl;
      break;

    case 2:
      cout << "The number of elements are = ";
      cout << Count(first);
      cout << endl;
      cout << endl;
      break;

    case 3:
      cout << "The sum of elements are = ";
      cout << Sum(first);
      cout << endl;
      cout << endl;
      break;

    case 4:
      cout << "The maximum number is = ";
      cout << Max(first);
      cout << endl;
      cout << endl;
      break;

    case 5:
      cout << "The minimum number is = ";
      cout << Min(first);
      cout << endl;
      cout << endl;
      break;

    case 9:
      break;
    }

  } while (n != 9);

  return 0;
}
