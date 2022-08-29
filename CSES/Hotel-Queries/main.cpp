/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Wed Aug 24 11:56:00 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1143
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
 
 
class node{
public:
	ll start,end,mx,idx,lazy;
	node(){
		start=-1;
		end=-1;
		idx=-1;
		mx=LLONG_MIN;
		lazy=0;
	}
	node(ll start,ll end,ll mx,ll idx=-1){
		this->start=start;
		this->end=end;
		this->mx=mx;
		this->idx=idx;
		lazy=0;
	}
};
 
class SegTree{
	vector<node> t;
	vector<ll> A;
	ll sz;
	void calc(ll v){
		t[v].mx=max(t[2*v].mx,t[2*v+1].mx);
	}
	void build(vector<ll>&arr,ll start,ll end,ll v){
		node n(start,end,LLONG_MIN);
		t[v]=n;
		if(start==end){
			t[v].mx=arr[start];
			t[v].idx=start;
			return;
		}
		ll mid=start+(end-start)/2;
		build(arr,start,mid,2*v);
		build(arr,mid+1,end,2*v+1);
		calc(v);
	}
	ll query_helper(ll n,ll v){
		if(t[v].start==t[v].end) return t[v].idx;
		auto r=query_helper(n,2*v);
		if(r==-1||A[r]<v) return query_helper(n,2*v+1);
		else return r;
	};
	void update_helper(ll pos,ll val,ll v){
		if(t[v].start==t[v].end&&t[v].start==pos){
			t[v].mx=val;
			return;
		}
		ll mid=t[v].start+(t[v].end-t[v].start)/2;
		if(pos<=mid) update_helper(pos,val,2*v);
		else update_helper(pos,val,2*v+1);
		calc(v);
	}
public:
	SegTree(vector<ll>&arr){
		sz=arr.size();
		t.clear();
		t.resize(4*(arr.size()+1));
		A.clear();
		A.resize(arr.size());
		for(ll i=0;i<sz;i++) A[i]=arr[i];
		build(arr,0,arr.size()-1,1);
	}
	ll query(ll n){
		return query_helper(n,1);
	}
	void update(ll pos,ll val){
		update_helper(pos,val,1);
	}
};
 
void tc(){
	ll N,Q;
	cin>>N>>Q;
	vector<ll> A(N);
	read(A);
	SegTree sg(A);
	for(ll qq=0;qq<Q;qq++){
		ll r;
		cin>>r;
		auto x=sg.query(r);
		if(x==-1||A[x]<r) cout<<0<<endl;
		else{
			cout<<x+1<<endl;
			sg.update(x,r-A[x]);
		}
	}
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