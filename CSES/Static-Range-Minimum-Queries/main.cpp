/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Wed Aug 10 17:18:37 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/1647
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


class SegTree{
private:
	ll val;
	SegTree*left;
	SegTree*right;
	ll start;
	ll end;

	void recalc(){
		if(this->left==this->right) return;
		this->val=min((this->left?this->left->val:INT_MAX),(this->right?this->right->val:INT_MAX));
	}

public:
	SegTree(){
		this->val=INF;
		this->start=-1;
		this->end=-1;
		this->left=NULL;
		this->right=NULL;
	}


	SegTree(vector<ll>&arr,ll start, ll end){
		if(start>end) return;
		this->start=start;
		this->end=end;
		if(start==end){
			this->val=arr[start];
			return;
		}
		ll mid=start+(end-start)/2;
		this->left=new SegTree(arr,start,mid);
		this->right=new SegTree(arr,mid+1,end);
		recalc();
		return;
	}

	void update(ll idx, ll val){
		if(this->start>idx||this->end<idx) return;
		if(this->start==idx&&this->end==idx){
			this->val=val;
			return;
		}
		this->left->update(idx,val);
		this->right->update(idx,val);
		this->recalc();
	}

	ll query(ll start,ll end){
		if(this->start>end||this->end<start) return INT_MAX;
		if(this->start>=start&&this->end<=end) return this->val;
		return min(this->left->query(start,end),this->right->query(start,end));
	}

};


class segment_tree{
private:
	SegTree*root;
public:
	segment_tree(){
		this->root=NULL;
	}
	segment_tree(vector<ll>arr){
		this->root=new SegTree(arr,0,arr.size()-1);
	}

	void update(ll idx, ll val){
		this->root->update(idx,val);
	}

	ll query(ll start, ll end){
		return this->root->query(start,end);
	}
};

void tc(){
	ll N,Q;
	cin>>N>>Q;
	vector<ll> arr(N);
	read(arr);
	segment_tree *sg=new segment_tree(arr);
	for(ll qq=0;qq<Q;qq++){
		ll start,end;
		cin>>start>>end;
		cout<<sg->query(start-1,end-1)<<endl;
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

