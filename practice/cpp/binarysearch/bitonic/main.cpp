#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& arr){
    int start = 0;
    int end = arr.size() - 1;
    while(start < end){
        int mid = start + (end - start) / 2;
        if(arr[mid] > arr[mid + 1]) end = mid;
        else start = mid + 1;
    }
    return end;
}

int binarySearch(vector<int>& arr, int x, int start, int end, bool isRev){
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) isRev ? start = mid + 1 : end = mid - 1;
        else isRev ? end = mid - 1 : start = mid + 1 ;
    }
    return -1;
}

int solve(vector<int>& arr, int x) {
    int pivot = getPivot(arr);
    int res = -1;
    res = binarySearch(arr, x, 0, pivot, false);
    if(res != -1) return res;
    return binarySearch(arr, x, pivot + 1, arr.size() - 1, true);
}

int main(){
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 };
    cout << solve(arr, 12);
    return 0;
}
