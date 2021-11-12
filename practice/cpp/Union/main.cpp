// program to find the number of elements formed from the union of two arrays
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
void printUnionCount(vi , vi) ;
void bruteforce(vi , vi) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	vi a  = {15,20,5,15} ;
	vi b  = {15,15,15,20,10} ;
	printUnionCount(a,b) ;
	cout << "\n" ;
	bruteforce(a,b) ;
	return ;
}


void printUnionCount(vi a , vi b){
	unordered_set<int> m ;
	for(int x : a) m.IN(x) ;
	for(int x : b) m.IN(x) ;
	cout << "ans: " << m.size() ;
}

void bruteforce(vi a , vi b){
	int c = 0 ;
	int arr[a.size() + b.size()] ;
	int i = 0 ;
	for( ; i < a.size() ; i++) arr[i] = a[i] ;
	for( ; i < a.size() + b.size() ; i++) arr[i] = b[i-a.size()] ;
	for(i = 0 ; i < sizeof(arr) / sizeof(arr[0]) ; i++){
		bool isThere = false ;
		for(int j = i - 1 ; j >= 0 ; j--){
			if(arr[i] == arr[j]){
				isThere = true ;
				break ;
			}
		}
		if(!isThere) ++c ;
	}
	cout << "ans(brute force) : " << c ;
}

void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


