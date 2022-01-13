#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)




void Run();
void printArray(int[] , int) ;

void merge(int arr[] , int start , int mid , int end) {
    int i = start ; 
    int j = mid + 1; 
    int k = start ; 
    int temp[10000] = {0} ;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++] ;
        else temp[k++] = arr[j++] ;
    }
    while(i <= mid) temp[k++] = arr[i++] ;
    while(j <= end) temp[k++] = arr[j++] ;
    for(k = start ; k <= end ; k++) arr[k] = temp[k] ;
}

void mergeSortUtil(int arr[] , int start , int end){
    if(start >= end) return ;
    int mid = start + (end - start) / 2 ;
    mergeSortUtil(arr , start , mid) ;
    mergeSortUtil(arr , mid + 1 , end)  ;
    merge(arr , start , mid , end) ;
}

void mergeSort(int arr[] , int size){
    mergeSortUtil(arr , 0 , size - 1) ;
}

int main(){

ios::sync_with_stdio(0);
cin.tie(0);
Run();
    return 0;
}

void Run() {
    int arr[] = {4,3,2,1} ;
    int n = sizeof(arr) / sizeof(arr[0]) ;
    cout << "unsorted: " ;
    printArray(arr , n) ;
    mergeSort(arr , n) ; 
    cout << "sorted: " ;
    printArray(arr , n) ;
    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}