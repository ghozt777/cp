// link : https://codeforces.com/problemset/problem/1607/A

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
			string d ;
			string str ;
			cin >> d >> str ;
			int ans = 0 ;
			map<char , int> m ;
			int i = 0 ;
			for(char x : d) 
				m.IN(x , i++) ;
			for(i = 0 ; i < size(str) - 1 ; i++)
				ans += abs(m.at(str[i]) - m.at(str[i + 1])) ;
		cout << ans << "\n" ;
	}
	return ;
}
 