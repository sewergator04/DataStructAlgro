#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(int arr[], int arrsize){
    for(int i = 0; i < arrsize; i++){
        int smallest = arr[i];
        int smallestpos = i;
        for(int j = i+1; j < arrsize; j++){
            if(smallest > arr[j]){
                smallest = arr[j];
                smallestpos = j;
            }
        }
        if(smallest != arr[i]){
            int temp = arr[i];
            arr[i] = arr[smallestpos];
            arr[smallestpos] = temp;
        }
    }
}

void InsertionSort(int arr[], int arrsize){
    for(int i = 1; i < arrsize; i++){
        int saved = arr[i];
        int startpos = i-1;
        while(startpos >= 0 && saved < arr[startpos]){
            arr[startpos+1] = arr[startpos];
            startpos--;
        }
        arr[startpos+1] = saved;
    }
}

void BubbleSort(int arr[], int arrsize){
    for(int i = 0; i < arrsize; i++){
        for(int j = i+1; j < arrsize; j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main(){
    int test[9] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    //SelectionSort(test,9);
    //InsertionSort(test,9);
    BubbleSort(test,9);
    for(int i : test){
        cout << i << " ";
    }
    return 0;
}