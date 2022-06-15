template <typename T>
void swap(T & a , T & b){T temp = a ; a = b ; b = temp ;}

/*
	Theory : https://cp-algorithms.com/algebra/euclid-algorithm.html
*/


// implementation : 

template<typename T> 
T gcd(T a , T b){
	return b ? gcd(b,a%b) : a ; 
}

int gcd_itr (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

