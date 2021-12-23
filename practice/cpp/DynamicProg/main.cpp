
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


int fibUtil(int n , unordered_map<int , int> memo){
	if(memo.find(n) != memo.end()) return memo.at(n) ;
	if(n <= 2) return 1 ;
	memo.insert(make_pair(n , fibUtil(n - 1 , memo) + fibUtil(n - 2 , memo))) ;
	return memo.at(n) ;
}

int fib(int n){
	unordered_map<int,int> memo ;
	return fibUtil(n , memo) ;
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
	int n ;
	cout << "Enter n : " ;
	cin >> n ;
	cout << "\nThe " << n << "th Fibonacci Number is : " << fib(n) << "\n" ;

	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


