
// link to problem : https://codeforces.com/problemset/problem/1607/C

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
	int t  ;
  	cin >> t ;
  	while(t--) {
    	int n ;
     	cin >> n ;
     	int arr[n] ;
     	for(int i = 0 ; i < n ;i++) cin >> arr[i] ;
     	sort(arr , arr+n) ;
     	int d = arr[0] ;
     	int ans = d ;
     	for(int i = 1 ; i < n ; i++) {
       		ans = max(ans , arr[i] - d) ;
       		d += arr[i] - d ;
     	}
     	cout << ans << "\n" ;
  	}

	return ;
}
