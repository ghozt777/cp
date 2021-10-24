// Dutch National Flag Algo : used to sort an array with 3 elements
#include<bits/stdc++.h>
using namespace std ;
void dnf_sort(int * , int) ;
void print_arr(int *, int);
void swap(int * , int *) ;
int main () {
  int arr[] = { 1,2,3,1,2,3,1,2,3,2,2,1,1,3,3,2,3,1,2};
  dnf_sort(arr , sizeof(arr) / sizeof(arr[0]));
  print_arr(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}
void swap(int * a , int * b) {
	int temp = * a;
	* a = * b ;
	* b = temp ;
}

void print_arr(int * arr , int n) {
	cout << "[ " ;
	for(int i = 0 ; i < n ; i++ ){
		if(i == n - 1) cout << *arr << " ]\n" ;
		else cout << *(arr++) << ", " ;
	}
}

void dnf_sort(int * arr , int n) {
  int low = 0 ;
  int high = n - 1;
  int curr = 0;
  while(curr < high) {
    if(arr[curr] == 1) swap(&arr[curr++] , &arr[low++]);
    else if(arr[curr] == 2) curr++ ;
    else swap(&arr[curr] , &arr[high--]) ;
  }
}
