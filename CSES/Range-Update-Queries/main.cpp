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

class SegTrees{
	ll data;
	ll sum;
	ll start;
	ll end;
	SegTrees*left;
	SegTrees*right;
	SegTrees(vector<ll> arr, ll start, ll end){
		if(start>end) return;
		this->start=start;
		this->end=end;
		if(start==end){
			this->data=0;
			this->sum=arr[start];
			return;
		}
		ll mid=start+(end-start)/2;
		this->left=new SegTrees(arr,start,mid);
		this->right=new SegTrees(arr,mid+1,end);
		this->data=0;
		this->sum=this->left->sum+this->right->sum+this->data;
		return;
	}
	void update(ll start,ll end,ll diff){
		if(this->start>end||this->end<start) return;
		if(this->start>=start&&this->end<=end){
			this->data+=diff;
			return;
		}
		this->left->update(start,end,diff);
		this->right->update(start,end,diff); 
	}

};



void tc(){
	
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

