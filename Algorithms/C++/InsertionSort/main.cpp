#include<bits/stdc++.h>
using namespace std ;

void insertion_sort(int * , int) ;
void insertion_sort_v2(int * , int) ;
void print_arr(int * , int);


void swap(int * a , int * b) {
	int temp = * a;
	* a = * b ;
	* b = temp ;
}


int main () {
  int arr[] = {3,3,-1,4,5,2,1,69} ;
  insertion_sort(arr,sizeof(arr) / sizeof(arr[0])) ;
  int arr2[] = {3,3,-1,4,5,2,1,69} ;insertion_sort_v2(arr2, sizeof(arr2) / sizeof(arr2[0]));
  print_arr(arr2, sizeof(arr2) / sizeof(arr2[0])) ;
  print_arr(arr, sizeof(arr) / sizeof(arr[0])) ;
  return 0 ;
}

void insertion_sort(int * arr , int n) {
  for(int i = 1 ; i < n ; i++){
    int j = i - 1 ;
    int temp = arr[i];
    while(j>=0 && arr[j] > temp) {
      arr[j+1] = arr[j] ;
      j--;
    }
    arr[j+1] = temp ;
  }
}

void insertion_sort_v2(int * arr , int n) {
  for(int i = 0 ; i < n - 1 ; i++){
    for(int j = i + 1 ; j > 0 ; j--){
      if(arr[j] < arr[j-1]) swap(&arr[j] , &arr[j-1]) ;
      else break ;
    }
  }
}

void print_arr(int * arr , int n) {
	cout << "[ " ;
	for(int i = 0 ; i < n ; i++ ){
		if(i == n - 1) cout << *arr << " ]\n" ;
		else cout << *(arr++) << ", " ;
	}
}