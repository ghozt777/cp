
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













/*
	Notes to refer :
	
	https://www.youtube.com/watch?v=9C2cpQZVRBA&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=41

	Formal Definition: 
	A graph is an ordered pair of a set V of vertives and a set E of edges.
		G = (V,E)

	|V| = number of vertices
	|E| = number of edges

	Edges in a graph can either be directed(unidirectional) or undirected(bidirectional)

	🍕 ---> 🍔 			🍕 --- 🍩        🍕 , 🍩 , 🍔 : nodes
	 directed 			undirected

	A graph with only directed edges is known as a Digraph and a graph with only undirected edges is called an undirected graph or simply a graph

	The edges in a graph may or may not be weighted

	Self Loop: If both the end points of an edge are same its known as a self loop. Eg: A page having a link to itself

	MultiEdge or Parallel : A edge is known as a multiedge if it occurs more than once . 
	Eg:     ---->               
		🧀  ----> 🥨  
			---->
		practical eg: flights between two cities wuth difference airlines or cost are going to have the same links or edges hence creating a mlutiedge .


	Self Loops and Multiedges often compilate graphs

	A graph without any self loops or multiedges is known as a simple graph .

	Number of edges in a simple graph:
	
		|V| = n = number of vertices
		then , 
			0 <= |E| <= n*(n-1)       if directed
			0 <= |E| <= (n*(n-1))/2   if undirected
	
	A graph is called Dense of the number of edges |E| is close to the maximum limit, which is close to the square of the number of nodes , vertices .

	A graph is called Sparse if the number of edges |E| is close to the minimum limit .

	Walk: a sequence of vertices where each adjacent pair is connected by an edge

	Simple Path : a walk where no vertiecs (and thus no edges) are repeated is known as a simple path

	Trail : a walk where no edges are repeated

	Connected Graphs: if in a undirected graph there is a path from any vertex to any other vertex .

	Strongly Connected Graphs: if in a directed graph there is a path from any vertex to any other vertex .

	Closed Walk: if the walk starts and ends at the same vertex and the length of the walk is greater than 1 .

	Length of a walk : Number of edges in the walk .

	Simple Cycle : a closed walk where other tham the start and end vertex there are no other repititions .

	Acyclic Graph : a graph with no cycle DAG(Directed Acyclic Graph) and UAG(Undirected Acyclic Graph) .

	if Stored in form of dynamic arrays of edges and verteces;
	struct Edge{
		char *start ; // points to the starting address of the vertex which is a string 
		char *end ;
		int weight ; 
	} ;
	or 
	struct Edge {
		int start ; // points to the index of the vertex
		int end ;
		int weight ;
	}
	Space Complexity: O(|V| + |E|) |E|max = n*(n-1) where n=|V|
	Time Complexity for finding adjacent nodes : O(|E|)
					for finding if two nodes are connected : O(|E|)
		Therefore TC , SC : O(|V|^2) -> costly
						 if O(|V|)   -> Ok
	
	
	

*/


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	return ;
}




