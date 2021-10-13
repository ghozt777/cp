#include<bits/stdc++.h>
using namespace std;
int main () {
	string str1 , str2;
	cin >> str1 >> str2 ;
	int i = 0;
	while( i < str1.length() ) {
		if(tolower(str1.at(i)) < tolower(str2.at(i))) {
			cout << -1 ;
			return 0;
		}
		else if(tolower(str1.at(i)) > tolower(str2.at(i))) {
			cout << 1;
			return 0;
		}
		++i;
	}
	cout << 0;
	return 0;
}