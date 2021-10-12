#include<bits/stdc++.h>
using namespace std;

int main() {
	int n ;
	string s;
	cin >> n >> s;

	int c = 0;
	int start = 0;
	int end = n - 1;
	for(int i = 1; i < n ;i++){
		if(s.at(i-1) == s.at(i)) ++c;
	}
	cout << c;
	return 0;
}