// link : https://codeforces.com/problemset/problem/339/B
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pßair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)


void Run();


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	ll n , m ;
	cin >> n >> m ;
	ll t[m] ;
	for(int i = 0 ; i < m ; i++) cin >> t[i] ;
	ll ans = t[0] - 1;
	for(int i = 1 ; i < m ; i++){
		if(t[i] < t[i-1]) ans += n - t[i-1] + t[i] ;
		else ans += t[i] - t[i-1] ;
	}
	cout << ans ;
	return ;
}


