
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


int maxFreq(int * arr , int n){
	sort(arr , arr + n) ;
	int res = 1 ;
	int curr = 1 ;
	int e = arr[0] ;
	for(int i = 1 ; i < n ; i++){
		if(arr[i] == e){
			++curr ;
			res = max(res , curr) ;
		}
		else{
			curr = 1 ;
			e = arr[i] ;
		}
	}
	return res ;
}


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
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int arr[n] ;
		int res = 0 ;
		for(int i = 0; i < n ; i++) cin >> arr[i] ;
		int count = maxFreq(arr , n)  ;
		if(count < n){
			while(count < n){
				++res ;
				count *= 2 ;
				if(count >= n) break ; 
				res += count / 2 ;
			}
			res += n - count / 2 ;
			cout << res << '\n' ;
		}
		else cout << 0 << '\n' ;
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


