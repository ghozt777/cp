/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Fri Jul 22 00:35:36 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1164
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


string serialize(ll a,ll b){
	return to_string(a)+"|"+to_string(b);
}

void tc(){
	ll n;
	cin>>n;
	vector<vector<ll>> a(n,vector<ll>(2));
	map<string,priority_queue<ll,vector<ll>,greater<ll>>> m;
	ll idx=0;
	for(auto &x:a)cin>>x[0]>>x[1],m[serialize(x[0],x[1])].push(idx++);
	sort(all(a));
	ll res=1;
	vector<ll> rooms(n);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>earliest;
	for(ll i=0;i<n;i++){
		ll room=-1;
		if(earliest.empty()||earliest.top().first<a[i][0]){
			if(!earliest.empty())room=earliest.top().second,earliest.pop();
			earliest.push({a[i][1],room==-1?1:room});
		}else{
			room=earliest.size()+1;
			++res;
			earliest.push({a[i][1],res});
		}
		auto &x=m[serialize(a[i][0],a[i][1])];
		if(!x.empty()){
			ll idx=x.top();
			x.pop();
			rooms[idx]=room==-1?1:room;
		}
	}
	cout<<res<<endl;
	for(auto x:rooms)cout<<x<<" ";
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t=1;
	while(t--) tc() ;

	return EXIT_SUCCESS ;
}

