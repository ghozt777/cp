
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
	string str ;
	cin >> str ;
	string res = "" ;
	for(int i = 0 ; i < str.length() ; ){
		if(i + 2 < str.length() && str.substr(i,3) == "WUB") i += 3 ;
		else{
			int j = i ;
			while(j < str.length()){
				if(j + 2 < str.length() && str.substr(j , 3) == "WUB") break ;
				else ++j ;
			}
			res += str.substr(i , j - i) + " " ;
			i = j ;	
		}

	}
	cout << res << " " ;
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


