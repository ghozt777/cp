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
Run();
return 0;
}

void increment(int & x){ ++x ; }

int * dynamic(){
    int * newInt = new int ;
    * newInt = 0 ;
    return newInt ; 
}



void Run() {

    // POINTERS : 

    /*
    int a = 10 ; // all the memmory addresses are kept in the symbol table
    cout << a << endl ;
    cout << "In the symbol table -> \nmemory address " << &a << " stores the value " << a << " assigned to variable \"a\"" << endl ;
    // the address is stored in hexadecimal : Eg : 0x16fa0393c 0x[...] represents hexadecimal number
    // creating a pointer : 
    int * ptr = &a ;
    (*ptr)++ ;
    cout << a << endl ;
    cout << "sizeof a int = " << sizeof(a) << endl ;
    cout << "sizeof a int pointer = " << sizeof(ptr) << endl ;
    char ch = 'a' ;
    char * chPtr = & ch ;
    cout << "sizeof a char = " << sizeof(ch) << endl ;
    cout << "sizeof a char pointer = " << sizeof(chPtr) << endl ;
    double d = 69.696969 ;
    double * dPtr = & d ;
    cout << "sizeof a double = " << sizeof(d) << endl ;
    cout << "sizeof a double pointer = " << sizeof(dPtr) << endl ;
    cout << "---- ponter arithmetics ------" << endl ;
    cout << "before incrementing an int pointer : " << ptr << endl ;
    ++ptr ;
    cout << "after incrementing an int pointer : " << ptr << endl ;   
    int arr[] = {1,2,3,4} ;
    int * arrPtr = arr ;
    for(int i = 0 ; i < 4 ; i++){
        cout << *arrPtr << " " ;
        ++arrPtr ;
    }
    
    int a = 1023 ;
    int * ptr = & a ;
    char * cPtr = (char *)ptr ;
    cout << * ptr << endl ; 
    cout << * cPtr << endl ; 
    
    int a = 65 ;
    int * ptr = & a ;
    char * cPtr = (char *) ptr ;
    cout << * ptr << endl ; 
    cout << *cPtr << endl ;   
    char str[] = "This is a test\n" ;
    char * pc = str ;
    cout << pc << endl ;

    
    int a = 10 ;
    int * ptr = & a ;
    char str[] = "🍕 🍔 🥨 🍩 \n" ;
    char * cPtr = str ;
    cout << ptr << endl ;
    cout << cPtr << endl ;
    
    char str[] = "AAAAAAAA" ;
    char * cPtr = str ;
    int * ptr = (int*) cPtr ;
    cout << * ptr << endl ;
    

    // REFERENCES : 

    int a = 10 ;
    int & b = a ;
    ++b ;
    cout << a << endl ;
    
    int a = 10 ;
    int & b = a  ;
    ++b ;
    int k = 69 ;
    b = k ;
    cout << a << endl ; 

    int a = 10 ;
    increment(a) ;
    cout << a << endl ;

    increment(a) ;
    increment(a) ;
    increment(a) ;

    cout << a << endl ;
    
    int * arr = new int[5]; 
    for(int i = 0 ; i < 5 ; i++) arr[i] = i + 1 ;
    for(int i = 0 ; i < 5 ; i++) cout << arr[i] << " " ;
    

    int * ptr = new int ;
    ptr[0] = 1 ;
    cout << ptr[0] ; 

     

    int * ptr = dynamic()  ;
    * ptr = 12 ;
    cout << *ptr << endl ;
    

    int * arr = new int[100] ;
    delete [] arr ;

    */

    

    return ; 
}







void printArray(int arr[] , int n){
if(n==0){cout << "[]"; return ;}
if(n==1){cout << "[" << arr[0] << "]"; return ;}
cout << "[" << arr[0] <<", " ;
for(int i = 1 ; i < n - 1 ; i++) cout << arr[i] << ", " ; 
cout << arr[n-1] << "]" ;
}