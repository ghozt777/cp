
#include <algorithm>
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

void Run() {
	// run your code here
	int n ;
	cin >> n ; 
	vector<int> prices(n) ;
	for(auto &a : prices) cin >> a ;
	int q ;
	cin >> q ;
	sort(prices.begin() , prices.end()) ;
	for(int i = 0 ;i < q ; i++){
		int x ;
		cin >> x ;
		int n = upper_bound(prices.begin() , prices.end() , x) - prices.begin(); // read more about upper_bound c++ -> https://www.geeksforgeeks.org/upper_bound-in-cpp/
		cout << n << endl ;
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


