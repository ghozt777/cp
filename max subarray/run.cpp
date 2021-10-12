#include <bits/stdc++.h>
using namespace std;

void maxSum(int[] , int);

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt" , "r" , stdin);
		freopen("output.txt" , "w" , stdout);
	#endif

	int size;
	cin >> size;
	int arr[size];
	for(int i = 0;i < size ; i++){
		cin >> arr[i];
	}
	maxSum(arr,size);

}

void maxSum(int *arr, int size){
	if(size == 1) {
		cout << arr[0];
		return ;
	}
	long maxSum = INT_MIN;
	long currSum = 0;
	for(int i = 0 ; i < size ; i++){
		currSum += arr[i];
		if(currSum > maxSum) maxSum = currSum;
		if(currSum < 0) currSum = 0;
	}
	cout << maxSum;
}
