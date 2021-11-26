#include<bits/stdc++.h>
using namespace std ;

 

// this program has nothing to do with anything its just for practice
void Run(){
	int arr[] = {1,2} ; // we may or maynot provide the size
	// if we initialze anyone of the elements in an array and be dont initialize other elements then they are initialized with 0 for the case of an integer array 
	// Eg : 
	int a[6] = {1,2,3} ; // o/p : 1 2 3 0 0 0 
	for(int i = 0 ; i < 6 ; i++)
		cout << a[i] << " " ;
	cout << endl ;
	// Therfore to initialize all the elements of an array of a large size use the following syntax
	int b[10000] = {0} ; // all the elements in the array are now initialized to 0

}

int main(){
	Run() ;
	return 0 ;
}
