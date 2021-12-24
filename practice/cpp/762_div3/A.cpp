
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

void runCase() {
	string str ;
	cin >> str ;
	int n = str.size() ;
	if(n% 2 != 0){
		cout << "NO\n" ;
		return ;
	}
	for(int i = 0 ; i < n / 2 ; i++){
		if(str[i] != str[n/2 + i]){
			cout << "NO\n" ;
			return ;
		}
	}
	cout << "YES\n" ;
}

void Run() {
	// run your code here
	int test ;
	cin >> test ;
	while(test-- > 0)
		runCase() ;

	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


