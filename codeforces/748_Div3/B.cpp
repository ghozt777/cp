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
void Solve();
 
 
int main(){
 
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	Run();
 
    return 0;
}
 
void Run() {
	// run your code here
	int t ;
	cin >> t;
	while(t--)
		Solve() ;
 
	return ;
}
 
void Solve() {
	string n  ;
	cin >> n ;
	int ans = INT_MAX ;
	int N = size(n) ;
	for(int i = 0  ; i < N ; i++){
		for(int j = i + 1 ; j < N ; j++){
			if(n[i] == '0' && n[j] == '0') ans = N - i - 2 ;
			if(n[i] == '2' && n[j] == '5') ans = N - i - 2 ;
			if(n[i] == '5' && n[j] == '0') ans = N - i - 2 ;
			if(n[i] == '7' && n[j] == '5') ans = N - i - 2 ;
		}
	}
	cout << ans << "\n" ;
}
