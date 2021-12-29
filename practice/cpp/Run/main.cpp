
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
bool check(string s){
        int n = s.size() ;
        for(int i = 0 ; i < n / 2 ; i++) if(s[i] != s[n - i - 1]) return false ;
        return true ;
    }

string longestPalindrome(string s) {
  int max = 0 ;
  int st = 0 ;
  int e = 0 ;
  for(int i = 0 ; i < s.size() ; i++){
    for(int j = i ; j < s.size() ; j++){
      if(check(s.substr(i , j - i + 1)) && max < s.substr(i , j - i + 1).size()){
        st = i ;
        e = j ;
        max = s.substr(i , j - i + 1).size() ;
      }
    }
  }
  return s.substr(st , e - st + 1) ;
}
    

void Run();;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
  cout << longestPalindrome("cbbd") ;
}




