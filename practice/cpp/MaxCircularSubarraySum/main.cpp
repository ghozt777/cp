
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii ;
typedef pair<int,int> pi;
typedef map<string , int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_bac
#define MP make_pair
#define f(n) for(int i = 0 ; i < n ; i++)
#define fr(itr, n) for(int itr = 0 ; itr < n ; itr++)

int bf(int[] , int) ;
int maxSum(int[] , int) ;
int maxSumInCircularSubarray(int[] , int) ;

void Run();


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	int arr[] = {5 , -2 , 3 , 4} ;
	int _max_bf = bf(arr , sizeof(arr) / sizeof(arr[0])) ;
	cout << "ans : " << _max_bf << "\n" ;
	int _max = maxSumInCircularSubarray(arr , sizeof(arr) / sizeof(arr[0])) ;
	cout << "Efficent ans: " << _max << "\n";
	return ;
}

// BRUTE FORCE APPROACH : O(n^2)

// the approach for the brute force soution is that we consider each element as the starting index and then iterate over the remaining elements to find the larget sum 

int bf(int arr[] , int n){
	int ans = INT_MIN ;
	for(int i = 0 ; i < n ; i++){ 
		int curr = 0 ;
		for(int j = 0 ; j < n ; j++){ 
			ans = max(ans , curr) ;
			curr += arr[(i+j)%n] ;
		}
	}
	return ans ;
}

// Efficient Solution : O(n)

// In this approach we instead of finding the max sum in the circular array we find the subrray with the minimum sum by inverting the array arr[i] = -arr[i] and then using kadens algorithm : max in inverted array = min in the original array . And we also keep track of the total sum of the array , now Our objective is to find the max subrray sum and this can be done by subtracting min subarray sum from the max subarray sum .
// Now since we inverted the array we need to add the min subarray sum to the total sum (min subarray sum is already negated) to get the right answer . 

// function that returns the max sum in a normal array using kadens algorithm
int maxSum(int arr[] , int  n){
	int ans = INT_MIN , curr = 0 ;
	for(int i = 0 ; i < n ; i++){
		curr += arr[i] ;
		ans = max(ans , curr) ;
		if(curr < 0) curr = 0 ;
	}
	return ans ;
}


int maxSumInCircularSubarray(int arr[] , int n){
	int sum = 0 ;
	int maxNormal = maxSum(arr , n) ; // ans for a normal array
	if(maxNormal < 0) return maxNormal ;// If max sum is negative then all the elements in the array are negative and this is the largest sum so we simply return it .
	for(int i = 0 ; i < n ; i++){
		sum += arr[i] ;
		arr[i] *= -1 ; // invert the array
	}
	int minSum = maxSum(arr , n) ; // ans for only circular array
	sum += minSum ;
	return max(sum , maxNormal) ; // circular array is composed of a normal array and a only circular array : comapare the results from thse array and return the largest one .
}


