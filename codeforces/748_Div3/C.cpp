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
	int t ;
	cin >> t;
	while(t--) {
		int n , k;
		cin >> n >> k;
		int arr[k] ;
		for(int i = 0 ; i < k ; i++)
			cin >> arr[i] ;
		sort(arr , arr + k) ;
		int c = 0;
		int cat = 0 ;
		for(int i = k - 1 ; i >= 0 ; i--){
			int mouse = arr[i];
			if(mouse > cat){
				c++ ;
				cat += n - mouse  ;
			}
			else break ;
		}
		cout << c << '\n' ;
	}
 
	return ;
}
 
