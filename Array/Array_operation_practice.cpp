#include <iostream>
using namespace std;

void traversal(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void insert_at_the_end(int arr[], int n, int x) {
  arr[n] = x;
  traversal(arr, n + 1);
}

void replace_at_any_index(int arr[], int n, int pos, int x) {
  arr[pos] = x;
  traversal(arr, n);
}

void insert_at_the_beginning(int arr[], int n, int x) {
  for (int i = n - 1; i >= 0; i--) {
    arr[i + 1] = arr[i];
  }
  arr[0] = x;
  traversal(arr, n + 1);
}

void insert_at_any_index(int arr[], int n, int pos, int x) {
  for (int i = n - 1; i >= pos; i--) {
    arr[i + 1] = arr[i];
  }
  arr[pos] = x;
  traversal(arr, n + 1);
}

int main() {
  int Arr[20] = {4, 8, 1, 6};
  traversal(Arr, 4);
  cout << endl;
  insert_at_the_end(Arr, 4, 9);
  cout << endl;
  replace_at_any_index(Arr, 5, 2, 7);
  cout << endl;
  insert_at_the_beginning(Arr, 5, 2);
  cout << endl;
  insert_at_any_index(Arr, 6, 3, 42);
}
