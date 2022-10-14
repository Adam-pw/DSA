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
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            count++;
        }
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
            count++;
        }
    }
    cout << "No of Vowels are " << count << endl;
}

int main()
{
    char a[] = "Hello Adam";
    cout << a << endl;
    Length(a);
    Countingvowels(a);
}