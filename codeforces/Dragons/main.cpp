
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
	int s , n ;
  	cin >> s >> n ;
  	pair<int , int> d[n] ;
  	for(int i = 0 ; i < n ; i++){
    	int x , y ;
    	cin >> x >> y ;
    	d[i] = make_pair(x , y) ;
  	}
  	sort(d , d + n) ;
  	for(auto drag : d) {
    	if(s <= drag.first) {
      		cout << "NO" ;
      		return ;
    	}
    	else s += drag.second ;
  	}
  	cout << "YES" ;

	return ;
}


