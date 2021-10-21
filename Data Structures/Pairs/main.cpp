
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

void Pair();


void Run();


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

    return 0;
}

void Run() {
	// run your code here
	Pair();

	return ;
}

void Pair() {
	// a pair is not a container
	// to make it a container use: 
	// vector<pair<int , int>> foo;
	// set<pair<int , int>> foo;
	// map<pair<int , int> , int> foo;
	// unordered_pair<pair<int , int> , int> foo < --- [X] this is not allowed  
	pi p = {1,2}; // simple pair its a defined data type
	pair<pair<int,int> , int> np = {{ 3 , 4 } , 69}; // nested pair
	pair<pi , pi> dnp = {{7 , 8} , {5 , 6}};// nested pair
	// to access elements inside a pair use .second and .first props
	cout << "\nprinting the elements in the pairs: ";
	cout << "\n☝️ first : " << p.first << "🤙 second : " << p.second;
	cout << "\nprinting elements in nested pairs: ";
	cout << "\n☝️ first : {" << np.first.first << " , " << np.first.second << "}" << "🤙 second : " << np.second;
	cout << "\n☝️ first : {" << dnp.first.first << " , " << dnp.first.second << "}"<< "🤙 second : {" << dnp.second.first << " , " << dnp.second.second << "}";



}


