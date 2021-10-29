
// link : https://codeforces.com/problemset/problem/58/A
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
	vector<pair<char , int>> check(5 , make_pair('x' , -1));
	for(int i = 0 ; i < size(str) ; i++){
		if(str[i] == 'h' && check[0].first == 'x') check[0] = make_pair('h' , i) ;
		if(str[i] == 'e' && check[0].first == 'h' && check[1].first == 'x') check[1] = make_pair('e' , i) ;
		if(str[i] == 'l' && check[1].first == 'e' && check[2].first == 'x') check[2] = make_pair('l' , i) ;
		if(str[i] == 'l' && check[2].first == 'l' && check[3].first == 'x' && i != check[2].second) check[3] = make_pair('l' , i) ;
		if(str[i] == 'o' && check[3].first == 'l' && check[4].first == 'x') check[4] = make_pair('o' , i) ;
	}
	// for(auto x : check) {
	// 	cout <<  "char: " << x.first << " pos: " << x.second << "\n" ;
	// }
	if(check[0].first == 'x') {
		cout << "NO" ;
		return ;
	}
	for(int i = 1 ; i < 5 ; i++){
		if(check[i].second < check[i-1].second || check[i].first == 'x'){
			cout << "NO" ;
			return ;
		}
	}
	cout << "YES" ;
	return ;
}


