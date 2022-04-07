#include<bits/stdc++.h>
using namespace std ;


bool subset_sum(int * arr , int sum , int n){
	if(sum == 0) return true ;
	if(n == 0) return false ;
	return subset_sum(arr , sum - arr[n - 1] , n - 1) || subset_sum(arr , sum , n - 1) ;
}

int main(){
	int arr[] = {2,3,7,8,10} ;
	cout << subset_sum(arr, 11, sizeof(arr) / sizeof(int)) ;
	return 0 ;
}