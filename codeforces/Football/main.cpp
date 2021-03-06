
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
	string str;
	cin >> str ;
	for(int i = 0; i < str.length() ; ){
		char start = str[i] ;
		int j = i + 1 ;
		while(j < str.length() && str[j] == start) ++j ;
		if(j - i >= 7){
			cout << "YES" << endl ;
			return ;
		}
		i = j ;
	}
	cout << "NO" << endl ;
	return ;
}


