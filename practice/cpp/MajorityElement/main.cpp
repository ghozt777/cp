// Given an array a majority element is one that appears more than n/2 times
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

void printArray(int arr[] ,int n){
	if(n==0){
		cout << "[]" ;
		return ;
	}
	cout << "[" << arr[0] << ", " ;
	for(int i = 1 ; i < n-1 ; i++) cout << arr[i] << ", " ;
	cout << arr[n-1] << "]\n" ;
}

namespace myApproach{
	void bruteforce(int[] ,int);
	void majority(int[] , int) ;
}

// Using Boyer-Moore Voting Algorithm : It takes O(n) time and O(1) Auxiliary Space
void majority(int[] , int) ; 


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	int arr[] = {20,30,40,50,50,50,50} ;
	cout << "Majority Element in the array: " ;
	printArray(arr , sizeof(arr) / sizeof(arr[0])) ;
	myApproach::bruteforce(arr , sizeof(arr) / sizeof(arr[0])) ;
	cout << "\n" ;
	myApproach::majority(arr , sizeof(arr) / sizeof(arr[0])) ;
	cout << "\n" ;
	majority(arr , sizeof(arr) / sizeof(arr[0])) ;
	return ;
}


// O(n^2) : TC
void myApproach::bruteforce(int arr[] , int n){
	// we consider each element as the majority element and confirm the same
	for(int i = 0 ; i < n ; i++){
		int c = 1 ;
		for(int j = i + 1 ; j < n ; j++){
			if(arr[i] == arr[j]) ++c;
		}
		if(c > n / 2){
			cout << "value : " << arr[i] << " pos : " << i ;
			return ;
		}
	}
	cout << "No Majority Element" ;
}


// O(nlog(n)) : TC
void myApproach::majority(int arr[] , int n){
	int i ;
	map<int , int> m ;
	for(i = 0 ; i < n ; i++) m.insert({arr[i] , i}) ;
	sort(arr , arr+n) ;
	int c = 1 ;
	for(i = 1 ; i < n ; i++){
		if(arr[i] == arr[i-1]) ++c ;
		if(c > n/2) break ;
		if(arr[i] != arr[i-1]) c = 1 ;
	}
	c > n/2 ? cout << "value : " << arr[i] << " pos : " << m.find(arr[i])->second : cout << "No Majority Element" ;
}


// Efficinet Solution : O(n)
void majority(int arr[] , int n){
	// phase 1 : find a candidate
	int res = 0  , c = 1 ;
	for(int i = 1 ; i < n ; i++){
		if(arr[i] == arr[res]) ++c ;
		else c-- ;
		if(c == 0){
			res = i ;
			c = 1 ;
		}
	}

	// phase 2: check if the candidate is actually the majority:
	c = 0 ; 
	for(int i = 0 ; i < n ; i++)
		if(arr[i] == arr[res]) ++c ;
	c > n/2 ? cout << "value : " << arr[res] << " pos : " << res : cout << "No majority Element" ;

}

