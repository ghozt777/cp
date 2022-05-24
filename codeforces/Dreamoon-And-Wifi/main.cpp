
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

vi out ;

void solve(int curr , int n){
	if(!n){
		out.push_back(curr) ;
		return ;
	}
	solve(curr + 1 , n - 1) ;
	solve(curr - 1 , n - 1) ;
}

void Run() {
	// run your code here
	string s1 ;
	string s2 ;
	cin >> s1 >> s2 ;
	int final = 0 ; 
	for(auto x : s1){
		if(x == '+') ++final ;
		else --final ;
	}
	int p = 0 ;
	int n = 0 ;
	int q = 0 ;
	for(char x : s2){
		if(x == '+') ++ p;
		else if(x == '-') ++n ;
		else ++q ;
	}
	solve(p - n , q) ;
	double a = 0 ;
	for(auto x : out) if(x == final) ++a ;
	cout << setprecision(12) << a / (double)out.size() << endl ;
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


