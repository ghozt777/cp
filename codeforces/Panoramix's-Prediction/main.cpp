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

bool isPrime(int n){
	int root = (int)(sqrt(n)) ;
	for(int i = 2 ; i <= root ; i++) if(n % i == 0) return false ;
	return true ;
}


void Run();
void printArray(int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	int n , m ;
	cin >> n >> m ;
	if(!isPrime(m)){
		cout << "NO" << endl ;
		return ;
	}
	int start = n + 1 ;
	while(!isPrime(start)){
		++start ;
		if(start == m) break ;
	}
	m == start ? cout << "YES" : cout << "NO" ;
	cout << endl ;

	return ;
}





void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


