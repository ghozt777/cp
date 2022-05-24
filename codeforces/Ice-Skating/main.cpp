/*

	SOLUTION IDEA: (Author : ghozt777) 

	Main Idea:  If two points lie on the same line along any of the 4 directions : E W N S we consider those two points as connected

	Eg: 

	|
	| x (1,2)
	|
	|     x (2,1)
	|_______________		


	clearly (2,1) ans (1,2) dont lie on the same line hence they are disconnectec

	Eg:

	| x (1,4)
	| 
	|
	| x (1,2)
	|_______________		

	(1,2) and (1,4) both lie on the same line so they are connected 


	at the end we just need to count the number of disconnected graphs and we will get our answer 

	we assign each point a index to represent it in the graph
	we run two loops to check each node being connected to the rest of the nodes -> O(n^2) -> O(V^2)

	then we simply do a dfs and count the number of disconnected graphs -> O(V + E)
	we initialize res by -1 as if there are no disconnected components the loop will run once thus incrementing the result valu to 0 which is the answer for that case

	overall complexity: O(V^2) 

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


void Run();
void printArray(int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

bool lieOnSameLine(pair<int , int> &a , pair<int , int> &b){
	return a.first == b.first || a.second == b.second ;
}

void dfs(vector<bool> & vis , vii & adj , int s){
	vis[s] = true ;
	for(auto x : adj[s]) if(!vis[x]) dfs(vis , adj , x) ;
}

void Run() {
	// run your code here
	int n ;
	cin >> n ;
	map<int , pair<int , int>> m ;
	for(int i = 0 ; i < n ; i++){
		int a , b ;
		cin >> a >> b ;
		m[i] = {a, b} ;
	}
	vii adj(n) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i != j && lieOnSameLine(m[i] , m[j])){
				adj[i].push_back(j) ;
				adj[j].push_back(i) ;
			}
		}
	}

	int res = -1 ;
	vector<bool> vis(n , false) ;

	for(int i = 0 ; i < n ; i++){
		if(!vis[i]){
			++res ;
			dfs(vis , adj , i) ;
		}
	}	

	cout << res << endl ;

	return ;
}




void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


