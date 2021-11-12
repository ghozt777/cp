// link: https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1/
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

void printArray(int[] , int) ;

void Run();

void solve() ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	solve() ;
	return ;
}


void solve(){
	int n ;
	cin >> n ;
	int arr[n] ;
	for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
	for(int i = 0 ; i < n ; i++) arr[i] += (arr[arr[i]]%n)*n ;
	for(int i = 0 ; i < n ; i++) arr[i] /= n ;
	printArray(arr , n) ; 
}

/*
Question : Given an array arr[] of size n where every element is in range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]]. This should be done with O(1) extra space.

Test Cases: 

Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation: 
arr[arr[0]] = arr[1] = 0.
arr[arr[1]] = arr[0] = 1.

Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1
Explanation: 
arr[arr[0]] = arr[4] = 3.
arr[arr[1]] = arr[0] = 4.
and so on.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Approach: The array elements of the given array lies from 0 to n-1. Now an array element is needed that can store two different values at the same time. To achieve this increment every element at ith index is incremented by (arr[arr[i]] % n)*n.After the increment operation of first step, every element holds both old values and new values. Old value can be obtained by arr[i]%n and a new value can be obtained by arr[i]/n.

How this can be achieved? 
Let's assume an element is a and another element is b, both the elements are less than n. So if an element a is incremented by b*n. So the element becomes a + b*n so when a + b*n is divided by n then the value is b and a + b*n % n is a

Algorithm:  
1.Traverse the array from start to end.
2.For every index increment the element by array[array[index] ] % n. To get the ith element find the modulo with n, i.e array[index]%n.
3.Again Travsese the array from start to end
4.Print the ith element after dividing the ith element by n, i.e. array[i]/n.

*/


void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}
