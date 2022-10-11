#include <iostream>
using namespace std;

// Stack Data structure using three vairables size top and an array
// Stack use FIFO (First in First out) rule  
struct Stack
{
    int size;
    int top;
    int *S;
};

// This functions creates the stack by entering the size and initialising the array;
void Create(struct Stack *St)
{
    cout << "Enter Size = ";
    cin >> St->size;
    cout << "Stack is created with size " << St->size << endl;
    St->top = -1;
    St->S = new int[St->size];
}

// Displays the stack 
void Display(struct Stack St)
{
    int i;
    for (i = St.top; i >= 0; i--)
    {
        cout << St.S[i] << " ";
    }
    cout << endl;
}

// This function Pushes the value in the stack 
void Push(struct Stack *St, int value)
{
    if (St->top == St->size - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        St->top++;
        St->S[St->top] = value;
        cout << value << " is pushed into stack" << endl;
    }
}

// Pops the value from the stack that is the last element which was inserted will be removed
int Pop(struct Stack *St)
{
    int x;
    if (St->top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        x = St->S[St->top];
        St->top--;
        cout << x <<" was removed" << endl;
    }
    return x;
}

// Returns the value of the index which is given
int Peek(struct Stack *St, int index)
{
    int x;
    x = St->S[St->top - index + 1];
    return 0;
}

int IsEmpty(struct Stack *St)
{
    if (St->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct Stack *St)
{
    return St->top == St->size - 1;
}

int main()
{
    struct Stack St;
    Create(&St);
    Push(&St, 54);
    Push(&St, 96);
    Push(&St, 63);
    Pop(&St);
    Push(&St, 79);
    Display(St);

    cout << endl << "By Adam Pithenwala" << endl;
    return 0;
}