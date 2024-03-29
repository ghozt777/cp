/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Wed Aug 10 20:16:20 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1651
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
	ll lazy;
	Node(){}
	Node(ll val,ll start,ll end){
		this->val=val;
		this->start=start;
		this->end=end;
		this->lazy=0;
	}
};


class SegTree{
	vector<Node> t;
	void calc(ll v){
		t[v].val=t[2*v].val+t[2*v+1].val;
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
		if(curr.lazy){
			curr.val+=(curr.end-curr.start+1)*curr.lazy;
			if(curr.start!=curr.end){
				t[2*v].lazy+=curr.lazy;
				t[2*v+1].lazy+=curr.lazy;
			}
			curr.lazy=0;
		}

		if(curr.start>end||curr.end<start) return 0;
		if(curr.start>=start&&curr.end<=end) return curr.val;
		return query_helper(start,end,2*v)+query_helper(start,end,2*v+1);
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
	void update_helper(ll start,ll end,ll diff,ll v){
		Node &curr=t[v];
		
		if(curr.lazy){
			curr.val+=(curr.end-curr.start+1)*curr.lazy;
			if(curr.start!=curr.end){
				t[2*v].lazy+=curr.lazy;
				t[2*v+1].lazy+=curr.lazy;
			}
			curr.lazy=0;
		}

		if(curr.start>end||curr.end<start) return;

		if(curr.start>=start&&curr.end<=end){
			curr.val+=(curr.end-curr.start+1)*diff;
			if(curr.start!=curr.end){
				t[2*v].lazy+=diff;
				t[2*v+1].lazy+=diff;
			}
			return;
		}

		update_helper(start,end,diff,2*v);
		update_helper(start,end,diff,2*v+1);

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
	void update(ll start,ll end,ll diff){
		update_helper(start,end,diff,1);
	}
};


void tc(){
	ll N,Q;
	cin>>N>>Q;
	vector<ll> arr(N);
	read(arr);
	SegTree sg(arr);
	for(ll qq=0;qq<Q;qq++){
		ll k;
		cin>>k;
		if(k==1){
			ll start,end,diff;
			cin>>start>>end>>diff;
			--start,--end;
			sg.update(start,end,diff);
		}
		else{
			ll pos;
			cin>>pos;
			--pos;
			cout<<sg.query(pos,pos)<<endl;
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

