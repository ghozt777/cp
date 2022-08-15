#include<bits/stdc++.h>
using namespace std;
using ll=long long;

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

int main(){
	ll N,T;
	cin>>N>>T;
	vector<pair<ll,ll>> arr;
	for(ll i=0;i<N;i++){
		ll a;
		cin>>a;
		arr.push_back({a,i});
	}
	sort(arr.begin(),arr.end());
	for(ll i=0;i<N;i++){
		auto r=bs(arr,i+1,N-1,T-arr[i].first);
		if(r.first!=-1){
			cout<<arr[i].second+1<<" "<<r.first+1<<" "<<r.second+1<<endl;
			return EXIT_SUCCESS;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return EXIT_SUCCESS;
}