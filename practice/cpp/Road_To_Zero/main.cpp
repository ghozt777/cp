// link: https://codeforces.com/problemset/problem/1342/A
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


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t ;
	cin >> t ;
	while(t--)
	Run();

    return 0;
}

void Run() {
	// run your code here
	ll x , y , a , b ;
	cin >> x >> y >> a >> b ;
	ll ans = 0 ;
	if( 2*a < b){
		ans = a*(x+y) ;
	}
	else{
		int _min = min (x , y) ;
 		ans = b*_min ;
		x -= _min ;
		y -= _min ;
		if(x > 0) ans += x*a ;
		if(y > 0) ans += y*a ;
	}
	cout << ans << "\n" ;
	return ;
}


