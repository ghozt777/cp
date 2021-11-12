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


vi prefixSumArray(int[] , int) ;
int getSum(int[] , int , int) ;
void equilibrium(int[] , int) ;
void equilibriumConstantSpace(int[] , int) ;
void isSorted(int[] , int) ;
void printArray(int[] , int) ;
void nRanges(int[] , int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	int arr[] = {2,8,3,9,6,5,4} ;
	vi ps = prefixSumArray(arr , sizeof(arr) / sizeof(arr[0])) ;
	cout << "Prefix Sum:\n" ;
	for(vector<int>::iterator x = ps.begin() ; x!= ps.end() ; x++)
		cout << *x << " " ;
	cout << "\n" ;
	int arr1[] = {3, 4, 8, -9, 20, 6} ;
	equilibrium(arr1 , sizeof(arr1) / sizeof(arr1[0])) ;
	equilibriumConstantSpace(arr1 , sizeof(arr1) / sizeof(arr1[0])) ;
	int sorted[] = {8, 12, 12, 13, 14, 99} ;
	int notSorted[] = {8, 12, 11, 11, 13, 14, 99} ;
	printArray(sorted , sizeof(sorted) / sizeof(sorted[0])) ;
	cout << " verdict: " ;
	isSorted(sorted , sizeof(sorted) / sizeof(sorted[0])) ;
	printArray(notSorted , sizeof(notSorted) / sizeof(notSorted[0])) ;
	cout << " verdict: " ;
	isSorted(notSorted , sizeof(notSorted) / sizeof(notSorted[0])) ;
	int L[] = {1,4,3,1} ;
	int R[] = {5,8,5,4} ;
	nRanges(L,R,sizeof(L) / sizeof(L[0])) ;
	return ;
}


vi prefixSumArray(int arr[] ,int n){
	vi ps(n,0) ;
	ps[0] = arr[0] ;
	f(n) if(i!=0) ps[i] = ps[i-1] + arr[i] ; // this enables to create queries regarding the sum in constant time 
	// getSum(l,r) = prefixSum(r) - prefixSum(l-1) [if l ≠ 0]
	// getSum(0,r) = prefixSum(r)  				   [if l = 0]
	return ps ;
}

int getSum(int ps[] , int l ,int r){
	// Given a fixed array and multiple queries of following types on the array , find a way to efficiently perform the queries :
	// Eg: [2, 8, 3, 9, 6, 5, 4]
	// getSum(0,2)
	// getSum(1,3)
	// getSum(2,6)
	return l == 0 ? ps[r] : ps[r] - ps[l-1] ;
}

void equilibrium(int arr[]  , int n){
	// Given an array of integers , find if it has an equilibirum point . 
	// An equilibrium point is one as which the sum of all the elements left to it is equal to the sum of all the elemets right to it .
	// Eg: [3, 4, 8, -9, 20, 6] <- In this case 20 is the equilibrium point
	// Also corner elements are considered and the elements before / after the corner elements are considered to be 0
	// Eg: [4, 2, -2] <- 4 is the eq. pt


	// Solution : We need to comopute the prefix sum and the suffix sum 
	vi ps(n,0) ;
	vi ss(n,0) ;
	ps[0] = arr[0] ;
	ss[n-1] = arr[n-1] ;
	for(int i = 1 ; i < n ; i++){
		ps[i] = ps[i-1] + arr[i] ;
		ss[n-1 - i] = ss[n-1 - i + 1] + arr[n-1-i] ;
	}
	for(int i = 0 ; i < n ; i++){
		if(ps[i] == ss[i]){
		 	cout << "YES\n" ;
		 	return ;
		}
	}
	cout << "NO\n" ;

	// But this approach takes O(n) extra space 
}

void equilibriumConstantSpace(int arr[] , int n){
	int sum = 0 ;
	int lSum = 0 ; 
	for(int i = 0 ; i < n ; i++) sum += arr[i] ;
	for(int i = 0 ; i < n ; i++){
		if(lSum == sum - arr[i]){
			cout << "YES\n";
			return ;
		}
		lSum += arr[i] ;
		sum -= arr[i] ;
	}
	cout << "NO\n" ;
}


void isSorted(int arr[] , int n){ // only checks for increasingly sorted arrays
	bool f = true ;
	for(int i = 1 ; i < n ; i++)
		if(arr[i] < arr[i-1]){
			f = false ;
			break ;
		}
	f ? cout << "IS SORTED\n" : cout << "NOT SORTED\n" ;
}


void nRanges(int L[] , int R[] , int n){
	// Given n ranges , find the maximum occuring element in the ranges
	// L[] = {a1 , a2 , a3 , a4 ....}
	// R[] = {b1 , b2 , b3 , b4 ....}
	// the ranges are : [a1 , b1] , [a2 , b2] , [a3 , b3] .....
	// assume L[i] <= R[i]  L = lowerbound , R = upperbound
	vi r(10e6 , 0) ;
	// mark end and begining of each range
	for(int i = 0 ; i < n ; i++){
		r[L[i]]++ ;
		r[R[i] + 1]--; // element right after the end of the range is decremented to nullify the effect of the range during computation of the prefix sum
	}
	int max = r[0] ;
	int elem = 0 ;
	// compute the prefix sum
	for(int i = 1 ; i < 10e6 ; i++){
		r[i] += r[i-1] ;
		if(r[i] > max){
			max = r[i] ;
			elem = i ;
		}
	}
	cout << "Max Occuring Elemenet is : " << elem << "\n" ;
}


void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}
