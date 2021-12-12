#include<bits/stdc++.h>
using namespace std ;

#define fr(n , x) for(int x = 0 ; x < n ; x++)

void Run() {
	// 2D arrays are internally stored as 1D array of size row x column
	// coversion of the 1D index from 2D index is done by the system
	// 2D index to 1D index conversion : cxi + j for (i,j) index where c denotes the number of columns
	int rows = 3 ;
	int columns = 4 ;
	int arr[100][100] ; // do not create a variable size array
	fr(rows , i) fr(columns , j) arr[i][j] = 0 ; // initialize the array with 0s 

}

// when using a function that takes a 2D array as an argument we need to metion the value of c inside the seond square bracket 
// for the conversion of the 2d indices to 1d without the value of c the program will generate an error 

void print2Darray(int arr[][100] , int m , int n){
	fr(m,i){
		fr(n,j) cout << arr[i][j] << " " ;
		cout << endl ;
	}
}

void findLargest(int arr[][100], int m, int n)
{
    //Write your code here
    int _max = INT_MIN ;
    string ans ;
    int ansI , ansJ ;
    int i , j ;
    for(i = 0 ; i < m ; i++){
    	int s = 0 ;
    	for(j = 0 ; j < n ; j++) s += arr[i][j] ;
    		if(_max < s){
    			ansI = i ;
    			ansJ = j ;
    			ans = "row" ;
    			_max = s ;
    		}
    }

    for(i = 0 ; i < n ; i++){
    	int s = 0 ;
    	for(j = 0 ; j < m ; j++) s += arr[j][i] ;
    		if(_max < s){
    			ansI = j ;
    			ansJ = i ;
    			ans = "column";
    			_max = s ;
    		}
    }
    if(ans == "row") cout << "row" << " " << ansI << " " << _max ;
    else cout << "column" << " " << ansJ << " " << _max ;
    cout << endl ;
}

void ProblemSolver() {
	int n , m ;
	cout << INT_MIN ;
	// int arr[100][100] ;
	// int t ;
	// cin >> t ;
	// while(t--){
	// 	cin >> m >> n ;
	// 	for(int i = 0 ; i < n ; i++){
	// 		for(int j = 0 ; j < m ; j++) cin >> arr[i][j]  ;
	// 	}
	// 	findLargest(arr , n , m) ;
	// }
}



int main(){
	Run() ;
	ProblemSolver() ;
	return 0 ;
}