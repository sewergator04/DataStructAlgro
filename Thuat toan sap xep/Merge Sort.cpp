#include <iostream>
#include <vector>
using namespace std;

void MergingVectors(int arr[], int left, int mid, int right){
    vector<int> firsthalf(arr+left, arr+mid+1);
    vector<int> secondhalf(arr+mid+1, arr+right+1);
    int firstpos = 0; int secondpos = 0;
    while(firstpos < firsthalf.size() && secondpos < secondhalf.size()){
        if(firsthalf[firstpos] < secondhalf[secondpos]){
            arr[left] = firsthalf[firstpos];
            left++; firstpos++;
        }
        if(secondhalf[secondpos] < firsthalf[firstpos]){
            arr[left] = secondhalf[secondpos];
            left++; secondpos++;
        }
    }
    while(firstpos < firsthalf.size()){
        arr[left] = firsthalf[firstpos];
        left++; firstpos++;
    }
    while(secondpos < secondhalf.size()){
        arr[left] = secondhalf[secondpos];
        left++; secondpos++;
    }
}

void MergeSort(int arr[], int left, int right){
    if(left >= right) return;
    int mid = (left+right)/2;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid+1,right);
    MergingVectors(arr,left,mid,right);
}
int main(){
    int test[9] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    MergeSort(test, 0, 9);
    for(int i : test){
        cout << i << " ";
    }
    return 0;
}