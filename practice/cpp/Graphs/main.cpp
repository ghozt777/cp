
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

void addEdge(vi adj[] , int u , int v){
	adj[u].push_back(v) ;
	adj[v].push_back(u) ; // as it is undirected
}

void debug(vi adj[] , int v){
	for(int i = 0 ; i < v ; i++){
		cout << i << "th node is connected to : " ;
		for(int x : adj[i]) cout << x << ", " ;
		cout << "\n" ; 
	}
}

void BFS(vi adj[] , int v , int s){
	bool visited[v] ;
	for(int i = 0 ; i < v ; i++) visited[i] = false ;
	visited[s] = true ;
	queue<int> q ;
	q.push(s) ;
	while(!q.empty()){
		int s = q.front() ;
		q.pop() ;
		cout << s << " " ;
		for(int x : adj[s]) if(!visited[x]){
			q.push(x) ;
			visited[x] = true ;
		}
	}
}

void Run() {
	// run your code here
	int v = 4 ;
	vi adj[4] ;
	addEdge(adj , 0 , 1) ;
	addEdge(adj , 0 , 2) ;
	addEdge(adj , 1 , 2) ;
	addEdge(adj , 1 , 3) ;
	// debug(adj,4);
	BFS(adj , 4 , 1) ;
	return ;
}










void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


