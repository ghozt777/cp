// link : https://codeforces.com/problemset/problem/69/A
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
	int n ;
	cin >> n; 
	int suma = 0 ;
	int sumb = 0 ;
	int sumc = 0 ;
	while(n--){
		int a , b , c ;
		cin >> a >> b >> c ;
		suma += a ;
		sumb += b ;
		sumc += c ;
	}
	suma == 0  && sumb ==0 && sumc == 0? cout << "YES" : cout << "NO" ;
	return ;
}


