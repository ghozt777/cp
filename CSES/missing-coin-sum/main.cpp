/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Sun Jun  5 19:15:00 IST 2022
	Link to problem / contest : https://cses.fi/problemset/task/2183
*/


#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pi = pair<int , int> ;

#define EB emplace_back
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i=0;i<n;i++)
#define fr(itr, n) for(int itr=0;itr<n;itr++)
#define F(s,e) for(int i=s;i<=e;i++)
#define c(arr,x) count(arr.begin() , arr.end() , x)
#define _max(arr) * max_element(arr.begin() , arr.end())
#define _min(arr) * min_element(arr.begin() , arr.end())
#define _max_pos(arr) max_element(arr.begin() , arr.end()) - arr.begin()
#define _min_pos(arr) min_element(arr.begin() , arr.end()) - arr.begin()
#define what_is(x) cout << #x << ": " << x << endl ;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
// requires c++17
template<typename... Args>void read(Args&... args){((cin >> args), ...);}
template<typename T>void read(vector<T> &arr){for(auto & a : arr) cin >> a ;}
template<typename T>void write(vector<T> &arr){for(auto & a : arr) cout << a << " " ;}
const ll MOD = pow(10,9)+7 ;


vvi adj ;
vector<bool> vis ;
void init(int v){adj.clear() ;vis.clear() ;adj.resize(v) ;vis.resize(v , false) ;}
void dfs(int s){vis[s] = true ;for(auto x : adj[s]) if(!vis[x]) dfs(x) ;}

void solve(){
	// to execute for each test case
    
    /*
    
        BASIC IDEA TO SOLVE : 
        
        Step 1 : First sort the array as we need to find the minimum sum we can't make using the array 
        
        Step 2 : Initially We assume that the asnwer = 1 
        
        Step 3 : We traverse the array in order and we check : 
                    
                CASE  i : possibleAns < arr[i] -> break the loop
                
                if the current possible answer is smaller that the number at the current index then 
                        this is our answer i.e. the sum that can't be formed as all the numbers later in the 
                        array are gonna be greater than value at possibleAns hence this is the least sum 
                        that can't be formed
                        
                CASE  ii : possibleAns >= arr[i] -> possibleAns += arr[i] 
                
                if the current possible answer is greater or equal to the current element in the 
                             array
                             then we increment the possible answer by that element i.e. possibleAns += arr[i] 
                             Now the reason why its particularly the current element by which we increment the possible answer is that :
                                if we were to add by by any smaller number say 1 or 2 or arr[i] - 1
                            then we would have caught the answer in the previous iteration so its
                            guranteed that it can't be any number smaller than arr[i] that we need 
                            to increment possibleAns by 
                        Hence we increment possibleAns by arr[i] 
                        i.e. possibleAns += arr[i] ;
    */
    
    
    int n ;
    cin >> n ;
    vector<ll> arr(n) ;
    read(arr) ; 
    sort(arr.begin() , arr.end()) ;
    ll possibleAns = 1 ;
    for(ll x : arr){
        if(possibleAns >= x) possibleAns += x ;
        else break ;
    }
    cout << possibleAns << endl ;
}

int main(){
	// io optimization
	// please make sure to flush the o/p stream using endl or cout.flush()
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
    cout << std::fixed;
    cout << std::setprecision(12);
	int t = 1 ;
	while(t--) solve() ;

	return EXIT_SUCCESS ;
}

