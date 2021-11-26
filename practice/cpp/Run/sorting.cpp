#include<bits/stdc++.h>
using namespace std ;

void printArr(int arr[] , int n){
	if(n==0){
		cout << "[]\n" ;
		return ;
	}
	else if(n==1){
		cout << "[" << arr[0] << "]\n" ;
		return ;
	}
	else{
		cout << "[" << arr[0] << ", " ;
		for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ;
		cout << arr[n-1] <<"]\n" ;
		return ;
	}
}

// binary search : 

int binarySearchUtil(int arr[] , int start , int end , int x){
	if(start > end) return -1 ;
	int mid = start + (end - start) / 2 ; 
	if(arr[mid] == x) return mid ;
	if(arr[mid] > x) return binarySearchUtil(arr , start , mid - 1 , x) ;
	else return binarySearchUtil(arr , start + 1 , end , x);
}

int binarySearch(int arr[] , int n  , int x){
	return binarySearchUtil(arr , 0 , n-1 , x) ;
}


// bubble sort : 

void bubbleSort(int arr[] , int n){
	for(int i = 0 ; i < n - 1; i++){
		bool didSwap = false ;
		for(int j = 0 ; j < n - 1 - i ; j++){
			if(arr[j] > arr[j+1]){ swap(arr[j] , arr[j+1]) ; didSwap = true ;} 
		}
		if(!didSwap) return ;
	}
}


// selection sort : 

int findMin(int arr[] , int start , int end){
	int _min = arr[start] ;
	int idx = start ;
	for(int i = start + 1 ; i <= end ; i++){
		if(arr[i] < _min){
			_min = arr[i] ;
			idx = i ;
		}
	}
	return idx ;
}

// select the minimum valued element and start adding them to the start 
// this can also be approached by selecting the maximum valued element and the  adding them to the end

void selectionSort(int arr[] , int n){
	int min_idx ;
	for(int i = 0 ; i < n - 1 ; i++){
		min_idx = findMin(arr , i , n-1) ;
		swap(arr[min_idx] , arr[i]) ;
	}	
}

void Run(){
	// binary search for sorted arrays
	int arr[] = {1,3,5,7,8,10,99,101,101,102}  ;
	cout << "In the array : " ;
	printArr(arr , sizeof(arr) / sizeof(arr[0])) ;
	cout << "Index(0-based) of 10 is : " << binarySearch(arr , sizeof(arr) / sizeof(arr[0]) , 10)  << endl;
	// bubble sort:
	int arr1[] = {5,2,-1,6,-31,3490,-90,1,-1,-1,-1,0,0,0,12,34} ;
	cout << "Before sorting : " ;
	printArr(arr1 , sizeof(arr1) / sizeof(arr1[0])) ;
	bubbleSort(arr1 , sizeof(arr1) / sizeof(arr1[0])) ;
	cout << "After sorting : " ;
	printArr(arr1 , sizeof(arr1) / sizeof(arr1[0])) ;
	int arr2[] = {5,2,-1,6,-31,3490,-90,1,-1,-1,-1,0,0,0,12,34} ;
	cout << "Before sorting : " ;
	printArr(arr2 , sizeof(arr2) / sizeof(arr2[0])) ;
	selectionSort(arr2 , sizeof(arr2) / sizeof(arr2[0])) ;
	cout << "After sorting : " ;
	printArr(arr2 , sizeof(arr2) / sizeof(arr2[0])) ;

}





























int main(){
	Run() ;
	return 0 ;
}
