
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

vii adj ;
vector<bool> vis ;


void Run();
void printArray(int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

bool dfs(int s , int d){
	if(s == d) return true ;
	vis[s] = true ;
	for(int x : adj[s]) if(!vis[x] && dfs(x , d)) return true ;
	return false ;
}


void Run() {
	// run your code here
	int n , s ;
	cin >> n >> s ;
	adj.clear() ;
	vis.clear() ;
	adj.resize(n + 1) ;
	vis.resize(n + 1 , false) ;
	int lastStop = -1 ;
	for(int i = 1 ; i <= n ; i++){
		int a ;
		cin >> a ;
		if(a){
			if(lastStop != -1){
				adj[lastStop].push_back(i) ;
				lastStop = i ;
			}
			else lastStop = i ;
		}
	}
	lastStop = -1 ;
	for(int i = 1 ; i <= n ; i++){
		int a ;
		cin >> a ;
		if(a){
			if(lastStop != -1){
				adj[i].push_back(lastStop) ;
				lastStop = i ;
			}
			else lastStop = i ;
		}
	}
	dfs(1 , s) ? cout << "YES" : cout << "NO" ;
	
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


