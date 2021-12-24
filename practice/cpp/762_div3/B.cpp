
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

void runCase() {
	ll n ;
	cin >> n ;
	int ans = 0 ;
	for(ll i = 1 ; i * i <= n ; i++) ++ ans ;
	for(ll i = 1 ; i * i * i <= n  ; i++) {
		double s = sqrt(i * i * i) ; 
		if(ll(s) == s) continue ;
		++ ans ;
	}
	cout << ans << endl ;
}

void Run() {
	// run your code here
	int test ;
	cin >> test ;
	while(test-- > 0)
		runCase() ;

	return ;
}