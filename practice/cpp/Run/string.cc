#include<bits/stdc++.h>
using namespace std ;

int main(){
	string s = "bcdefg";
	for(int i = 0 ; i < s.length() ; i++){
			string left = s.substr(0,i);
			string right = s.substr(i - 1);
			cout << left << right << endl;
		}

	return 0;
}