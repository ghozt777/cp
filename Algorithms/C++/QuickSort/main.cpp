
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)


void Run();

void swap(int * , int *) ;
void quick_sort(int *);
void quick_sort_util(int * , int , int);
int partition(int * , int , int) ;
void print_arr(int * , int) ;

// mycodeschool video link: https://www.youtube.com/watch?v=COk73cpQbFQ

// Quick Sort Algorithm
// uses divide and conquer algorithm

// Merge Sort : Time Complexity : O(nlog(n))
//				Space Complxity: O(n)

// Quick Sort: Time Complexity: O(nlog(n)) <-- average case
//								O(n*n) <---- Worst Case (can be avoided using a randomized version of quicksort)
//			   Space Complexity: O(1) <--- In Place Sorting


// randomized quick sort time complexity is of O(nlog(n)) with very hight probability


// language libraries most of the time uses quicksort for sorting Eg: STL

/*
	Steps for quick sort: 
	1. Choose a pivot. Can be anything Eg : the last element in the list , the first element in the list or any random element in the list .

	2. Rearrange the list such that all the elements lesser than the pivot are towards the left of it and all the elements greater than the pivot are in the right of it. This process is known as partitionaing of a list . ( the order of the elements dosent matter) 

	3. Divide the problem into subproblems and keep track of the start and the end indices

	4. If there is only one element left in the segment its already sorted and we dont need to go any further. This is the base condition for the recursion .

	Note : the paritioning function after rearrangement of the elements return the index of the pivot .
*/


void swap(int * a , int * b) {
	int temp = * a;
	* a = * b ;
	* b = temp ;
}

void quick_sort(int * arr , int n) {
	quick_sort_util(arr , 0 , n - 1) ;
}

void quick_sort_util(int * arr , int start ,  int end) {
	if(start < end) {
		int pi = partition(arr , start , end) ;
		quick_sort_util(arr , start , pi - 1) ;
		quick_sort_util(arr , pi + 1 , end) ;
	}
	return ;
}

int partition(int * arr , int start , int end) {
	int pivot = arr[end] ;
	int pi = start ;
	for(int i =  start ; i < end ; i++)
		if(arr[i] <= pivot) swap(&arr[i] , &arr[pi++]);
	swap(&arr[pi] , &arr[end]);
	return pi ;
}

void print_arr(int * arr , int n) {
	cout << "[ " ;
	for(int i = 0 ; i < n ; i++ ){
		if(i == n - 1) cout << *arr << " ]\n" ;
		else cout << *(arr++) << ", " ;
	}
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	int n ;
	cin >> n;
	int arr[n] ;
	for(int i = 0 ; i < n ; i++) 
		cin >> arr[i] ;
	quick_sort(arr , n) ;
	print_arr(arr , n) ;
	return ;
}


