// a program to find the size of the array formed from the intersection of two arrays
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
void intersectionCount(vi , vi) ;
void bruteforceIntersection(vi,vi) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	vi a = {10,15,20,5,30} ;
	vi b = {30,5,30,80} ;
	intersectionCount(a,b) ;
	cout << "\n" ;
	bruteforceIntersection(a,b) ;
	return ;
}


void intersectionCount(vi a , vi b){
	int c = 0 ;
	unordered_set<int> ma ;
	unordered_set<int> mb ;
	for(int x : a) ma.insert(x) ;
	for(int x : b) mb.insert(x) ;
	for(int x : ma) if(mb.find(x) != mb.end()) ++c ;
	cout << "ans : " << c ;
}


void bruteforceIntersection(vi a , vi b){
	int c = 0 ;
	for(int i = 0 ; i < a.size() ; i++){
		bool isThere = false ;
		for(int j = i - 1 ; j >= 0 ; j--){
			if(a[i] == a[j]){
				isThere = true ;
				break ;
			}
		}
		if(isThere) continue ;
		for(int k = 0 ; k < b.size() ; k++){
			if(a[i] == b[k]){
				++c ;
				break ;
			}
		}
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


