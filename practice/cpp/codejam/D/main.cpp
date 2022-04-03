
#include<bits/stdc++.h>
#include <unordered_set>

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

void shift(vector<int> &arr){
	vector<int> aux(arr.size()) ;
	for(int i = 0 ; i < arr.size() ; i++) aux[(i + 1) % arr.size()] = arr[i] ;
	for(int i = 0 ; i < arr.size() ; i++) arr[i] = aux[i] ; 
}

int getMax(vector<int> adj[] , int F[] , int s){
	if(adj[s][0] == -1) return F[s] ;
	int res = F[s] ;
	for(int x : adj[s]) res = max(res , getMax(adj , F , x)) ;
	return res ;
}

int getMax(vector<int> adj[] , int F[] , int s , unordered_set<int> &visited){
	if(s == -1) return INT_MIN ;
	int res = F[s] ;
	for(int x : adj[s]){
		if(visited.find(x) == visited.end()){
			int pa = getMax(adj , F , x , visited) ;
			if(res < pa){
				res = pa ;
				visited.insert(x) ;
			}
		}
	}
	return res ;
}



void solve(){
	int n ;
	cin >> n ;
	int F[n] ;
	vector<int> adj[n] ;
	for(int i = 0 ; i < n ; i++) cin >> F[i] ;
	for(int i  = 0 ; i < n ; i++){
		int P ;
		cin >> P ; 
		adj[i].push_back(P - 1) ;
	}
	vector<int> edges ;
	vector<int> indegree(n , 0) ;
	for(int i = 0 ; i < n ; i++){
		for(int x : adj[i]) if(x != -1) ++indegree[x] ;
	}
	for(int i = 0 ; i < n ; i++) if(!indegree[i]) edges.push_back(i) ;
	int res = INT_MIN ;

	cout << res << endl ;
}

void Run() {
	// run your code here

	int t ;
	cin >> t ;
	for(int tt = 1 ; tt <= t ; tt++){
		cout << "Case #" << tt << ": " ;
		solve() ;
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


