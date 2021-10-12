#include<bits/stdc++.h>
using namespace std;

int* binarySearch(int[5][5]);

int main() {
	int m[5][5];
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin >>m[i][j];

	binarySearch(m); 
}

void binarySearch(int* m){
	int rStart = 0;
	int rEnd = 4;
	int mCol = 2;
	int idx[2];
	while(rStart < rEnd - 1){
		int mid = rStart + (rEnd - rStart) / 2;
		if(m[mid][mCol] == 1) {
			idx[0] = mid;
			idx[1] = mCol;
			return idx;
		}
		else if (m[mid][mCol] < 0) rStart = mid;
		else rEnd = mid;
	}
	for(int i = 0; i < 5 ; i++){
		if(m[rStart][i] == 1){
			idx[0] = rStart;
			idx[1] = i;
			return idx;
		}
	}

	for(int i = 0; i < 5 ; i++){
		if(m[rEnd][i] == 1){
			idx[0] = rEnd;
			idx[1] = i;
			return idx;
		}
	}
	return idx;
}