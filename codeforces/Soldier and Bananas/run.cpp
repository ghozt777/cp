#include<bits/stdc++.h>
using namespace std;
int main() {
	int  k , n ,w;
	cin >> k >> n >> w;
	int t = 0;
	for(int i = 1 ; i <= w ; i++)
		t += i;
	t *= k;
	t - n > 0 ? cout << t - n : cout << 0;
	return 0;
}