#include<bits/stdc++.h>
using namespace std;

int main() {
	string name ; 
	cin >> name;
	char ca[name.length()];
	strcpy(ca , name.c_str());
	sort(ca , ca + name.length());
	int c = 1;
	for(int i = 1 ; i < name.length(); i++)
		if(ca[i]!=ca[i-1]) ++c;
	c%2 != 0 ? cout << "IGNORE HIM!" : cout << "CHAT WITH HER!";
	return 0;
}