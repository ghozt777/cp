#include<bits/stdc++.h>
using namespace std ;

inline int test(int , int) ;


string 🍕(int , int) ; // this is function decleration 
//     [  ..   .. ]
// 		   ☝️
// the list of the arguments is known as the decleration list
/*
	-----------------------------------------------------------------
	|							NOTES								|
	-----------------------------------------------------------------

The prototype is the declaration of the function and thus describes only the formal

interface of that function. This means you can omit parameter names from the proto-
type, whereas compiling a function definition will produce machine code.

A function declaration can be omitted only if the function is defined within the same
source file immediately before it is called.

the fact that copying larger objects is difficult can be a major disadvantage,
and for this reason vectors are passed by reference to their starting address.

Inline Functions : The compiler inserts the code of an inline function at the address where the function is
called and thus avoids jumping to a sub-routine. The definition of an inline function is
introduced by the inline keyword in the function header.

Inline vs Macros: Inline functions are an alternative to macros with parameters. When a macro is called,
the preprocessor simply replaces a block of text. In contrast, an inline function
behaves like a normal function, although the program flow is not interrupted by the
function branching. The compiler performs a type check, for example.

Default Args : if you define a default argument for a parameter, all following parameters must
have default arguments

Function Signature and Overloading: A function signature comprises the number and type of parameters. When a function is
called, the compiler compares the arguments to the signature of the overloaded functions
and simply calls the appropriate function.

Difference in Reference variable and pointer variable 
A reference is same object, just with a different name and reference must refer to an object. Since references can’t be NULL, they are safer to use.
 

A pointer can be re-assigned while reference cannot, and must be assigned at initialization only. 
 
Pointer can be assigned NULL directly, whereas reference cannot.
Pointers can iterate over an array, we can use increment/decrement operators to go to the next/previous item that a pointer is pointing to. 
 
A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
A pointer to a class/struct uses ‘->'(arrow operator) to access it’s members whereas a reference uses a ‘.'(dot operator)
A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.
 




*/


void _swap(int& , int&) ; // function that takes ref passed args  

int main(){
	cout << 🍕(4,12) ;
	int x1 = test(1,2) ;
	int x2 = test(1,2) ;
	cout << "x1 : " << x1 << " x2: " << x2 << "\n" ;
	int a = 10 ;
	int b = 20 ;
	cout << "OG: " << "a :" << a << " b: " << b <<"\n" ;
	_swap(a,b) ;
	cout << "Swaped: " << "a :" << a << " b: " << b <<"\n" ;
	return 0 ;
}

string 🍕(int arg1 , int arg2) { // function definition
	string message = to_string(arg1) + " 🍕 + " + to_string(arg2) + " 🍕 = " + to_string(arg1 + arg2) + " 🍕 : Too much Pizza !\n" ; 
	return message ;
}

inline int test(int a , int b){
	int x = a ;
	x += b ;
	return x ;
}

void _swap(int &a , int &b){
	int t = a ;
	a = b ;
	b = t ;
	return ;
}
