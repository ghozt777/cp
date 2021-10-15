#include <bits/stdc++.h>
using namespace std;
void mergeSort(int[] , int);
void helper(int[] , int  , int , int);
void merge(int[] , int , int , int , int);
void arraysToString(int[] , int);

int main() {
    int arr[] = {4,8,1,4,12,67,1,-98};
    mergeSort(arr ,  sizeof(arr) / sizeof(arr[0]));
    arraysToString(arr , sizeof(arr) / sizeof(arr[0]));    
    return 0;
}

void arraysToString(int *arr , int n){
    cout << "[ ";
    for(int i = 0 ; i < n ; i++){
        if( i != n-1)  cout << *arr++ << ", ";
        else cout << *arr++ << " ]\n"; 
    }
}

void mergeSort(int *arr , int n){
    helper(arr , 0 , n - 1 , n);
}

void helper(int *arr , int start , int end , int n){
    if(start == end) return ; 
    int mid = start + (end - start) / 2;
    helper(arr , start , mid , n);
    helper(arr , mid + 1 , end , n);
    merge(arr , start , end , mid , n);
}

void merge(int *arr , int start , int end , int mid , int n){
    int temp[n];
    int i = start;
    int j = mid + 1;
    int k = start;
    while(i <=mid && j <= end){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= end) temp[k++] = arr[j++];
    for(i = start ; i <= end ; i++) arr[i] =  temp[i];
}
