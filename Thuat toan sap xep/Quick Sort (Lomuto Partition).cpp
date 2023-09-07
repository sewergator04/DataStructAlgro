#include <iostream>
using namespace std;

int Partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    return i+1;
}

void QuickSort(int arr[], int left, int right){
    if(left >= right) return;
    int partitionpos = Partition(arr,left,right);
    QuickSort(arr,left,partitionpos-1);
    QuickSort(arr,partitionpos+1,right);
}

int main(){
    int test[9] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    QuickSort(test,0,8);
    for(int i : test){
        cout << i << " ";
    }
    return 0;
}
