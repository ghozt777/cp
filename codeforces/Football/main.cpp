
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
	int n ;
	cin >> n;
	vector<string> str;
	for(int i = 0. ; i < n ; i++){
		string temp;
		cin >> temp;
		str.PB(temp);
	}
	sort(str.begin() , str.end());
	int count = 1;
	int maxCount = 1;
	int index = 0;

	for(int i = 1 ; i < n ;i++){
		if(str[i] == str[i-1]) ++count;
		else count = 1;
		if(count > maxCount){
			maxCount = count;
			index = i;
		}
	}

	cout << str[index];

	return ;
}


