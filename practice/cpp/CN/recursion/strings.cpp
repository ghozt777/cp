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

int substring(string str , string op[]){
    if(str.empty()){
        op[0]  = "" ;
        return 1 ;
    }
    int count = substring(str.substr(1) , op) ;
    for(int i = 0 ; i < count ; i++){
        op[i + count] = str[0] + op[i] ;
    }
    return 2 * count ;
}

void Run();
void printArray(int[] , int) ;

int main(){

ios::sync_with_stdio(0);
cin.tie(0);
Run();
    return 0;
}

void Run() {
    string * op = new string[10000] ;
    cout << "Enter a string\n" ;
    string str ;
    cin >> str ;
    int count = substring(str , op) ;
    cout << "all the possible subsequences are : " ;
    for(int i = 0 ; i < count ; i++) cout << op[i] << " " ;
    cout << endl ;
    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}
