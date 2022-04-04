
#include<bits/stdc++.h>
#include<unordered_set>
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

bool isOk(string s){
	unordered_set<char> visited ;
	for(char x : s){
		if(visited.find(x) == visited.end()) visited.insert(x) ;
		else return false ;
	}
	return true ;
}

void Run() {
	// run your code here
	int start ;
	cin >> start ;
	for(int i = start + 1 ; i <= 9000000 ; i++){
		if(isOk(to_string(i))){
			cout << i << endl ;
			return ; 
		}
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


