#include<bits/stdc++.h>
using namespace std;
using ll= long long ;

void run_test_case(){
	ll N,Q;
	cin>>N>>Q;
	vector<vector<ll>> arr(N,vector<ll>(N));
	for(ll i=0;i<N;i++)
		for(ll j=0;j<N;j++){
			char x;
			cin>>x;
			arr[i][j]=x=='*';
		}

	for(ll i=0;i<N;i++)
		for(ll j=1;j<N;j++) arr[i][j]+=arr[i][j-1];

	for(ll j=0;j<N;j++){
		for(ll i=1;i<N;i++) arr[i][j]+=arr[i-1][j];
	}


	for(ll qq=0;qq<Q;qq++){
		ll x1,x2,y1,y2;
		cin>>y1>>x1>>y2>>x2;
		--x1,--x2,--y1,--y2;
		ll res=0;
		if(y1==0){
			if(x1==0) res=arr[y2][x2];
			else res=arr[y2][x2]-arr[y2][x1-1];
		}
		else{
			if(x1==0) res=arr[y2][x2]-arr[y1-1][x2];
			else{
				res=arr[y2][x2];
				res-=arr[y1-1][x2];
				res-=(arr[y2][x1-1]-arr[y1-1][x1-1]);
			}
		}
		cout<<res<<endl;
	}
}

int main(){
	ll t;
	t=1;
	while(t--) run_test_case();
	return EXIT_SUCCESS;
}