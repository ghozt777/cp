/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Mon Aug  8 14:28:09 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1642
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
 
pair<ll,ll> bs(vector<pair<ll,ll>>&arr,ll start,ll end, ll T){
	if(end<start) return {-1,-1};
	while(start<end){
		ll sum=arr[start].first+arr[end].first;
		if(sum==T)return{arr[start].second,arr[end].second};
		else if(sum<T) ++start;
		else --end;
	}
	return {-1,-1};
}
 
void tc(){
	ll N,T;
	cin>>N>>T;
	vector<pair<ll,ll>> arr;
	for(ll i=0;i<N;i++){
		ll a;
		cin>>a;
		arr.push_back({a,i+1});
	}	
	map<ll,vector<pair<ll,ll>>> m;
	for(ll start=0;start<N-1;start++){
		for(ll end=start+1;end<N;end++){
			ll sum=arr[start].first+arr[end].first;
			m[sum].push_back({start+1,end+1});
		}
	}

	for(auto x:m){
		if(m.find(T-x.first)!=m.end()){
			auto x1=x.second;
			auto x2=m[T-x.first];
			for(ll i=0;i<x1.size();i++){
				for(ll j=0;j<x2.size();j++){
					set<ll> s;
					s.insert(x1[i].first);
					s.insert(x1[i].second);
					s.insert(x2[j].first);
					s.insert(x2[j].second);	
					if(s.size()==4){
						for(auto r:s){
							cout<<r<<" ";
						}
						return ;
					}
				}
			}
		}
	}
	
	cout<<"IMPOSSIBLE";
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