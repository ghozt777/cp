#include<bits/stdc++.h>
using namespace std ; 

int length(char arr[]){
	int c = 0 ;
	for(int i = 0; arr[i]; i++) c++ ;
	return c ;
}

bool checkPalindrome(char str[]) {
    // Write your code here
	int len = length(str) ;
	for(int i = 0 ; i < len/2; i++) if(str[i] != str[len - 1 - i]) return false ;
	return true;	
}


void reverseString(char arr[]){
	int len = length(arr) ;
	for(int i = 0 ; i < len/2 ; i++) swap(arr[i] , arr[len - 1 - i]) ;
}

void reverse(char arr[] , int start , int end){
	while(start < end) swap(arr[start++] , arr[end--]) ;
}

void Run () {
	char ip1[100] ;
	char ip2[100] ;
	char str[100] ;

	// for char arrays we dont need to run a loop we simply cin the string and it auomatically gets stored in the array
	/*
	cout << "Enter a name: " ;
	cin >> str ;
	for(int i = 0 ; str[i] ; i++) cout << str[i] ;
	cout << endl ;
	// another way to print the string : 
	cout << str ; // for normal arrays it prints the memory address but for a character array is print the entiter string
	cout << endl ;
	// Hence cin and cout both behave a bit differrntly for character arrays
	// For cout it prints the contents of the array until the null character is encountered
	cout << "Length of the string: " << length(str) ;
	cout << endl ;
	cout << "Enter a string: " ;
	cin >> str ;
	checkPalindrome(str) ? cout << "Its a pallindrome " << endl : cout << "Its Not a palindrome" << endl;
	// to take string that contain whitespaces use cin.getline() function
	char message[100] ;
	// this function takes 3 arguments : string_name , length , optional_arg -> delimiter
	cout << "Enter a message: " << endl ;
	cin.getline(message , 100) ; // reads till newline or till 99 characters
	cout << message ; 
	cout << "Enter another Message: " << endl ;
	char anotherMessage[100] ;
	cin.getline(anotherMessage,4) ;
	cout << anotherMessage << endl ;
	// make sure that the second argument in the geline function i.e. the lenght of the string at max is equal to the size of the array and it never should exceed the size of the array
	// the third argument in the getline function is a delimiter that is a character and when this character is encountered the getline function stops taking in characters
	// default value of the delimiter argument is '\n'
	char secret[100] ;
	cin.getline(secret , 100 , 'x') ; // stops reading input once it encounters character 'x'
	cout << secret << endl ;
	char str1[100] ;
	cout << "enter a string:  " ;
	cin.getline(str1 , 100) ;
	reverseString(str1) ;
	cout << "The reversed string is : " << str1 << endl ;
	to get string length
	cout << "Enter a string: "  << endl ;
	cin.getline(ip , 100) ;
	cout << "The length of the string is : " << strlen(ip) << endl ;
	// to comapare two strings use strcmp 
	cout << "enter two strings: " << endl ;
	cin >> ip1 >> ip2 ;
	strcmp(ip1 , ip2) == 0 ? cout << "They are the same" << endl 
		: cout << "They are different" << endl ;  
	// strcpy to copy a string 
	cout << "Enter a string : " ;
	cin >> ip1 ;
	strcpy(ip2 , ip1) ;
	strcmp(ip1 , ip2) == 0 ? cout << "String copied successfully" << endl :	
		cout << "Error during copying string" << endl ;
	// to copy a part from the original string
	cout << "Enter a string : " ;
	cin >> ip1 ;
	cout << "Enter a number lesser than " << strlen(ip1) ;
	int n ;
	cin >> n ;
	strncpy(ip2 , ip1 , n) ;
	cout << "The substring is " << ip2 << endl ;
	*/
	cin.getline(str , 100) ;
	// int n = strlen(str) ;
	// reverse(str , 0 , n - 1) ;
	// int i = 0 ;
	// int j = 0 ;
	// while(str[i]){
	// 	while(str[i] && str[i] != ' ') i++ ;
	// 	reverse(str , j , i - 1) ;
	// 	while(str[i] && str[i] == ' ') i++ ;
	// 	j = i ;
	// }
	// cout << str << endl ;
	int i , j ;
	i = j = strlen(str) - 1;
	char a[100] ;
	int c = 0 ;
	while(i >= 0){
		while(i >= 0 && str[i] != ' ') --i  ;
		for(int k = i + 1 ; k <= j ; k++ ) a[c++] = str[k] ;
		a[c++] = ' ' ;
		while(i >= 0 && str[i] == ' ') --i ;
		j = i ;
	}
	// a[strlen(str)] = '/0' ;
	cout << a << endl ;
}


int main() {
	Run() ;
	return 0 ;
}