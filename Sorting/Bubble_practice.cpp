#include <iostream>
#include <ctime>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

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
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "The date and time is :=> " << dt << endl;
    int n;
    int arr[n];
    cout << "Enter the number of elements in the array :=> " << endl;
    cin >> n;
    cout << "Enter the array you want to Sort :=> " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}