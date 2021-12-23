
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

#define MULTIPY(a , b) a * b


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

	cout << MULTIPY(2+3 , 3+5) ; // 16 
/*
	Explaination: 
	"MULTIPLY(a, b)" will be replaced by "a*b" in code.
	So, MULTIPLY(2+3, 3+5) will be replaced by 2+3*3+5. And according to operator precedence, multiply operator (*) has higher precedence than plus operator (+). 
	So, 3*3 will be evaluated first. Hence expression will become :
	2+9+5 = 16
/*
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


