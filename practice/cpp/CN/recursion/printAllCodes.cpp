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

int getInt(char c){
    return c - '0' ;
}

void util(string ip, string p){
    if(ip.empty()){
        cout << p << endl ;
        return ;
    }
    util(ip.substr(1) , p + (char)('a' + getInt(ip[0]) - 1)) ;
    if(ip.length() >= 2 && (10 * getInt(ip[0]) + getInt(ip[1])) <= 26){
        util(ip.substr(2) , p + (char)('a' - 1 + 10 * getInt(ip[0]) + getInt(ip[1]))) ;
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */

   util(input , "") ;
}


void Run() {
    string input;
    cin >> input;

    printAllPossibleCodes(input);

    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}