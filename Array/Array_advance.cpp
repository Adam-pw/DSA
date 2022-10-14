#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length = arr->length + 1;
    }
}

void Insert(struct Array *arr, int x, int index)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0, i;
    if (index >= 0 && index <= arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// This functions searches the elements in the array and also replace it with the first element
// So that if we searches the second time it can be found in the front
int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    cout << endl;
    return -1;
}

// Can only be applied on sorted array
int BinarySearch(struct Array *arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr->length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr->A[mid] == key)
            return mid;
        else if (arr->A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(struct Array *arr, int key, int l, int h)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (arr->A[mid] == key)
            return mid;
        else if (arr->A[mid > key])
            return RBinarySearch(arr, key, l, mid - 1);
        else
            return RBinarySearch(arr, key, mid + 1, h);
    }
    return -1;
}

int Get(struct Array arr, int index)
{

    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{

    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr)
{

    int max = arr.A[0];
    struct Array arr1 = {{6, 8, 7, 9, 4}, 10, 5};
    Append(&arr1, 42);
    Insert(&arr1, 69, 4);
    Delete(&arr1, 2);
    Display(arr1);
    cout << LinearSearch(&arr1, 69);
    cout << endl;
    // cout << BinarySearch(&arr1, 69);
    Reverse(&arr1);
    Display(arr1);
    int i;

    for (i = 1; i < arr.length; i++)

    {

        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{

    int min = arr.A[0];

    int i;

    for (i = 1; i < arr.length; i++)

    {

        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s = 0;
    int i;

    for (i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B = new int[arr->size];
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

int IsSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = new Array;
    while (i < arr1->length && j < arr2->length)
    {
        
    }
}

int main()
{
    struct Array arr1 = {{6, 8, 7, 9, 4}, 10, 5};
    Append(&arr1, 42);
    Insert(&arr1, 69, 4);
    Delete(&arr1, 2);
    Display(arr1);
    cout << LinearSearch(&arr1, 69);
    cout << endl;
    // cout << BinarySearch(&arr1, 69);
    Reverse(&arr1);
    Display(arr1);
}