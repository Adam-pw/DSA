#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int c = *x;
    *x = *y;
    *y = c;
}

void Selectionsort(int arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(&arr[i], &arr[k]);
    }
}

int main()
{
    int arr[] = {67, 45, 32, 98, 54, 69};
    Selectionsort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}