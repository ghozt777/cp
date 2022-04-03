
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
	int t ;
	cin >> t ;
	while(t--){
		int n;
		cin >> n ;
		ll arr[n] ;
		ll m = INT_MAX ;
		for(int i = 0 ; i < n ; i++){ 
			cin >> arr[i] ;
			m = min(m , arr[i]) ;
		}
		if(n == 1) {
			arr[0] == 1 ? cout << "YES" : cout << "NO" ;
			cout << endl ;
			continue ;
		}
		vector<ll> a ;
		for(ll x : arr) if(x - m > 0) a.emplace_back(x - m) ;
		bool ok = true ;
		for(int i = 0 ; i < a.size() ; i++){
			for(int j = 1 ; j < a.size() ; j++){
				if(abs(a[i] - a[j]) >= a.size()){
					ok = false ;
					break ;
				}
			}
		}
		ok ? cout << "YES" : cout << "NO" ;
		cout << endl ;
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


