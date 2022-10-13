// Merge Sort

// Divide and Conquer

// Best case O(n*log n)
// Worst case O(n*log n)
// Average case O(n*log n)

// In-place : No { Requires Extra Space }
// Stable : Yes

// Space Complexity : O(n)

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
    int L[m - l + 1], M[h - m];

    for (int i = 0; i < m - l + 1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < h - m; i++)
    {
        M[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < m - l + 1 && j < h - m)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < m - l + 1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < h - m)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 6, 1, 7, 3, 8, 45, 96, 12};

    print_array(arr, 9);
    
    MergeSort(arr, 0, 9);
    
    print_array(arr, 9);
}