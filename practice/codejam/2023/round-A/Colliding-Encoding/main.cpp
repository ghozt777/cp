/*
	Author: ghozt777
	codeforces: https://co
	deforces.com/profile/ghozt777
    Time: Sat Apr 15 18:29:52 IST 2023
	Link to problem / contest : 
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

string getEncoded(string &word,map<char,int> &m){
	string curr(word.size() , ' ') ;
	ll j = 0 ; 
	for(char x : word) curr[j++] = char(to_string(m[x])[0]) ;
	return curr ;
}

bool tc(){
	map<char,int> m;
	for(char i = 'A' ; i <= 'Z' ; i++){
		int code ;
		cin >> code ;
		m[i] = code ;
	}
	ll N ;
	cin >> N ;
	vector<string> arr(N) ;
	map<string,string> encodings; 
	bool ok = true ;
	for(string & x : arr){
		cin >> x ;
		if(!ok) continue ;
		string str = getEncoded(x,m);
		if(encodings.find(str) != encodings.end()){
			if(encodings[str] != x) ok = false ;
		}
		else{
			encodings[str] = x ;
		}
	} 
	return !ok ;
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
	for(int TT = 1 ; TT <= t ; TT++){
		cout << "Case #" << TT << ": " ;
		tc() ? cout << "YES" << endl : cout << "NO" << endl ; 
	}

	return EXIT_SUCCESS ;
}

