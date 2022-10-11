#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
} *Head = NULL;

void Push(char x)
{
    struct Node *q;
    q = new Node;
    if (q == NULL)
    {
        cout << "Sttack is overflow";
    }
    else
    {
        q->data = x;
        q->next = Head;
        Head = q;
    }
}

char Pop()
{
    char x;
    struct Node *q;
    if (Head == NULL)
    {
        cout << "Stack is empty";
    }
    else
    {
        q = Head;
        q->data = x;
        Head = Head->next;
        free(q);
    }

    return x;
}

void Display()
{
    struct Node *q;
    q = Head;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}
int IsBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (Head == NULL)
            {
                return 0;
            }
            Pop();
        }
    }
    if (Head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

int IsOperand(char x)
{
    if (x == '-' || x == '*' || x == '+' || x == '/')
    {
        return 0;
    }
    return 1;
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int length = strlen(infix);
    postfix = new char[length];
    while (infix[i] == '\0')
    {
        cout << 1;
        if (IsOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre(infix[i]) > pre(Head->data))
            {
                Push(infix[i++]);
            }
            else
            {
                postfix[j++] = Pop();
            }
        }
    }
    while (Head != NULL)
    {
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b";
    Push('#');

    char *postfix = InToPost(infix);

    cout << postfix << endl;
    return 0;
}