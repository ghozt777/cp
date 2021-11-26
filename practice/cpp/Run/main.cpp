
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



int divCount(int n){
    int c = 1 ;
    for(int i = 0 ; i <= n ; i++) if(n%i == 0) ++c ;
        return c ;
}

void Run() {
    int n ;
    cin >> n ;
    int arr[n] ;
    f(n) cin >> arr[i] ;
    int c = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int s = 0 ;
            for(int k = i ; k < j ; k++){
                s += divCount(arr[k]) ;
            }
            if(s%2 == 1) ++c ;
        }
    }
    cout << c ;
}




