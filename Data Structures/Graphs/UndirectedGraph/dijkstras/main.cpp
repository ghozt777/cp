#include<bits/stdc++.h>
using namespace std ;


vector<int> dijkstras_naive(vector<vector<int>> & graph , int src){
	int V = graph.size() ;
	vector<bool> finalized(V , false) ;
	vector<int> dist(V , INT_MAX) ;
	dist[src] = 0 ;

	for(int count = 0 ; count < V - 1 ; count++){
		int u = -1 ;
		for(int i = 0 ; i < V ; i++){
			if(!finalized[i] && (u == -1 || dist[i] < dist[u])) 
				u = i ;
		}
		finalized[u] = true ;
		for(int i = 0 ; i < V ; i++){
			if(graph[u][i] != 0) dist[i] = min(dist[i], dist[u] + graph[u][i]) ;
		}
	}
	return dist ;
}

int main(){
	vector<vector<int>> graph = {
		// 0 1 2 3  
		{0,50,100,0} ,
		{50,0,30,200} ,
		{100,30,0,20} ,
		{0,200,20,0}
	} ;
	int src = 0 ;
	vector<int> dist = dijkstras_naive(graph , src) ;
	for(auto d : dist) cout << d << " " ;
	cout << endl ;
	return EXIT_SUCCESS ;
}