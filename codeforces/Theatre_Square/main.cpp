
#include<bits/stdc++.h>

using namespace std;


int main(){

	// run your code here
	long long n , m , a;
	cin >> n >> m >> a;

	long long r =0, c =0;

	 if(n%a == 0) r = n/a;
	 if(n%a > 0) r = n/a + 1;
	 if(m%a == 0) c = m/a;
	 if(m%a > 0) c =  m/a + 1;

	 (r*c == 0 && (r > 0 || c > 0)) ? cout << 1 : cout << r*c ;

    return 0;
}




