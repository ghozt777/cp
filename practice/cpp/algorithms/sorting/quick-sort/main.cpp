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

int partitioner(int arr[] , int start , int end){
    int c = 0 ;
    for(int i = start ; i <= end ; i++) if(arr[i] < arr[start]) ++c ;
    swap(arr[start] , arr[start +c]) ;
    int s = start ; 
    int e = end ;
    while(s < e){
        if(arr[s] > arr[start + c]) swap(arr[s] , arr[e--]) ;
        else s++ ;
    }
    return start + c ; 
}
void _swap(int & a , int & b){
    int temp = a ;
    a = b ;
    b = temp ;
}

void quickSortUtil(int arr[] , int start , int end){
    if(start >= end) return ;
    int p = partitioner(arr , start , end) ;
    quickSortUtil(arr , start , p - 1) ;
    quickSortUtil(arr , p + 1 , end) ;
}

void quickSort(int arr[] , int size){
    quickSortUtil(arr , 0 , size - 1) ;
}

void Run();
void printArray(int[] , int) ;

int main(){

ios::sync_with_stdio(0);
cin.tie(0);
Run();
    return 0;
}

void test() {
    int arr[] = {9,0,11,4,0,9} ;
    // cout << "p : " << partitioner(arr , 0 , 5) ;
    // cout << endl ;
    _swap(arr[0] , arr[1]) ;
    printArray(arr , 6) ;
}

void Run() {
    test(); 
    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}