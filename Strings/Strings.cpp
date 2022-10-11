#include <iostream>
using namespace std;

void Length(char a[])
{
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    cout << "Length is " << i << endl;
}

void Countingvowels(char a[])
{

}

int main()
{
    char a[] = "Hello Adam";
    cout << a << endl;
    Length(a);
}