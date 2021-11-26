
#include<bits/stdc++.h> // import STL templates and containers
/*	using STL , you cn write shorted code that runs faster
 *	The perwritten code in STL error free and optimized
 *	STL makes advanced concepts easier : 
 *	1. vectors used in graph adjacency list
 *	2. pairs and sets are used for dijkstra algorithm in graph
 *	
 * */

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

// -------- Vectors --------------

void Vector(){
	vector<int> v ; // empty vector on integers 
	vector<char> c(10) ; // vector of char with 10 elements
	vector<string> s(10, "default") ; // vector of string with 10 elements all "default"
	cout << c[0] ;
	cout << endl ;
	cout << s[0] << endl ;
	v.push_back(10) ; // adding elemnts at the end of the vector
	v.emplace_back(11) ; // slightly faster than push_back
	cout << v[0] << " , " << v[1] << endl ;
	v.pop_back() ; // removes the last element
	cout << "size :" << v.size() << endl ;
	v.clear() ; // this deletes all the elements in the vector 
	cout << v.size() << endl ;
	
}


// ----------------- SORT ------------------------------
// This function can be used to sort am array or a vector or a string. The undelying sorting algorithm is called gcc_sort
// is a hybrid algorithm which is implemented in a very efficient way 
// it is a mix of 3 algorithm : quick sort , insertion sort , heap sort

void Sort(){
	// syntax : sort(pointer to the first element , pointer to the last element + 1) 
	// using vectors
	vector<int> v = {5,4,3,2,1} ;
	sort(v.begin() , v.end()) ;
	f(v.size()) cout << v[i] << " "  ;
	cout << endl ;
	// using arrays 
	int arr[5] = {10,9,8,7,6} ;
	int n = sizeof(arr) / sizeof(arr[0]) ;
	sort(arr , arr + n) ;
	f(n) cout << arr[i] << " " ;
	cout << endl ;
	cout << endl ;
	
}
// Pairs are importtant if we want to return two values from a function that are either of the same data type or different datatye
//

void Pair(){
	pair<int , string> hybd ;
	hybd = make_pair(69 , "is the best position") ;
	cout << hybd.first << " " << hybd.second << endl ;
	pair<string , char> foo ;
	foo = {"foo" , 'f'} ;
	cout << foo.first << " " << foo.second << endl ;
	// the main use case of a pair is however used in sorting 
	// p[0] = {1,2} p[1] = {5,2} p[2] = {8,1} p[3] = {1,0} p[4] = {3,4}
	// sorting the pairs will look like : 
	// [{1,0} {1,2} {3,4} {5,2} {8,1}]
	// Sorting is done on the basis of the first element and when two or more elements have the same first element then its sorted as per the second element
	pair<int , int> arr[5] = {
		{1,2} ,
		{5,2} ,
		{8,1} ,
		{1,0} ,
		{3,4}
	} ;
	for(auto x : arr){
		cout << x.first << " " << x.second << endl ;
	}
	cout << endl ;
}
void Run();
void printArray(int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	Vector() ;
	Sort() ;
	Pair() ;
	
	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


