#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n;
	int p[n][3];
	int count = 0;
	for(int i = 0; i < n ; i++){
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		if(p[i][0] + p[i][1] + p[i][2] >= 2) ++count;
	}
	cout << count;
	return 0;
}