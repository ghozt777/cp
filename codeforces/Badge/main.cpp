
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


vii adj ;
vector<bool> cs ;

int dfs(int s){
	if(cs[s]) return s;
	cs[s] = true ;
	int a = -1 ;
	for(int x : adj[s]) a = dfs(x) ;
	cs[s] = false ;
	return a ;
}

void Run() {
	// run your code here
	int n ;
	cin >> n ;
	adj.clear() ;
	cs.clear() ;
	adj.resize(n + 1);
	cs.resize(n + 1 , false) ;
	for(int i = 1 ; i <= n ; i++){
		int x ;
		cin >> x ;
		adj[i].push_back(x) ;
	}
	for(int i = 1 ; i <= n ; i++){
		cs.clear() ;
		cout << dfs(i) << " " ;
	}
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}




