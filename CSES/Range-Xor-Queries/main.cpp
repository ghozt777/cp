/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Mon Aug 22 14:50:48 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1650
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

class Node{
public:
	ll val;
	ll start;
	ll end;
	Node(){}
	Node(ll val,ll start,ll end){
		this->val=val;
		this->start=start;
		this->end=end;
	}
};

class SegTree{
	vector<Node> t;
	void calc(ll v){
		t[v].val=t[2*v].val^t[2*v+1].val;
	}
	void build(vector<ll>&A,ll start,ll end,ll v){
		Node n(-1,start,end);
		t[v]=n;
		if(start==end){
			t[v].val=A[start];
			return;
		}
		ll mid=start+(end-start)/2;
		build(A,start,mid,2*v);
		build(A,mid+1,end,2*v+1);
		calc(v);
	}
	ll query_helper(ll start,ll end,ll v){
		Node &curr=t[v];
		if(curr.start>end||curr.end<start) return 0;
		if(curr.start>=start&&curr.end<=end) return curr.val;
		return query_helper(start,end,2*v)^query_helper(start,end,2*v+1);
	}
	void update_helper(ll pos,ll val,ll v){
		Node &curr=t[v];
		if(curr.start==curr.end&&curr.start==pos){
			curr.val=val;
			return;
		}
		ll mid=curr.start+(curr.end-curr.start)/2;
		if(pos<=mid) update_helper(pos,val,2*v);
		else update_helper(pos,val,2*v+1);
		calc(v);
	}
public:
	SegTree(vector<ll>A){
		this->t.clear();
		this->t.resize(4*(A.size()+1));
		build(A,0,A.size()-1,1);
	}
	ll query(ll start,ll end){
		return query_helper(start,end,1);
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
		ll start,end;
		cin>>start>>end;
		--start,--end;
		cout<<sg.query(start,end)<<endl;
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

