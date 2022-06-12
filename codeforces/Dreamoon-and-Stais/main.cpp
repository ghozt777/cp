/*
	Author: ghozt777
	codeforces: https://codeforces.com/profile/ghozt777
    Time: Wed Jun  8 19:43:08 IST 2022
	Link to problem / contest : https://codeforces.com/problemset/problem/476/A
*/


/*

	BASIC IDEA : 

	for a given n say 10 the minimum number of moves = n / 2 : and maxmimum number of moves = n ;
	
		Eg: if n = 10 
			2 2 2 2 2 -> 5 moves (min = n / 2)
			2 2 2 2 1 1 -> 6 moves
			2 2 2 1 1 1 1 -> 7 moves
			2 2 1 1 1 1 1 1 -> 8 moves
			2 1 1 1 1 1 1 1 1 -> 9 moves
			1 1 1 1 1 1 1 1 1 1 -> 10 moves (max = n)

			so in the range of [n/2 , n] we need the mind the minumum number that is a multiple of m 
			if there is no such number then the answer = -1 


*/

#include<bits/stdc++.h>
using namespace std ;

void solve(){
	int n , m ;
	cin >> n >> m ;
	int lower_bound = n / 2 + n % 2 ;
	for(int i = lower_bound ; i <= n ; i++){
		if(i % m == 0){
			cout << i ;
			return ;
		}
	}
	cout << -1 ;
}


int main(){
	int t = 1 ;
	while(t--) solve() ;
	return EXIT_SUCCESS ;
}