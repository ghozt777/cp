// link: https://codeforces.com/problemset/problem/118/A
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

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	string str ;
	cin >> str ;
	transform(str.begin(), str.end(), str.begin(), ::tolower) ;
	vector<char> str_new;
	for(char x : str){
		if(x == 'a' || x == 'o' || x == 'y' || x == 'e' || x == 'u'|| x == 'i') continue ; 
		else{
			str_new.PB('.');
			str_new.PB(x) ;
		}
	}
	for(auto x = str_new.begin() ; x != str_new.end() ; x++)
		cout << *x ;
	return ;
}

