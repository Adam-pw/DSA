#include<iostream>
using namespace std;

#define SIZE 5

int arr[SIZE], rear = -1, front = - 1;

void AddRear(int n){
    if((front == 1 && rear == SIZE - 1) || front == rear + 1){
        cout << "The Queue is full";
    }
    if(front == -1){
        front = 0;
    }
}

int main(){

}