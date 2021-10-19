
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)


void Run();


int main(){

	Run();

    return 0;
}

void Run() {
	// run your code here

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	int count = 0;
	getline(cin , str);
	for(char c : str){
		if(isupper(c) != 0) ++count;
	}
	if(count == size(str) || ( isupper(str[0]) == 0) && count == size(str) - 1 ){
		for(char c : str)
			isupper(c) == 0 ? cout << (char)toupper(c) : cout << (char)tolower(c);
	}
	else cout << str;

	return ;
}


