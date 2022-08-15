/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Thu Jul 28 20:37:21 IST 2022
	Link to problem / contest : https://codeforces.com/problemset/problem/1709/C
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

#define PB push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
#define _max(arr) * max_element(all(x))
#define _min(arr) * min_element(all(x))
#define _max_pos(arr) max_element(all(x)) - arr.begin()
#define _min_pos(arr) min_element(all(x)) - arr.begin()
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = 1e9+7 ;
const ll INF = INT_MAX;
// count set bits in a given number
template <typename T>
int cnt_set_bits(T n){int res=0;while(n){n=n&(n-1);++res;}return res;}

//-----------------------------------------------------------------------------------------------
/*
	use balance concept
*/

bool isRBS(string &s){
	int balance=0;
	for(char x:s){
		if(x=='(') ++balance;
		else --balance;
		if(balance<0) return false;
	}
	return balance==0;
}

void tc(){
	string s;
	cin>>s;
	int open=s.length()/2;
	int close=s.length()/2;
	vector<int> q;
	for(int i=0;i<s.length();i++){
		char x=s[i];
		if(x=='(') --open;
		else if(x==')') --close;
		else q.push_back(i);
	}
	for(int i=0;i<q.size();i++){
		if(i<open)s[q[i]]='(';
		else s[q[i]]=')';
	}
	bool ok=true;
	if(open>0&&close>0){
		int lastOpen=q[open-1];
		int firstClose=q[open];
		swap(s[lastOpen],s[firstClose]);
		ok=!isRBS(s);
	}
	
	ok ? cout<<"YES\n":cout<<"NO\n";
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t ;
	cin >> t ;
	while(t--) tc() ;

	return EXIT_SUCCESS ;
}

