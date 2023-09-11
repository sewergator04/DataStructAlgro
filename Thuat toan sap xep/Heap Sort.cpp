#include <iostream>
#include <algorithm>
using namespace std;

void Heapify(int arr[], int n, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        Heapify(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(arr[i],arr[0]);
        Heapify(arr,i,0);
    }
}
int main(){
    int test[9] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    HeapSort(test,9);
    for(int i : test){
        cout << i << " ";
    }
    return 0;
}
