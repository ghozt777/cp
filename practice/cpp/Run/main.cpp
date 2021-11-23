
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


bool check(string str){
    for(int i = 0 ; i < str.size() ; i++) if(str[i] != '5' && str[i] != '6') return false ;
    return true ;
}


void Run() {
    int t ; 
    cin >> t ;
    while(t--){
        string str ;
        cin >> str ;
        int c1 = 0 ;
        int c2 = 0 ;
        for(char c : str) if(c != '5' || c!= '6') c1++ ;
        while(!check(str) && c2 < c1){
            str = to_string(stoi(str) + 1) ;
            c2++ ;
        }   
        cout << min(c1 , c2) << endl ;
    }
}




