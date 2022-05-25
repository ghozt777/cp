// link : https://codeforces.com/problemset/problem/115/A

/*
	Solution : (author : ghozt777)

	for each disconnected tree find the number of levels by doing a bfs
	answer = max(levels from all disconnected tress)

	so if there are n disconnected trees: a1 , a2 , .... an -> where ai = number of levels in ith tree

	ans = max(a1 , a2 , .... , an) ;

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

vii adj ;

int bfs(){
	queue<int> toProcess ;
	int res = INT_MIN ;
	const int v = adj.size() ;
	vector<bool> vis(v , false) ;
	for(int i = 0 ;i < v ; i++){
		if(!vis[i]){
			int levels = 0 ;
			toProcess.push(i) ;
			while(!toProcess.empty()){
				int n = toProcess.size() ;
				++levels ;
				for(int j = 0 ; j < n ; j++){
					int curr = toProcess.front() ;
					toProcess.pop() ;
					vis[curr] = true ;
					for(auto x : adj[curr]) toProcess.push(x) ;
				}
			}
			res = max(res , levels) ;
		}
	}
	return res ;
}


void Run() {
	// run your code here
	int n ;
	cin >> n ;
	adj.clear() ;
	adj.resize(n) ;
	for(int i = 0 ; i < n ; i++){
		int p ;
		cin >> p ;
		if(p != -1) adj[p - 1].PB(i) ;
	}
	int res = bfs() ;
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


