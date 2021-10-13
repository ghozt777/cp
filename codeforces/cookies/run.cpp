#include<bits/stdc++.h>
using namespace std;
int main () {
	int n ;
	cin >> n ;
	int cookies[n];
	int total = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> cookies[i];
		total += cookies[i];
	}
	int count = 0;
	for(int cookie : cookies){
		if((total - cookie) % 2 == 0) ++count;
	}
	cout << count;
	return 0;
}