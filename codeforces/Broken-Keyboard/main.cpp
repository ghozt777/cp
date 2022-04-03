
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

void solve(string s){
	unordered_set<char> added ;
	vector<char> res ;
	for(int i = 0 ; i < s.length() ; i++){
		if(i < s.length() - 1 && s[i] == s[i + 1]){
			++i ; 
			continue ;
		}
		else if(added.find(s[i]) == added.end())added.insert(s[i]) , res.emplace_back(s[i]) ;
	}
	sort(res.begin() , res.end()) ;
	for(char x : res) cout << x ;
	cout << endl ;
}

void Run() {
	// run your code here
	int t ;
	cin >> t ;
	while(t--){
		string s ; 
		cin >> s ;
		solve(s) ;
	}

	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


