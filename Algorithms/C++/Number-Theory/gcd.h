/*
	Theory : 
*/


// implementation : 

template<typename T> 
T gcd(T a , T b){
	if(a < b) return gcd(b , a) ;
	return b ? gcd(b,a%b) : a ; 
}
