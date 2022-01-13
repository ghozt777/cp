/*
    KMP Algo is used to find a pattern in a string : 
    Time Complexity : O(m + n) 
    Space Complexity : O(m)
    where m = length of the pattern and n = length of the string
*/

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

pair<int * , int> getLPS(string pattern){
    const int n = pattern.length() ;
    int * lps = new int[n] ;
    lps[0] = 0 ;
    int len = 0 ;
    int i = 1 ;
    while(i < n){
        if(pattern[i] == pattern[len]){
            ++len ;
            lps[i] = len ;
            ++i ;
        }
        else {
            if(len != 0){
                len = lps[len - 1] ;
            }
            else{
                lps[i] = 0 ;
                ++i ;
            }
        }
    }
    return make_pair(lps , n) ;
}

void KMPSearch(string str , string pattern){
    const int n = str.length() ;
    const int m = pattern.length() ;
    int i = 0 ; 
    int j = 0 ; 
    int * lps = getLPS(pattern).first ;
    while(i < n){
        if(str[i] == pattern[j]){
            ++i ;
            ++j ;
        }
        if(j == m){
            cout << "Pattern match at : " << i - j << endl ;
            j = lps[j - 1] ;
        }
        if(i < n && str[i] != pattern[j]){
            if(j != 0) j = lps[j - 1] ;
            else ++i ;
        }
    }
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
    KMPSearch("abcdababc" , "aba") ;
    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}