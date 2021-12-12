// link : https://codeforces.com/problemset/problem/499/B
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


void Run();;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
   int n , m ;
   cin >> n >> m ;
   unordered_map<string , string> d ;
   f(m){
    string a , b ;
    cin >> a >> b ;
        d.insert({a , size(a) <= size(b) ? a : b}) ;
   }
   f(n){
    string ip ;
    cin >> ip ;
    cout << d.find(ip)->second << " " ;
   }
}



