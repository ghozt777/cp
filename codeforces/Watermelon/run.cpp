#include<bits/stdc++.h>
using namespace std;

void ans(int);

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt" , "r" , stdin);
		freopen("output.txt" , "w" , stdout);
	#endif
	int n;
	cin >> n;
	ans(n);
	return 0;
}

void ans(int n ){
	for(int i = 2 ; i < n ; i += 2){
		if((n - i) % 2 == 0) {
			cout << "YES";
			return ;
		}
	}
	cout << "NO" ; 
	return ;
}