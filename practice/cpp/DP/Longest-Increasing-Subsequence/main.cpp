#include<iostream>
#include<vector>

using namespace std ;

const int NEGATIVE_INF = INT_MIN ;

int LIS(vector<int> &arr , int n , int curr , int last){
	if(n == 0) return curr ;
	if(last ==  NEGATIVE_INF || arr[n - 1] < last) return max(LIS(arr , n - 1 , curr + 1 , arr[n - 1]) , LIS(arr , n - 1 , curr , last)) ;
	else return LIS(arr , n - 1 , curr , last) ;
}


int LIS(vector<int> & arr){
	return LIS(arr , arr.size() , 0 , NEGATIVE_INF) ;
}

int main(){

	vector<int> arr = {4,10,6,5,8,11,2,20} ;

	cout << LIS(arr) << endl ;

	return 0 ;
}