// link : https://codeforces.com/contest/1607/problem/B
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

	int t ;
	cin >> t ;
	while(t--) {
		ll x , n ; 	
		cin >> x >> n ;
		if(x%2 == 0) {
			if(n%4 ==0) cout << x << "\n" ;
			else if(n%4 == 1) cout << x - n << "\n" ;
			else if(n%4 == 2) cout << x + 1 << "\n" ;
			else cout << x + n + 1<< "\n" ; 
		}
		else {
			if(n%4 ==0) cout << x << "\n" ;
			else if(n%4 == 1) cout << x + n << "\n" ;
			else if(n%4 == 2) cout << x - 1 << "\n" ;
			else cout << x - n - 1<< "\n" ;
		}
	}
	return ;
}