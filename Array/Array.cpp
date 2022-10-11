#include <iostream>
using namespace std;

int main()
{
    // Simple creation of an array
    int A[] = {2, 4, 6, 8, 10};

    // Creating array in heap using pointer and creating dynamic memory using new keyword which is same as malloc
    int *p;
    p = new int[5];
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;

    cout << "Array in stack" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Array in heap using pointer p " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    // We can not increase the size of an array but we in heap we can create an other array greater then the privous one and we can make the pointer point to that array the example code is given below.
    int *z, *q;
    z = new int[5];
    z[0] = 2;
    z[1] = 4;
    z[2] = 6;
    z[3] = 8;
    z[4] = 10;

    q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        z[i] = q[i];
    }
    free(p);
    p = q;
    q = NULL;

    // Creating a 2d array
    int B[3][4] = {
        {1, 2, 3, 4},
        {8, 7, 9, 6},
        {7, 6, 4, 9}};

    // Creating a 2d array in heap using pointers
    // Here each row will be a 1d array pointing to the arrays in heap
    int *C[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    // Creating a 2d array in heap where all the elements will be in heap
    int **D;
    D = new int*[3];
    D[0] = new int[4];
    D[1] = new int[4];
    D[2] = new int[4];
}