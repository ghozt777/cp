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

void util(string str , string p){
    if(str.empty()){
        cout << p << endl ;
        return ;
    }
    for (int i = 0; i < str.size(); i++)
    {
        // Remove first character from str and
        // add it to out
        util(str.substr(1), p + str[0]);
 
        // Rotate string in a way second character
        // moves to the beginning.
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    util(input , "") ;
}


void Run() {
    string input;
    cin >> input;
    printPermutations(input);
    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}