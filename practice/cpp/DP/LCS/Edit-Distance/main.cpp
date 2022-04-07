#include<bits/stdc++.h>
using namespace std ;

int edit_distance(string s1 , string s2 , int n , int m){
	if(!n) return m ;
	if(!m) return n ;
	if(s1[n - 1] == s2[m - 1]) return edit_distance(s1, s2, n - 1, m - 1) ;
	else return 1 + min(edit_distance(s1 , s2 , n - 1 , m) , min(edit_distance(s1 , s2 , n - 1, m - 1) , edit_distance(s1 , s2 , n, m - 1))) ;	
}

int edit_distance(string s1 , string s2){
	return edit_distance(s1, s2, s1.length(), s2.length()) ;
}

int main(){
	cout << edit_distance("SATURDAY" , "SUNDAY") << endl ;
	return 0 ;
}
