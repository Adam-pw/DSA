// Bubble Sort

// Best case O(n)
// Worst case O(n*2)
// Average case O(n*2)

// In-place : Yes
// Stable : Yes

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int c = *x;
    *x = *y;
    *y = c;
}

// Flag for making bubble sort adaptive
void Bubblesort(int arr[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {67, 45, 32, 98, 54, 69};
    Bubblesort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}