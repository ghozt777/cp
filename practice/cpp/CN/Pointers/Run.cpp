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

Run();
return 0;
}



void Run() {

    int a = 10 ; // all the memmory addresses are kept in the symbol table
    cout << a << endl ;
    cout << "In the symbol table -> \nmemory address " << &a << " stores the value " << a << " assigned to variable \"a\"" << endl ;
    // the address is stored in hexadecimal : Eg : 0x16fa0393c 0x[...] represents hexadecimal number
    // creating a pointer : 
    int * ptr = &a ;
    (*ptr)++ ;
    cout << a << endl ;
    return ; 
}







void printArray(int arr[] , int n){
if(n==0){cout << "[]"; return ;}
if(n==1){cout << "[" << arr[0] << "]"; return ;}
cout << "[" << arr[0] <<", " ;
for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
cout << arr[n-1] << "]" ;
}