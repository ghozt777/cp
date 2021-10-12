#include<bits/stdc++.h>
using namespace std;

void distinct(int[], int);

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt" , "r" , stdin);
		freopen("output.txt" , "w" , stdout);
	#endif

	int size ;
	cin >> size;
	int arr[size];
	for(int i = 0;i < size ; i++)
		cin >> arr[i];
	distinct(arr,size);
}


void distinct(int *arr , int size){ 
	sort(arr , arr+size);
	int count = 1;
	for(int i = 1 ; i < size ; i++){
		if(arr[i]!=arr[i-1]) ++count;
	}
	cout << count;
	return ;
}