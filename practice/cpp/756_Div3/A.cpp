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
 
int fact(int n){
	if(n <= 1) return 1 ;
	int ans = 1 ;
	while(n > 1) ans *= n-- ;
	return ans ;
}
 
void Run() {
	// run your code here
	int t ;
	cin >> t ;
	while(t--){
		string n ;
		cin >> n ;
		if(n[size(n) - 1]%2 == 0){cout << 0 << endl ; continue ;}
		int i = 0 ;
		bool f = false ;
		for(; i < size(n) ; i++){
			int d = n[i] - '0' ;
			if(d%2 == 0){f = true; break;}
		}
		if(!f){ cout << -1 << endl ; continue ;}
		if(i == 0) cout << 1 << endl ;
		else cout << 2 << endl ;
	}
}
 
 
 
 
 
 
void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}
 
 