#include<bits/stdc++.h>
using namespace std;

void ans(int[] , int , int);

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt" , "r" , stdin);
		freopen("output.txt" , "w" , stdout);
	#endif
	
	int n , x ;
	cin >> n >> x;
	int w[n];
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}	
	ans(w,n,x);
	return 0;
}
void ans(int *w , int n , int x){
	sort(w,w+n);
	int start = 0;  
	int end = n - 1;
	int c = 0;
	while(start<=end){
		if(w[start]+w[end]<=x){
			++start;
			--end;
			++c;
	
		}
		else {
			++c;
			--end;
		}
	}
	cout << c;
}