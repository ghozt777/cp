
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
	int n , q ;
	cin >> n ;
	int x[n] ;
	for(int i = 0 ; i < n ; i++)
		cin >> x[i] ;
	cin >> q ;
	int d[q] ;
	for(int i = 0 ; i < q ; i++)
		cin >> d[i] ;
	sort(x , x + n) ;
	for(int i = 0 ; i < q ; i++){
		if(d[i] < x[0]){
			cout << "0\n" ;
			continue ; 
		}
		int start = 0 ;
		int end = n - 1 ;
		while(start <= end){
			int mid = start + (end - start) / 2 ;
			if(x[mid] == d[i]){
				end = mid ;
				break ;
			}
			else if(x[mid] < d[i]) start = mid + 1 ;
			else end = mid - 1 ;
		}
		cout << end + 1  << "\n" ;

	}

	return ;
}


