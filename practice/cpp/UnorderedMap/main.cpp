// in unordered map serach insert and delete operations are O(1) on average , whereas for map it is log(n) for all of these operations
// Thus for fast search insert and delete operatons unorderedmap can be used to store (key,value) pairs
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
void distinctCount(int[] , int) ;
void printFrequency(int[] , int) ;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here

	// Sytax for unordered map :
	unordered_map<string , int> um ;
	um["ghozt"] = 7 ; // using [] this operator is know as a memener access operator
	// it returns an iterator pointing to the key value pair of the mentioned key
	// if a key is not present it inserts that key
	// Therefore , [] -> used for both insertion and accessing
	um.insert({ "position" , 69 }) ;
	um.insert({ "u a dumb fuck" , 1 }) ;
	// to iterate over the map a for each loop can be used
	for(pair<string , int> x : um)
		cout << "key: " << x.first << " || value: " << x.second << "\n" ;

	// find function take in a key and returns an iterator pointing to the pair if the key is present and returns end iteraor if the key is not present: 

	um.find("ghozt") != um.end() ? cout << "key is present -> key : " << um.find("ghozt")->first << " value: " << um.find("ghozt")->second << "\n"  : cout << "key ghozt not found\n";

	um.find("abc") != um.end() ? cout << "key is present -> key : " << um.find("abc")->first << " value: " << um.find("abc")->second << "\n" : cout << "key abc not found\n" ;

	int arr[] = {15,12,13,12,13,13,1} ;
	distinctCount(arr , sizeof(arr) / sizeof(arr[0])) ;
	int arr1[] = {50,50,10,40,10} ;
	printFrequency(arr1 , sizeof(arr1) / sizeof(arr1[0])) ;

	return ;
}


void distinctCount(int arr[] , int n){
	unordered_set<int> unique(arr , arr + n) ;
	cout <<"\n\nIn the array : " ;
	printArray(arr , n) ;
	cout << "\nNumber of unique elements = " << unique.size() << "\n" ; 
}

void printFrequency(int arr[] , int n){
	unordered_map<int , int> m ;
	for(int i = 0 ; i < n ; i++)
		m[arr[i]]++ ;
	// the above code is the shorthand expression of the below code: 
	// for(int i = 0 ; i < n ; i++){
	// 	if(m.find(arr[i]) != m.end()){
	// 		m.find(arr[i])->second++ ;
	// 	}
	// 	else m.insert({arr[i] , 1});
	// }
	cout <<"\n\nIn the array :" ;
	printArray(arr , n) ;
	cout << "\n" ;
	for(pair<int , int> x : m)
		cout << "value: " << x.first << " freq: " << x.second << "\n" ;

}


void printArray(int arr[] , int n){
	if(n==0){cout << "[]"; return ;}
	if(n==1){cout << "[" << arr[0] << "]"; return ;}
	cout << "[" << arr[0] <<", " ;
	for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
	cout << arr[n-1] << "]" ;
}


