// unordered sets in STL is implementede using hashing 
// ordered sets in STL is implemented using Red Black Trees


// TC : insert , erase , find , count -> O(1) on average

#include<bits/stdc++.h>

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

	unordered_set<int> us ;

	us.insert(1) ; 
	us.insert(-1) ;
	us.insert(2) ;
	us.insert(9) ;
	us.insert(5) ;
	// the elements are not stored in any sortof an order 
	// the order varies from compiler to compiler

	for(unordered_set<int>::iterator x = us.begin() ; x != us.end() ; x++)
		cout << *x << " " ;
	cout << "\nSize: " << us.size() << "\n" ;

	// find function returns an iterator to the found element and if the element is not found then it returns the end iterator

	int a , b , c , d ;
	a= 10 ;
	b = -1 ;
	c = 5 ;
	d = 0 ;
	us.find(a) == us.end() ? cout << a << " is not present in the set\n" : cout << *us.find(a) << " is present in the set\n" ; 
	us.find(b) == us.end() ? cout << b << " is not present in the set\n" : cout << *us.find(b) << " is present in the set\n" ; 
	us.find(c) == us.end() ? cout << c << " is not present in the set\n" : cout << *us.find(c) << " is present in the set\n" ; 
	us.find(d) == us.end() ? cout << d << " is not present in the set\n" : cout << *us.find(d) << " is present in the set\n" ; 

	// instead of using the find function one can use the count function that returns 1 if the element is present and 0 if it is not present

	// Eg:

	us.count(9) == 1 ? cout << "9 is present in the set\n" : cout << "9 is not present in the set\n" ;

	us.count(-9) == 1 ? cout << "-9 is present in the set\n" : cout << "-9 is not present in the set\n" ;
	cout << "us.count(-9) = " << us.count(-9) << "\n" ;

	// The reason why its either 1 or 0 is that like set there can't be anu duplicate elements in it .

	// This property can be applied to find the number of duplicate elements in an array 

	// erase function is used to remove an element

	us.erase(-1) ;
	unordered_set<int>::iterator x  = us.begin();
	us.erase(x) ;

	for(unordered_set<int>::iterator x = us.begin() ; x != us.end() ; x++)
		cout << *x << " " ;	


	us.clear() ;
	cout << "\nCleared Size: " << us.size() << "\n" ;

	return ;
}







void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


