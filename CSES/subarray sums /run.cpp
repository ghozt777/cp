#include<bits/stdc++.h>
using namespace std;

void ans(int[] , int , int);

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt" , "r" , stdin);
		freopen("output.txt" , "w" , stdout);
	#endif

	int n , x;
	cin >> n >> x;
	int arr[n];
	for(int i=0;i<n;i++) 
		cin >> arr[i];
	ans(arr,n,x);
	return 0;
}

void ans(int *arr , int n , int x){
	int count = 0;
	for(int i = 0 ; i < n - 1; i++){
		for(int j = i + 1; j < n;j++){
			
		}
	}
	cout << count;
}