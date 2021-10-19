
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

	int upper = 0;
	int len = 0;
	string str;
	getline(cin , str);
	for(char c : str){
		++len;
		if((int)c < 97) upper++;
	}
	if(upper > len/2){
		transform(str.begin(), str.end(), str.begin(), ::toupper);
		cout << str ;
	}
	else{
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		cout << str ;
	}
	return ;
}


