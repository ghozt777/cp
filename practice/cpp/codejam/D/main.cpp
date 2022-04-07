
#include<bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;
typedef map<string, int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)


void Run();
void printArray(int[], int);

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	Run();

	return 0;
}

int64_t ans ;

int64_t res(vector<int>* adj, vector<int64_t>& F, int s){
	if(adj[s].size() == 0) return F[s - 1];
	vector<int64_t> fun;
	for(int x : adj[s]){
		fun.push_back(res(adj, F, x));
	}
	sort(fun.begin(), fun.end());
	int64_t sum = 0 ;
	if(s == 0) for(int64_t x : fun) ans += x ;
	else for(int i = 1 ; i < fun.size() ; i++) ans += fun[i] ;
	return max(F[s - 1] , fun[0]); 
}


void solve(){
	ans = 0 ;
	int n;
	cin >> n;
	vector<int64_t> F(n);
	vector<int> adj[n + 1];
	for(auto& a : F) cin >> a;
	for(int i = 1; i <= n; i++){
		int P;
		cin >> P;
		adj[P].push_back(i);
	}
	// cout << endl ;
	// for(int i = 0 ; i <= n ; i++){
	// 	for(int x : adj[i]) cout << x << " " ;
	// 	cout << endl ;
	// }
	res(adj , F , 0); 
	cout <<  ans << endl ;

}

void Run() {
	// run your code here

	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cout << "Case #" << tt << ": ";
		solve();
	}
	return;
}







void printArray(int arr[], int n){
	if(n == 0){ cout << "[]"; return; }
	if(n == 1){ cout << "[" << arr[0] << "]"; return; }
	cout << "[" << arr[0] << ", ";
	for(int i = 1; i < n - 1; i++) cout << arr[i] << ", ";
	cout << arr[n - 1] << "]";
}


