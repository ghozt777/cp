
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

void Q1() ;
void Q2() ;
void Q3() ;
namespace q1 {
	void bruteforce(int[] , int , int) ;
	void windowSliding(int[] , int , int) ;
}

namespace q2 {
	void bruteforce(int[] , int , int , int) ;
	void windowSliding(int[] , int , int , int) ;
}

namespace q3 {
	void bruteforce(int[] , int , int) ;
	void windowSliding(int[] , int , int) ;
}

void nFibbonacci(int , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	Q1() ;
	Q2() ;
	Q3() ;

	nFibbonacci(3,8) ; 
	nFibbonacci(4,10) ; 

	return ;
}


void Q1(){
	// Question : Given an array of integers of size n and a number k, find the maximum sum of k consecutive inetegrs
	int n , k;
	cin >> n >> k ;
	int arr[n] ;
	for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
	q1::bruteforce(arr , n , k) ;
	q1::windowSliding(arr , n , k) ;
	
}

void q1::bruteforce(int arr[] ,int n , int k){
	// In this approach we consider every element in the array as the stating element
	// TC : O((n-k)*k) Quadratic
	int ans = INT_MIN ;
	for(int i = 0 ; i < k && (i + k) < n ; i++){
		int curr = 0 ;
		for(int j = 0 ; j < k ; j++){
			curr += arr[j+i] ;
		}
		ans = max(ans,curr) ;
	}
	cout << ans << "\n" ;
 }

 void q1::windowSliding(int arr[] , int n ,int k){
 	// TC: O(n) Linear
 	// Intitialize the current sum window by traversing the first k elements
 	int curr = 0 ;
 	for(int i = 0 ; i < k ; i++) curr += arr[i] ;
 	int ans = curr ;
 	// start of the current window = 0 ;
 	// end of the current window = k - 1 ;
 	// There for the first iteration i - k = arr[0] -> we remove this elemenet from the sum
 	// and we add arr[i] and i = k therefore we add the next element sliding the window by one unit 
 	for(int i = k; i < n ; i++){ // i indicates the end of the current window
 		curr -= arr[i-k] ; // remove the prev first element
 		curr += arr[i] ; // add the new last elemenet
 		// hence creating a slifind window
 		ans = max(ans , curr) ;
 	}
 	cout << ans << "\n" ;
 }


 void Q2(){
 	// Question : Given an array of size n of integres find wether there exist a subarray of size k with a given sum (say x)
 	int n , k , x ;
 	cin >> n >> k >> x ;
 	int arr[n] ;
 	for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
 	q2::bruteforce(arr , n , k , x) ;
 	q2::windowSliding(arr , n , k , x) ;

 }

 void q2::bruteforce(int arr[] , int n , int k , int x){
 	for(int i = 0 ; i < k ; i++){
 		int curr = 0 ;
 		for(int j = 0 ; j < k ; j++) curr += arr[i+j] ;
 		if(curr == x){
 			cout << "bf: True(q2)\n" ;
 			return ;
 		} 
 	}
 	cout << "bf: False(q2)\n" ;
 }


 void q2::windowSliding(int arr[] , int n ,int k , int x){
 	int curr = 0 ;
 	for(int i = 0 ; i < k ; i++) curr += arr[i] ;
 	for(int i = k; i < n ; i++){ 
 		curr -= arr[i-k] ; 
 		curr += arr[i] ; 
 		if(curr == x){
 			cout << "sw: True(q2)\n" ;
 			return ;
 		}
 	}
 	cout << "sw: False(q2)\n" ;
 }


void Q3(){
	// Question : Given an unsorted array of non-negative(imp) integers find if there is a subarray with given sum. 
	// Approach: 
	// Note : If the array contains negative integer values the window sliding technique wont work
	// Hashing works in O(n) time ans O(n) Space with negative and non-negative integers 

	// Therefore : if the array conatins non-negative intergers use Sliding Window 
	//			 : if the array contains negative integers use hashing
	int t ;
	cin >> t ;
	while(t--){
		int n , x ;
		cin >> n >> x ;
		int arr[n] ;
		for(int i = 0; i < n ; i++) cin >> arr[i] ;
		q3::bruteforce(arr , n , x) ;
		q3::windowSliding(arr , n , x) ;
	}

}

void q3::bruteforce(int arr[] , int n , int x){
	// This approach works regarless of wether the array contains negative or non-negatove integers unlike the sliding window solution that only works for non-negative values

	// TC: O(n^2)
	for(int i = 0 ; i< n ; i++){
		int sum = 0 ;
		for(int j= i ; j < n  ; j++){
			sum += arr[j] ;
			if(sum == x){
				cout << "bf: True(q3)\n" ;
				return ;
			} 
		}
	}
	cout << "bf: False(q3)\n" ;
}


void q3::windowSliding(int arr[] , int n , int x){
	// Note that this approach works only for non-negative ineteger arrays
	// TC: O(n) 
	// we keep on adding elements while the sumis lesser than the target 
	// we remove elements from the start if the sum becomes greater that the target
	int start , end ;
	start = 0 ;
	end = 0 ;
	int currSum = arr[0] ;
	for(end = 1; end < n ; end++){
		// clean the window
		while(currSum > x) currSum -= arr[start++] ;
		if(currSum == x){
			cout << "sw: True(q3)\n" ;
			return ;
		}
		currSum += arr[end] ;
	}
	if(currSum == x){
		cout << "sw: True(q3)\n" ;
		return ;
	}
	cout << "sf: False(q3)" ;
}


void nFibbonacci(int n , int pos){
	cout << "\n" << n << "-bonaci Series:\n" ;
	vector<int> arr ;
	for(int i = 0 ; i < n - 1 ; i++) arr.emplace_back(0) ;
	arr.emplace_back(1) ;
	arr.emplace_back(1) ;
	int curr = 2 ;
	for(int i = n ; i < pos ; i++){
		curr -= arr[i-n] ;
		arr.emplace_back(curr) ;
		curr += arr[i+1] ;
	}
	for(int i = 0 ; i < pos ; i++) 
		cout << arr[i] << ", " ;
}







