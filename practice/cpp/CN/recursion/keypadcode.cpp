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

int keypadUtil(string nums , string op[]){
    
    int curr = nums[0] - '0' ;
    cout << "curr " << curr << endl ;
    if(nums.length() <= 1){
        switch(curr){
            case 0 : 
            op[0] = "" ;
            return 1 ;

            case 1 : 
            op[0] = "" ;
            return 1 ;

            case 2 : 
            op[0] = "a" ;
            op[1] = "b" ;
            op[2] = "c" ;
            return 3 ;

            case 3 : 
            op[0] = "d" ;
            op[1] = "e" ;
            op[2] = "f" ;
            return 3 ;

            case 4 :
            op[0] = "g" ;
            op[1] = "h" ;
            op[2] = "i" ;
            return 3 ;

            case 5 : 
            op[0] = "j" ;
            op[1] = "k" ;
            op[2] = "l" ;
            return 3 ;

            case 6 : 
            op[0] = "m" ;
            op[1] = "n" ;
            op[2] = "o" ;
            return 3 ;

            case 7 : 
            op[0] = "p" ;
            op[1] = "q" ;
            op[2] = "r" ;
            op[3] = "s" ;
            return 4 ;

            case 8 : 
            op[0] = "t" ;
            op[1] = "u" ;
            op[2] = "v" ;
            return 3 ;

            case 9 :
            op[0] = "w" ;
            op[1] = "x" ;
            op[2] = "y" ;
            op[3] = "z" ;
            return 4 ;
        }
    }
        int count = keypadUtil(nums.substr(1) , op) ;
        string * temp = new string[count] ;
        for(int i = 0 ; i < count ; i++) temp[i] = op[i] ;
        switch(curr){
            case 0 :
            for(int i = 0 ; i < count ; i++) op[i + count] = op[i] ; 
            return 2 * count ;

            case 1 : 
            for(int i = 0 ; i < count ; i++) op[i + count] = op[i] ; 
            return 2 * count ;

            case 2 : 
            for(int i = 0 ; i < count ; i++) op[i] = "a" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "b" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "c" + temp[i] ;
            return 3 * count ;

            case 3 : 
            for(int i = 0 ; i < count ; i++) op[i] = "d" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "e" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "f" + temp[i] ;
            return 3 * count ;

            case 4 :
            for(int i = 0 ; i < count ; i++) op[i] = "g" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "h" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "i" + temp[i] ;
            return 3 * count ;

            case 5 : 
            for(int i = 0 ; i < count ; i++) op[i] = "j" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "k" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "l" + temp[i] ;
            return 3 * count ;

            case 6 : 
           for(int i = 0 ; i < count ; i++) op[i] = "m" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "n" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "o" + temp[i] ;
            return 3 * count ;

            case 7 : 
            for(int i = 0 ; i < count ; i++) op[i] = "p" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "q" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "r" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[3 * count + i] = "s" + temp[i] ;
            return 4 * count ;

            case 8 : 
            for(int i = 0 ; i < count ; i++) op[i] = "t" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "u" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "v" + temp[i] ;
            return 3 * count ;

            case 9 :
            for(int i = 0 ; i < count ; i++) op[i] = "w" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[count + i] = "x" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[2 * count + i] = "y" + temp[i] ;
            for(int i = 0 ; i < count ; i++) op[3 * count + i] = "z" + temp[i] ;
            return 4 * count ;
        }
    return 0 ;
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
   return keypadUtil(to_string(num) , output) ;
}

int main(){

ios::sync_with_stdio(0);
cin.tie(0);
Run();
    return 0;
}

void Run() {
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }

    return ;
}







void printArray(int arr[] , int n){
    if(n==0){cout << "[]"; return ;}
    if(n==1){cout << "[" << arr[0] << "]"; return ;}
    cout << "[" << arr[0] <<", " ;
    for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
    cout << arr[n-1] << "]" ;
}