
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
void printArray(int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	int n , k ;
	cin >> n >> k ;
	vector<pair<int64_t , int64_t> > pos(n) ;
	for(auto &x : pos){
		int p , t ;
		cin >> p >> t ;
		t *= -1 ;
		x = make_pair(p , t) ;
	} 
	sort(pos.begin() , pos.end()) ;
	reverse(pos.begin() , pos.end()) ;
	int start = k - 2;
	int end = k ;
	int res = 1 ;
	// cout << "-------" << endl ;
	// for(auto x : pos) cout << x.first << " " << abs(x.second) << endl ;
	// cout << "-------" << endl ;
	pair<int64_t , int64_t> check = pos[k - 1] ;
	while(start >=0 && pos[start] == check) ++res , --start ;
	while(end < pos.size() && pos[end] == check) ++res , ++end ;
	cout << res << endl ;
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


