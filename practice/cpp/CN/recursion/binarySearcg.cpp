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

int main(){

ios::sync_with_stdio(0);
cin.tie(0);
Run();
    return 0;
}

int util(int arr[] , int start , int end , int x){
    if(start > end) return -1; 
    int mid = start + (end - start) / 2 ;
    if(arr[mid] == x) return mid ;
    else if(arr[mid] > x) return util(arr , start , mid - 1 , x) ;
    else return util(arr , mid + 1 , end , x) ;
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    return util(input , 0 , size - 1 , element) ;
}


void Run() {

    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}