#include<iostream>
#include<vector>

using namespace std ;
typedef long long ll ;
#define UB 1000000 

void solve(){
	vector<vector<ll>> ink (3 , vector<ll>(4)) ;
	for(int i = 0 ; i < 3 ; i++) for(int j = 0 ; j < 4 ; j++) cin >> ink[i][j] ;
	ll c , m , y , k ;
	c = min(min(ink[0][0] , ink[1][0]) , ink[2][0]) ;
	m = min(min(ink[0][1] , ink[1][1]) , ink[2][1]) ;
	y = min(min(ink[0][2] , ink[1][2]) , ink[2][2]) ;
	k = min(min(ink[0][3] , ink[1][3]) , ink[2][3]) ;
	if((c + m + y + k) < UB){
		cout << "IMPOSSIBLE" << endl ;
		return ;
	}
	if((c + m + y + k) == UB){
		cout << c << " " << m << " " << y << " " << k << " " ;
		cout << endl ;
		return ;
	}
	else{
		ll excess = (c + m + y + k) - UB ;
		ll p = excess ;
		if(c >= p){
			cout << c - p << " " << m << " " << y << " " << k << " " ;
			cout << endl ;
		}
		else{
			p -= c ;
			if(m >= p){
				cout << 0 << " " << m - p << " " << y << " " << k << " " ;
				cout << endl ;		
			}
			else{
				p -= m ;
				if(y >= p){
					cout << 0 << " " << 0 << " " << y - p << " " << k << " " ;
					cout << endl ;		
				}
				else{
					p -= y ;
					cout << 0 << " " << 0 << " " << 0 << " " << k - p << " " ;
					cout << endl ;	
				}
			}
		}
		return ;
	}
}

int main(){
	int t ;
	cin >> t ;
	for(int tt = 1 ; tt <= t ; tt++){
		cout << "Case #" << tt << ": " ;
		solve() ; 
	}
	return 0 ;
}