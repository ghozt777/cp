// link : https://codeforces.com/problemset/problem/584/A
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

	Run();

    return 0;
}

void Run() {
	// run your code here
	int n , t ;
	cin >> n >> t ;
	string ans ;
	if(n == 1 && t == 10){ cout << -1 ; return ;}
	if(t < 10) for(int i = 0 ; i < n ; i++) ans += to_string(t) ;
	else {ans = to_string(1) ;for(int i = 0 ; i < n-1 ; i++) ans += to_string(0) ;}
	cout << ans ;
	return ;
}


