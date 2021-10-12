#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	string s[n];
	for(int i = 0; i < n ;i++)
		cin >> s[i];

	// driver code above

	for(string str : s){
		if(str.length() > 10) cout << str.at(0) << str.length() - 2 << str.at(str.length() - 1);
		else cout << str;
		cout << "\n"; 
	}

	return 0;
}

